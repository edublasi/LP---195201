/* --------------------------------------------------------------------------
Disciplina  : Lógica de Programação, turma IB, 2026S1
Nome        : Eduardo Abreu
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1030
Data        : 09/06/2026
Objetivo    : Resolver o problema de Josephus
Aprendizado : Lógica de programação, uso de loops e condições.
Pergunta de segunda ordem: Por que a divisão de resto usando o contador do loop for resolve o problema?
-------------------------------------------------------------------------- */
#include <stdio.h>
 
int main() 
{

    int N, temp = 1;
    scanf("%d", &N);
    
    while(N > 0)
    {
        int n, k, sv = 0;
        scanf("%d %d", &n, &k);
        
        for(int i = 2; i <= n; i++)
        {
            sv = (sv + k) % i;
        }
        
        sv += 1;
        
        printf("Case %d: %d\n", temp, sv);
        
        temp++;
        N--;
    }

    return 0;
}
