/* --------------------------------------------------------------------------
Disciplina  : Lógica de Programação, turma IB, 2026S1
Nome        : Eduardo Abreu
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1441
Data        : 28/05/2026
Objetivo    : Calcular a conhecida Sequência de Granizo utilizando funções recursivas.
Aprendizado : Uso da função recursiva, funções e lógica aritmética.
Pergunta de segunda ordem: Por que basta acompanhar um único valor para resolver o problema?
-------------------------------------------------------------------------- */
#include <stdio.h>

int soma(int N, int maior);

int main()
{
    int N;

    while (scanf("%d", &N) == 1 && N != 0)
    {
        printf("%d\n", soma(N, N));
    }

    return 0;
}

int soma(int N, int maior)
{
    if (N == 1)
    {
        return maior;
    }

    if (N % 2 == 0)
    {
        N = N / 2;
    }
    else
    {
        N = 3 * N + 1;
    }

    if (N > maior)
    {
        maior = N;
    }

    return soma(N, maior);
}
