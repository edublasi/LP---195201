/* --------------------------------------------------------------------------
Disciplina  : Lógica de Programação, turma IB, 2026S1
Nome        : Eduardo Abreu
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1534
Data        : 12/05/2026
Objetivo    : Imprimir a matriz dada seguindo suas condições com o uso de ponteiros.
Aprendizado : Manipulação de matriz, e lógica de matrizes e ponteiros.
-------------------------------------------------------------------------- */
#include <stdio.h>
 
int main() {
    
    int N , j , i;
    
    while(scanf("%d", &N) != EOF){
        int mat[N][N] , *p = &mat[0][0];
        
        for(i = 0; i < N; i++){
            for(j = 0; j < N; j++){
                int *atual = p + (i*N) + j;
                
                if(j == (N - 1) - i){
                    *atual = 2;
                } else if (i == j){
                    *atual = 1;
                } else {
                    *atual = 3;
                }
                printf("%d", mat[i][j]);
            }
            
            printf("\n");
        }
    }
    
    return 0;
}
