/* --------------------------------------------------------------------------
Disciplina  : Lógica de Programação, turma IB, 2026S1
Nome        : Eduardo Abreu
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1015
Data        : 14/05/2026
Objetivo    : Calcular a distância entre dois pares de pontos nos planos 1 e 2.
Aprendizado : Uso da biblioteca math.h, manipulação algébrica e de matrizes.
-------------------------------------------------------------------------- */
#include <stdio.h>
#include <math.h>
 
int main() {
    
    int N = 1 , i;
    float p1[N][2] , p2[N][2] , soma;
    
    for(i = 0; i < N; i++) {
        scanf("%f %f", &p1[i][0], &p1[i][1]);
    }

    for(i = 0; i < N; i++) {
        scanf("%f %f", &p2[i][0], &p2[i][1]);
    }

    for(i = 0; i < N; i++) {
        soma = sqrt(pow(p2[i][0] - p1[i][0], 2) + pow(p2[i][1] - p1[i][1], 2));
        printf("%.4f\n", soma);
    }

    return 0;
}
