/* --------------------------------------------------------------------------
Disciplina  : Lógica de Programação, turma IB, 2026S1
Nome        : Eduardo Abreu
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1046;
Data        : 19/05/2026
Objetivo    : Imprimir a duração de um jogo dado o inicio e o fim;
Aprendizado : Introdução ao uso de funções e lógica aritmetica;
-------------------------------------------------------------------------- */

#include <stdio.h>

int calcularDuracao(int inicio, int fim)
{
    if (fim != inicio)
    {
        if (fim > inicio)
        {
            return fim - inicio;
        } else {
            return 24 - inicio + fim;
        }
    } else {
        return 24;
    }
}

int main()
{
    int inicio, fim, resultado;
    scanf("%d", &inicio);
    scanf("%d", &fim);
    
    resultado = calcularDuracao(inicio, fim);
    printf("O JOGO DUROU %d HORA(S)\n", resultado);
    
    return 0;
}    
