/* --------------------------------------------------------------------------
Disciplina  : Lógica de Programação, turma IB, 2026S1
Nome        : Eduardo Abreu
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1080
Data        : 17/04/2026
Objetivo    : Ler 100 valores inteiros, mostrar o maior valor e sua posição.
Aprendizado : Uso de condições if, laço for e loops.
-------------------------------------------------------------------------- */
#include <stdio.h>

int main() {
    
    int maior , n , posicao;
    
    for(int i = 1; i <= 100; i++) {
        
        scanf("%d", &n);
        
        if(i==1) {
            
            maior = n;
            posicao = i;
            
        }
        
        if(n > maior) {
            
            maior = n;
            posicao = i;
            
        }
        
        
    }
    
    printf("%d\n", maior);
    printf("%d\n", posicao);
    
    return 0;
}
