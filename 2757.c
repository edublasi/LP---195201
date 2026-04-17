/* --------------------------------------------------------------------------
Disciplina  : Lógica de Programação, turma IB, 2026S1
Nome        : Eduardo Abreu
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/2757
Data        : 9/04/2026
Objetivo    : Ler 3 valores inteiros e manipulá-los fazendo uso do "printf".
Aprendizado : Usos diversos do printf e seus diferentes comandos.
-------------------------------------------------------------------------- */
#include <stdio.h>

int main() {
    
    int A , B , C;
    
    scanf("%d %d %d", &A, &B, &C);
    
    printf("A = %d, B = %d, C = %d\n", A , B , C);
    printf("A = %10d, B = %10d, C = %10d\n", A , B , C);
    printf("A = %010d, B = %010d, C = %010d\n", A , B , C);
    printf("A = %-10d, B = %-10d, C = %-10d\n", A , B , C);
    
    return 0;
}
