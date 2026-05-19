/* --------------------------------------------------------------------------
Disciplina  : Lógica de Programação, turma IB, 2026S1
Nome        : Eduardo Abreu
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1017;
Data        : 19/05/2026
Objetivo    : Imprimir a quantidade de combustivel gasto dado o tempo e a velocidade media;
Aprendizado : Introdução ao uso de funções em C;
-------------------------------------------------------------------------- */
#include <stdio.h>

float calcularLitros (int tempo, int velocidade)
{
    return ((float)velocidade * tempo) / 12;
}
int main()
{
    int tempo , velocidade;
    float resultado;
    
    scanf("%d", &tempo);
    scanf("%d", &velocidade);
    
    resultado = calcularLitros(tempo, velocidade);
    printf("%.3f\n", resultado);
    
    return 0;
}
 
