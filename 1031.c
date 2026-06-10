/* --------------------------------------------------------------------------
Disciplina  : Lógica de Programação, turma IB, 2026S1
Nome        : Eduardo Abreu
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1031
Data        : 09/06/2026
Objetivo    : Garantir que a região 13 seja a última a ser desligada.(Problema de josephus com condições)
Aprendizado : Lógica de programação, uso de loops e condições.
Pergunta de segunda ordem: Porque fazemos por força bruta, testando todos os casos até dar certo?
-------------------------------------------------------------------------- */
#include <stdio.h>

int counter(int N, int m) 
{
    int sv = 0;
    
    for (int i = 2; i <= N - 1; i++) 
    {
        sv = (sv + m) % i;
    }
    
    return (sv + 1) % N;
}

int main() 
{
    int N;
    
    while (scanf("%d", &N) == 1 && N != 0) 
    {
        int m = 1;
        
        while (counter(N, m) != 12) 
        {
            m++;
        }
        
        printf("%d\n", m);
    }

    return 0;
}
