/* --------------------------------------------------------------------------
Disciplina  : Lógica de Programação, turma IB, 2026S1
Nome        : Eduardo Abreu
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/2552
Data        : 23/06/2026
Objetivo    : Descobrir o número de pão de queijos em uma matriz dada a lógica do jogo "Mine Sweeper"
Aprendizado : Lógica de programação, uso de loops, condições e matrizes.
Pergunta de segunda ordem: Por que a lógica de força bruta é mais eficaz para esse tamanho?
-------------------------------------------------------------------------- */
#include <stdio.h>

int main()
{
    int N, M;
    
    while (scanf("%d %d", &N, &M) != EOF) 
    {
        int tab[100][100];
        
        for (int i = 0; i < N; i++) 
        {
            for (int j = 0; j < M; j++) 
            {
                scanf("%d", &tab[i][j]);
            }
        }

        for (int i = 0; i < N; i++) 
        {
            for (int j = 0; j < M; j++) 
            {
                if (tab[i][j] == 1) 
                {
                    printf("9");
                } 
                else
                {
                    int counter = 0;

                    if ((i > 0) && (tab[i - 1][j] == 1))
                    {
                        counter++;
                    }
                    if ((i < N - 1) && (tab[i + 1][j] == 1))
                    {
                        counter++;
                    }
                    if ((j > 0) && (tab[i][j - 1] == 1))
                    {
                        counter++;
                    }
                    if ((j < M - 1) && (tab[i][j + 1] == 1))
                    {
                        counter++; 
                    }
                    
                    printf("%d", counter);
                }
            }
            
            printf("\n");
        }
    }
    
    return 0;
}
