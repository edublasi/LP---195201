/* --------------------------------------------------------------------------
Disciplina  : Lógica de Programação, turma IB, 2026S1
Nome        : Eduardo Abreu
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1241
Data        : 05/05/2026
Objetivo    : Verificar se o final de uma string dada é igual à uma string dada.
Aprendizado : Uso de strings e da biblioteca "string.h", manipulação de strings e flags.
-------------------------------------------------------------------------- */
#include <stdio.h>
#include <string.h>

int main(){
    
    int N , len , tam; 
    char A[1001] , B[1001];
  
    scanf("%d%*c", &N);

    for(int i = 0; i < N; i++) {
        int eh = 0;
        scanf("%s", A);
        scanf("%s", B);
        
        len = strlen(A) - 1;
        tam = strlen(B) - 1;

        if(tam > len){
            printf("nao encaixa\n");
        } else {
            while(tam >= 0){
                if(B[tam] != A[len]){
                    eh = 1;
                    break;
                }
                tam--;
                len--;
            }
            if(eh == 1){
                printf("nao encaixa\n");
            } else {
                printf("encaixa\n");
            }
        }
    }
    return 0;
}
