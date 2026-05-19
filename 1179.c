/* --------------------------------------------------------------------------
Disciplina  : Lógica de Programação, turma IB, 2026S1
Nome        : Eduardo Abreu
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1179
Data        : 19/05/2026
Objetivo    : Imprimir os vetores seguindo as condições impostas;
Aprendizado : Introdução ao comando switch e lógica de vetores;
-------------------------------------------------------------------------- */

#include <stdio.h>

int main()
{
    int par[5], impar[5] , n , qp = 0, qi = 0, i;
    
    for (i = 0; i < 15; i++)
    {
        scanf("%d", &n);
        
        switch (n % 2)
        {
            case 0:
            par[qp] = n;
            qp++;
            
            if (qp == 5)
            {
                for (int j = 0; j < 5; j++)
                {
                    printf("par[%d] = %d\n", j, par[j]);
                }
                qp = 0;
            }
            break;
            case 1:
            case -1:
            impar[qi] = n;
            qi++;
            
            if (qi == 5)
            {
                for (int j = 0; j < 5; j++)
                {
                    printf("impar[%d] = %d\n", j, impar[j]);
                }
                qi = 0;
            }
            break;
        }
    }
    for (int j = 0; j < qi; j++)
    {
        printf("impar[%d] = %d\n", j, impar[j]);
    }

    for (int j = 0; j < qp; j++)
    {
        printf("par[%d] = %d\n", j, par[j]);
    }

    return 0;
}
