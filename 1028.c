/* --------------------------------------------------------------------------
Disciplina  : Lógica de Programação, turma IB, 2026S1
Nome        : Eduardo Abreu
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1028.c
Data        : 26/05/2026
Objetivo    : Imprimir o maior divisor comum entre dois números
Aprendizado : Lógica aritimética, uso de loops
-------------------------------------------------------------------------- */
#include <stdio.h>
 
int main() {

    int N;
    
    scanf("%d%*c", &N);
    
    while (N > 0)
    {
        int F1, F2;
        int aux, temp, menor;
        scanf("%d %d%*c", &F1, &F2);
        menor = F2;
        
        if(F1 > menor)
        {
            temp = F1 % menor;
        } else {
            menor = F1;
            temp = F2 % menor;
        }
        if (temp == 0)
        {
            printf("%d\n", menor);
        } else {
            while(temp != 0)
            {
                aux = temp;
                temp = menor % temp;
                menor = aux;
            }
        
            printf("%d\n", menor);
        }
            
        N--;
    }

    return 0;
}
