/* --------------------------------------------------------------------------
Disciplina  : Lógica de Programação, turma IB, 2026S1
Nome        : Eduardo Abreu
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1169
Data        : 28/05/2026
Objetivo    : Descobrir quantos quilos de arroz devem ser entregues ao monge dado as condições estabelecidas do tabuleiro de damas.
Aprendizado : Uso da função recursiva, funções e lógica aritmética.
Pergunta de segunda ordem: Como calcular o valor de 2^64 sem estourar o limite de unsigned long long.
-------------------------------------------------------------------------- */

#include <stdio.h>

unsigned long long soma(int C, unsigned long long Sum);

int main() 
{
    int C, N;
    
    scanf("%d", &N);
    
    while (N > 0)
    {
        unsigned long long Sum = 0;
        scanf("%d", &C);
        
        unsigned long long resultado = soma(C, Sum);
        
        printf("%llu kg\n", (resultado / 12000));
        
        N--;
    }
    
    
    return 0;
}

unsigned long long soma(int C, unsigned long long Sum)
{
    if(C > 0)
    {
        Sum += (0x01ULL << (C - 1));
        return soma(C - 1, Sum);
        
    } else if (C == 0) {
        return Sum;
    }
}
