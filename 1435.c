/* --------------------------------------------------------------------------
Disciplina  : Lógica de Programação, turma IB, 2026S1
Nome        : Eduardo Abreu
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1435
Data        : 23/06/2026
Objetivo    : Imprimir uma matriz dado seu tamanho e seguindo as condições.
Aprendizado : Lógica de programação, uso de loops, condições e matrizes.
Pergunta de segunda ordem: Por que o cálculo das distância mínima resolve o problema?
-------------------------------------------------------------------------- */
#include <stdio.h>

int minimo(int a, int b) 
{
    return (a < b) ? a : b;
}
 
int main() 
{
    int N;
    
    while (scanf("%d", &N) == 1)
    {
        if (N == 0)
        {
            break;
        }
        
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                int dist_esq = j;
                int dist_sup = i;
                int dist_dir = (N - 1) - j;
                int dist_inf = (N - 1) - i;
        
                int min = minimo(minimo(dist_esq, dist_dir), minimo(dist_sup, dist_inf));
        
                int valor = min + 1;
        
                if (j == 0) 
                {
                    printf("%3d", valor);
                } 
                else 
                {
                    printf(" %3d", valor);
                }
            }
          
            printf("\n");
        }
      
        printf("\n");
    }
    return 0;
}
