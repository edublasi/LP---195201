/* --------------------------------------------------------------------------
Disciplina  : Lógica de Programação, turma IB, 2026S1
Nome        : Eduardo Abreu
Linguagem   : C
Problema    : Jogo de sudoku
Objetivo    : Resolver o Sudoku
Aprendizado : Lógica de programação, uso de loops, condições, funções, structs, linguagem C
-------------------------------------------------------------------------- */
#define MAX 81
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// Estruturas do código
typedef struct Config
{
    int N;
    int mode;
    int pmode;
} Config;

// Prototipos das funções
void playGame(int **tab, int N, int M);
bool ismovValid(int **tab, int i, int j, int num, int N, int M);
bool win(int **tab, int N, int M);
bool solveSudoku(int **tab, int N, int M);
int solveSudokuComplete(int **tab, int N, int M)
void printTab(int **tab, int N, int M);
Config lobby(void);
int loadfile(int **tab, int N);

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

    loadfile(tab, game.N);
    printf("Loading board for size %d\n", game.N);

    printTab(tab, game.N, M);

    if (game.pmode == 1)
    {
        printf("Processing\n");

        if (solveSudoku(tab, game.N, M))
        {
            printTab(tab, game.N, M);
            printf("Completed\n");
        }
        else
        {
            printf("The AI could not find a solution");
        }
    }
    else
    {
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
int solveSudokuComplete(int **tab, int N, int M)
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

                        solveSudoku(tab, N, M);
                      
                        tab[i][j] = 0;
                    }
                }

                return 1;
            }
        }
    }

    printTab(tab, N, M);
}

// Verifica os valores de entrada
void valValid(int **tab, int N)
{
    int V[MAX] = {0};
    int lsup = 1;
    V[0] = tab[0][0];

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int flag = 0;
            for(int x = 0; x < MAX; x++)
            {
                if (tab[i][j] == V[x])
                {   
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
            {
                if (lsup < MAX) 
                {
                    V[lsup] = tab[i][j];
                    lsup++;              
                }
            }
        }
    }
}

void Converter(int **tab, int V[MAX], int N)
{
    
}

// Carrega os tabuleiros dispostos nos arquivos de input
int loadfile(int **tab, int N)
{
    FILE *file = fopen("input2.txt", "r");

    // Verifica se o arquivo foi encontrado e aberto com sucesso
    if (file == NULL) {
        printf("Erro: Nao foi possivel abrir o arquivo input2.txt\n");
        return 1; 
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            fscanf(file, "%d", &tab[i][j]);
        }
    }
  
    fclose(file);

    return 0;
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
                    int c;
                    printf("This is a challenge. Continue? (y/n)\n");
                    scanf(" %c", &anw);

                    while ((c = getchar()) != '\n' && c != EOF);

                    if (anw == 'n' || anw == 'N')
                    {
                        state = SIZE;
                        continue;
                    }
                }

                state = PLAYER;
            }
            else
            {
                printf("Invalid size!\n");
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
                state = DONE;
            }
            else
            {
                printf("Invalid player mode!\n");
            }
        }
    }

    return Lconfig;
}
