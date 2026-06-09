
/* --------------------------------------------------------------------------
Disciplina  : Lógica de Programação, turma IB, 2026S1
Nome        : Eduardo Abreu
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1383
Data        : 09/06/2026
Objetivo    : Verificar se uma matriz é uma solução válida de sudoku.
Aprendizado : Lógica de programação, uso de loops, funções, algebra e condições.
Pergunta de segunda ordem: Como a divisão e multiplicação por 3 é capaz de isolar blocos 3x3 para a verificação?
-------------------------------------------------------------------------- */

#include <stdio.h>
#define N 9

int ismovValid(int tab[N][N], int i, int j, int num)
{
    int x, y;

    if(!(num >=1 && num <=9))
    {
      return 0;
    }

    for (y = 0; y < N; y++)
    {
        if ((num == tab[i][y]) && (y != j))
        {
            return 0;
        }
    }

    for (x = 0; x < N; x++)
    {
        if ((num == tab[x][j]) && (x != i))
        {
            return 0;
        }
    }

    int bgi = (i / 3) * 3;
    int bgj = (j / 3) * 3;

    for (x = bgi; x < bgi + 3; x++)
    {
        for (y = bgj; y < bgj + 3; y++)
        {
            if ((tab[x][y] == num) && !(y == j && x == i))
            {
                return 0;
            }
        }
    }

    return 1;
}
 
int main() 
{

    int tab[N][N];
    int n, temp = 1;
    
    scanf("%d", &n);
    
    while(n > 0)
    {
        
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
                scanf("%d", &tab[i][j]);
            }
        }
        
        n--;
    
        int flag = 1; 
        
        for(int i = 0; i < N && flag == 1; i++)
        {
            for(int j = 0; j < N && flag == 1; j++)
            {
                if (ismovValid(tab, i, j, tab[i][j]) == 0)
                {
                    flag = 0;
                }
            }
        }
        
        printf("Instancia %d\n", temp);
        
        if(flag == 1)
        {
            printf("SIM\n");
        } else {
            printf("NAO\n");
        }
        
        printf("\n");
        
        temp++;
    }

    return 0;
}
