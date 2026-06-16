/* --------------------------------------------------------------------------
Disciplina  : Lógica de Programação, turma IB, 2026S1
Nome        : Eduardo Abreu
Linguagem   : C
Problema    : Jogo de sudoku
Objetivo    : Resolver o Sudoku
Aprendizado : Lógica de programação, uso de loops, condições, funções, structs, linguagem C
-------------------------------------------------------------------------- */
#define MAX 257
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

// Estruturas do código
typedef struct Config
{
    int N;
    int mode;
    int pmode;
    int input;
    int generic;
    int solve;
} Config;

// Protótipos das funções
void playGame(int **tab, int N, int M);
bool ismovValid(int **tab, int i, int j, int num, int N, int M);
bool win(int **tab, int N, int M);
bool solveSudoku(int **tab, int N, int M);
int solveSudokuComplete(int **tab, int N, int M, int *counter);
bool solveSudokuGeneric(int **tab,int N, int M, int count, int *V);
int solveSudokuCompleteGeneric(int **tab, int N, int M, int count, int *V, int *counter);
int ValidGeneric(int **tab, int N, int *V);
void printTabGeneric(int **tab, int N, int M, int *V);
int loadfile(int **tab, int N, int input);
void printTab(int **tab, int N, int M);
Config lobby(void);
void ClearBuffer(void);

// Função principal do código
int main(void)
{
    Config game = lobby();
    int M = (game.N == 4) ? 2 : (game.N == 9) ? 3 : 4;

    int **tab = (int **) malloc(game.N * sizeof(int *));
    for (int i = 0; i < game.N; i++)
    {
        tab[i] = (int *) malloc(game.N * sizeof(int));
    }

    loadfile(tab, game.N, game.input);
    printf("Loading board for size %d\n", game.N);

    if (game.pmode == 1)
    {
        // Sudoku com input genérico mostrando todas as soluções
        if(game.generic == 0 && game.solve == 0)
        {
            int *V = (int *) malloc(MAX * sizeof(int));
            int count = ValidGeneric(tab, game.N, V);
            int counter = 0;
            
            printTabGeneric(tab, game.N, M, V);
            printf("Processing\n");
            
            solveSudokuCompleteGeneric(tab, game.N, M, count, V, &counter);
            printf("Completed, with a total of %d solutions\n", counter);

            free(V);
            V = NULL;
        }
        // Sudoku com input padrão mostrando todas as soluções
        else if(game.solve == 0 && game.generic == 1)
        {
            int counter = 0; 
            printTab(tab, game.N, M);
            printf("Processing all solutions\n");
            
            solveSudokuComplete(tab, game.N, M, &counter);
            printf("Completed, with a total of %d solutions\n", counter);
        }
        // Sudoku padrão mostrando uma solução
        else if (game.solve == 1 && game.generic == 1)
        {
            printTab(tab, game.N, M);
            printf("Processing\n");
            
            if(solveSudoku(tab, game.N, M))
            {
                printTab(tab, game.N, M);
                printf("Solution found\n");
            }
            else
            {
                printf("No solution exists\n");
            }
        }
        // Sudoku com input genérico mostrando uma solução
        else if (game.solve == 1 && game.generic == 0)
        {
            int *V = (int *) malloc(MAX * sizeof(int));
            int count = ValidGeneric(tab, game.N, V);
            
            printTabGeneric(tab, game.N, M, V);
            printf("Processing\n");
            
            if(solveSudokuGeneric(tab, game.N, M, count, V))
            {
                printTabGeneric(tab, game.N, M, V);
                printf("Solution found\n");
            }
            else
            {
                printf("No solutions exist\n");
            }
            
            free(V);
            V = NULL;
        }
    }
    else
    {
        printTab(tab, game.N, M);
        printf("Good luck!\n");
        
        playGame(tab, game.N, M);
    }

    for (int i = 0; i < game.N; i++)
    {
        free(tab[i]);
    }
    free(tab);

    return 0;
}


// Valida a jogada
bool ismovValid(int **tab, int i, int j, int num, int N, int M)
{
    for (int y = 0; y < N; y++)
    {
        if ((num == tab[i][y]) && (y != j))
        {
            return false;
        }
    }

    for (int x = 0; x < N; x++)
    {
        if ((num == tab[x][j]) && (x != i))
        {
            return false;
        }
    }

    int bgi = (i / M) * M;
    int bgj = (j / M) * M;

    for (int x = bgi; x < bgi + M; x++)
    {
        for (int y = bgj; y < bgj + M; y++)
        {
            if ((tab[x][y] == num) && !(y == j && x == i))
            {
                return false;
            }
        }
    }

    return true;
}

// Checa se o usuário ganhou o jogo
bool win(int **tab, int N, int M)
{
    int i, j;

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            int V = tab[i][j];

            if (V == 0)
            {
                return false;
            }

            if (!ismovValid(tab, i, j, V, N, M))
            {
                return false;
            }
        }
    }

    return true;
}

// Carrega os tabuleiros dispostos nos arquivos de input
int loadfile(int **tab, int N, int input)
{
    FILE *file;
    
    switch (input) {
        case 1:
            file = fopen("input1.txt", "r");
            break;
        case 2:
            file = fopen("input2.txt", "r");
            break;
        case 3:
            file = fopen("input3.txt", "r");
            break;
        case 4:
            file = fopen("input4.txt", "r");
            break;
        default:
            printf("Invalid input choice!\n");
            return 1; 
    }

    // Verifica se o arquivo foi encontrado e aberto com sucesso
    if (file == NULL) {
        printf("Erro: Nao foi possivel abrir o arquivo input2.txt\n");
        return 1; 
    }

    char temp[10];

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            fscanf(file, "%s", temp);
            
            if ((temp[0] >= '0' && temp[0] <= '9') || temp[0] == '-') {
                tab[i][j] = atoi(temp);
            }
            else 
            {
                tab[i][j] = -(int)temp[0];
            }
        }
    }
  
    fclose(file);

    return 0;
}

// Permite que o usuário jogue o sudoku
void playGame(int **tab, int N, int M)
{
    int i, j, num;

    while (1)
    {
        printf("Enter the value: (Row, Column, Value)\n");

        if (scanf("%d %d %d", &i, &j, &num) != 3)
        {
            int c;

            printf("Invalid value, try again\n");

            while ((c = getchar()) != '\n' && c != EOF);

            continue;
        }

        if (i < 0 || i >= N || j < 0 || j >= N)
        {
            printf("Invalid position\n");
            continue;
        }

        if ((tab[i][j] == 0) && (ismovValid(tab, i, j, num, N, M)))
        {
            tab[i][j] = num;
            printTab(tab, N, M);
        }
        else
        {
            printf("That number cannot be placed there! Try again\n");
            continue;
        }

        if (win(tab, N, M))
        {
            printf("Congratulations, you won!");
            break;
        }
    }
}

// Resolvedor por código recursivo
bool solveSudoku(int **tab, int N, int M)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (tab[i][j] == 0)
            {
                for (int num = 1; num <= N; num++)
                {
                    if (ismovValid(tab, i, j, num, N, M))
                    {
                        tab[i][j] = num;

                        if (solveSudoku(tab, N, M))
                        {
                            return true;
                        }

                        tab[i][j] = 0;
                    }
                }

                return false;
            }
        }
    }

    return true;
}

// Resolvedor exibindo todos os casos de resposta possíveis
int solveSudokuComplete(int **tab, int N, int M, int *counter)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (tab[i][j] == 0)
            {
                for (int num = 1; num <= N; num++)
                {
                    if (ismovValid(tab, i, j, num, N, M))
                    {
                        tab[i][j] = num;

                        solveSudokuComplete(tab, N, M, counter);
                      
                        tab[i][j] = 0;
                    }
                }

                return 1;
            }
        }
    }

    (*counter)++;
    printTab(tab, N, M);
    printf("%d", *counter);
    return 0;
}

// Resolvedor usando quaisquer valores de entrada genéricos
bool solveSudokuGeneric(int **tab, int N, int M, int count, int *V)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (tab[i][j] == 0)
            {
                for (int num = 1; num <= count; num++)
                {
                    if (ismovValid(tab, i, j, num, N, M))
                    {
                        tab[i][j] = num;

                        if (solveSudokuGeneric(tab, N, M, count, V))
                        {
                            return true;
                        }
                      
                        tab[i][j] = 0;
                    }
                }

                return false;
            }
        }
    }

    return true;
}

// Resolvedor exibindo todos os casos de resposta possíveis e usando quaisquer valores de entrada genéricos
int solveSudokuCompleteGeneric(int **tab, int N, int M, int count, int *V, int *counter)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (tab[i][j] == 0)
            {
                for (int num = 1; num <= count; num++)
                {
                    if (ismovValid(tab, i, j, num, N, M))
                    {
                        tab[i][j] = num;

                        solveSudokuCompleteGeneric(tab, N, M, count, V, counter);
                      
                        tab[i][j] = 0;
                    }
                }

                return 1;
            }
        }
    }

    (*counter)++;
    printTabGeneric(tab, N, M, V);
    printf("%d", *counter);
    return 0;
}

// Verifica e converte os valores de entrada
int ValidGeneric(int **tab, int N, int *V)
{
    int lsup = 1;
    int value = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if(tab[i][j] == 0)
            {
                continue;
            }

            int flag = 0;
            for(int x = 0; x < MAX; x++)
            {
                if (tab[i][j] == V[x])
                {   
                    flag = 1;
                    value = x;
                    break;
                }
            }
            if (flag == 0)
            {
                if (lsup < MAX) 
                {
                    V[lsup] = tab[i][j];
                    value = lsup; 
                    lsup++;            
                }

            }

            tab[i][j] = value;
        }
    }

    return (lsup - 1);
}

// Imprime o tabuleiro no console usando os valores genéricos
void printTabGeneric(int **tab, int N, int M, int *V)
{

    printf("\n");
    printf("     ");

    for (int j = 0; j < N; j++)
    {
        if (j > 0 && j % M == 0)
        {
            printf("  ");
        }

        printf("%2d ", j);
    }

    printf("\n");

    for (int i = 0; i < N; i++)
    {
        if (i > 0 && i % M == 0)
        {
            printf("\n     ");

            for (int j = 0; j < N; j++)
            {
                printf("---");

                if ((j + 1) % M == 0 && j != N - 1)
                {
                    printf("+");
                }
            }

            printf("\n");
        }

        printf("%2d | ", i);

        for (int j = 0; j < N; j++)
        {
            if (tab[i][j] == 0)
            {
                printf(" . ");
            }
            else
            {
                int original_value = V[tab[i][j]];

                if (original_value < 0) 
                {
                    printf(" %c ", -original_value);
                } 
                else 
                {
                printf("%2d ", original_value);
                }
            }

            if ((j + 1) % M == 0 && j != N - 1)
            {
                printf("| ");
            }
        }

        printf("\n");
    }

    printf("\n");
}

// Imprime o tabuleiro no console
void printTab(int **tab, int N, int M)
{
    printf("\n");
    printf("     ");

    for (int j = 0; j < N; j++)
    {
        if (j > 0 && j % M == 0)
        {
            printf("  ");
        }

        printf("%2d ", j);
    }

    printf("\n");

    for (int i = 0; i < N; i++)
    {
        if (i > 0 && i % M == 0)
        {
            printf("\n     ");

            for (int j = 0; j < N; j++)
            {
                printf("---");

                if ((j + 1) % M == 0 && j != N - 1)
                {
                    printf("+");
                }
            }

            printf("\n");
        }

        printf("%2d | ", i);

        for (int j = 0; j < N; j++)
        {
            if (tab[i][j] == 0)
            {
                printf(" . ");
            }
            else
            {
                printf("%2d ", tab[i][j]);
            }

            if ((j + 1) % M == 0 && j != N - 1)
            {
                printf("| ");
            }
        }

        printf("\n");
    }

    printf("\n");
}


// Configurações do jogo
Config lobby(void)
{
    Config Lconfig;

    enum
    {
        SIZE,
        PLAYER,
        INPUT,
        DONE
    } state = SIZE;

    while (state != DONE)
    {
        if (state == SIZE)
        {
            printf("========================================\n");
            printf("                SUDOKU                  \n");
            printf("========================================\n");

            printf("Choose the sudoku size:\n");
            printf("[4] Mini Sudoku (4x4)\n");
            printf("[9] Traditional Sudoku (9x9)\n");
            printf("[16] Giant Sudoku (16x16)\n");

            scanf("%d", &Lconfig.N);

            if (Lconfig.N == 4 || Lconfig.N == 9 || Lconfig.N == 16)
            {
                if (Lconfig.N == 16)
                {
                    char anw;
                    printf("This is a challenge. Continue? (y/n)\n");
                    scanf(" %c", &anw);

                    ClearBuffer();

                    if (anw == 'n' || anw == 'N')
                    {
                        state = SIZE;
                        continue;
                    }
                }

                state = INPUT;
            }
            else
            {
                printf("Invalid size!\n");
                ClearBuffer();
            }
        }
        else if (state == INPUT)
        {
            printf("========================================\n");
            printf("                 INPUT                  \n");
            printf("========================================\n");

            printf("Choose the input\n");
            printf("input1.txt (1)\n");
            printf("input2.txt (2)\n");
            printf("input3.txt (3)\n");
            printf("input4.txt (4)\n");
            scanf("%d", &Lconfig.input);

            if(Lconfig.input == 1 || Lconfig.input == 2 || Lconfig.input == 3 || Lconfig.input == 4)
            {
                printf("========================================\n");
                printf("                 INPUT                  \n");
                printf("========================================\n");

                printf("Choose the input mode\n");
                printf("Random input\"generic\" (0)\n");
                printf("1 to N\"standard\" (1)\n");
                scanf("%d", &Lconfig.generic);

                state = PLAYER;
            }
            else
            {
                printf("Invalid input!\n");
                ClearBuffer();
            }
        }
        else if (state == PLAYER)
        {
            printf("========================================\n");
            printf("                 PLAYER                 \n");
            printf("========================================\n");
          
            printf("Human Mode (0)\n");
            printf("AI Mode (1)\n");
          
            scanf("%d", &Lconfig.pmode);

            if (Lconfig.pmode == 0 || Lconfig.pmode == 1)
            {
                if(Lconfig.pmode == 1)
                {
                    printf("========================================\n");
                    printf("                SUDOKU                  \n");
                    printf("========================================\n");

                    printf("Choose the sudoku resolution:\n");
                    printf("Sudoku all solutions (0)\n");
                    printf("Sudoku unique solution (1)\n");
                    scanf("%d", &Lconfig.solve);

                    if(Lconfig.solve == 0 || Lconfig.solve == 1)
                    {
                        state = DONE;
                    }
                    else
                    {
                        printf("Invalid resolution mode!\n");
                        ClearBuffer();
                    }
                }
            }    
            else
            {
                printf("Invalid player mode!\n");
                ClearBuffer();
            }
        }
    }

    return Lconfig;
}

void ClearBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
