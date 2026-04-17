/* --------------------------------------------------------------------------
Disciplina  : Lógica de Programação, turma IB, 2026S1
Nome        : Eduardo Abreu
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1071
Data        : 17/04/2026
Objetivo    : Ler dois valores inteiros e calcular a soma dos números impares entre eles.
Aprendizado : Uso de condições if, else, laço for e divisão com resto.
-------------------------------------------------------------------------- */
#include <stdio.h>

int main() {
    
	int X, Y, soma = 0, maior, menor;
	
	scanf("%d %d", &X, &Y);
	
	if (X < Y) {
	    
		maior = Y;
		menor = X;
		
	}
	else
	{
	    
		maior = X;
		menor = Y;
		
	}
	
	for (int i = menor + 1; i < maior; i++) {
	    
	   if (i % 2 != 0) {
	       
	       soma = soma + i;
	       
	   } 
	}
	
	printf("%d\n", soma);
	
	return 0;
}
