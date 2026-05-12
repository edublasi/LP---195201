/* --------------------------------------------------------------------------
Disciplina  : Lógica de Programação, turma IB, 2026S1
Nome        : Eduardo Abreu
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1534
Data        : 12/05/2026
Objetivo    : Imprimir a matriz dada seguindo suas condições
Aprendizado : Manipulação de matriz, e lógica de matrizes.
-------------------------------------------------------------------------- */
#include <stdio.h>
 
int main() {
    
    int N, j , i;
    
    while(scanf("%d", &N) != EOF){
        int mat[N][N];
        
        for(i = 0; i < N; i++){
            for(j = 0; j < N; j++){
                if(j == (N - 1) - i){
                    mat[i][j] = 2;
                } else if (i == j){
                    mat[i][j] = 1;
                } else {
                    mat[i][j] = 3;
                }
                printf("%d", mat[i][j]);
            }
            printf("\n");
        }
    }
    
    return 0;
}
