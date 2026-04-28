/* --------------------------------------------------------------------------
Disciplina  : Lógica de Programação, turma IB, 2026S1
Nome        : Eduardo Abreu
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1078
Data        : 28/04/2026
Objetivo    : Imprimir a tabuada da dezena de um inteiro N qualquer fornecido.
Aprendizado : Uso de álgebra e funções básicas da linguagem C.
-------------------------------------------------------------------------- */
#include <stdio.h>
 
int main() {
 
    int N;
    
    scanf("%d", &N);
    
    for(int i = 1; i <= 10; i++){
    
        printf("%d x %d = %d\n", i , N , i*N);
    }

    return 0;
}
