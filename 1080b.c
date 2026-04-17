/* --------------------------------------------------------------------------
Disciplina  : Lógica de Programação, turma IB, 2026S1
Nome        : Eduardo Abreu
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1080
Data        : 17/04/2026
Objetivo    : Ler 100 valores inteiros, mostrar o maior valor e sua posição.
Aprendizado : Uso de vetores, condições if e laço for.
-------------------------------------------------------------------------- */

#include <stdio.h>

int main() {
    
	int A[100] , maior , posicao;
	
	for(int i = 0; i < 100; i++) {
	    
	    scanf("%d", &A[i]);
	    
	    if(i==0){
	        
	        maior = A[i];
	        posicao = i;
	        
	    } else {
	        
	        if(A[i] >= maior){
	            
	            maior = X[i];
	            posicao = i;
	            
	        }
	    }
	}
    
    printf("%d\n", maior);
    printf("%d\n", posicao + 1);
    
    return 0;
}   
