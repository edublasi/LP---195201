/* --------------------------------------------------------------------------
Disciplina  : Lógica de Programação, turma IB, 2026S1
Nome        : Eduardo Abreu
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1168
Data        : 19/05/2026
Objetivo    : Imprimir o valor de leds necessário para escrever um dado número, seguindo as condições;
Aprendizado : Introdução ao uso de funções e lógica aritmetica;
-------------------------------------------------------------------------- */

#include <stdio.h>

int count(char V[])
{
    int led[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
    int S = 0;
    
    for (int i = 0; V[i] != '\0'; i++) 
    {
        int num = V[i] - '0';
        S += led[num];
    }
    
    return S;
}

int main()
{
    int n;
    char V[101];
    
    scanf("%d", &n);
    
    while(n > 0)
    {
        scanf("%s%*c", V);
        printf("%d leds\n", count(V));
        n--;
    }
    
    return 0;
}
