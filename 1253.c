/* --------------------------------------------------------------------------
Disciplina  : Lógica de Programação, turma IB, 2026S1
Nome        : Eduardo Abreu 
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1253
Data        : 26/04/2026
Objetivo    : Decodificação do sistema de codificação Cifra de César.
Aprendizado : Manipulação de strings, caracteres em C e tabela ASCII.
-------------------------------------------------------------------------- */
#include <stdio.h>

int main() {
 
    char string[51];
    int i , qc , dist;
    
    scanf("%d", &qc);
    
    for (int t = 0; t < qc; t++) {
        
        scanf("%s", string);
        scanf("%d", &dist);
        
        for (i = 0; string[i] != '\0'; i++) {
            
            if (string[i] >= 'A' && string[i] <= 'Z') {
                
                string[i] = ((string[i] -65 - dist + 104) % 26) + 65;
            }
        }
      
        printf("%s\n", string);
    }
  
    return 0;
}
