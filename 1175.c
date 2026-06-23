/* --------------------------------------------------------------------------
Disciplina  : Lógica de Programação, turma IB, 2026S1
Nome        : Eduardo Abreu
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1075
Data        : 23/06/2026
Objetivo    : Inverter um vetor
Aprendizado : Lógica de programação, uso de loops, condições e vetores.
Pergunta de segunda ordem: Por que o uso de uma váriavel temporária é necessário?
-------------------------------------------------------------------------- */
#include <stdio.h>
 
int main() 
{
    int N[20];
    int temp;
    int tamanho = 19;
    
    for (int i = 0; i < 20; i++)
    {
        scanf("%d", &N[i]);
    }
    
    for(int i = 0; i < 10; i++)
    {
        temp = N[i];
        N[i] = N[tamanho - i];
        N[tamanho - i] = temp;
    }
    
    for (int i = 0; i < 20; i++)
    {
        printf("N[%d] = %d\n",i, N[i]);
    }
     
    return 0;
}
