/* --------------------------------------------------------------------------
Disciplina  : Lógica de Programação, turma IB, 2026S1
Nome        : Eduardo Abreu 
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1234
Data        : 26/04/2026
Objetivo    : Transformar as sentenças aleatórias de entrada em sentenças "dançantes".
Aprendizado : Manipulação de strings, caracteres em C e tabela ASCII; Controle de estado de variáveis.
-------------------------------------------------------------------------- */
#include "stdio.h"

int main() {
    char string[51];
    int i;

    while (fgets(string, 51, stdin) != NULL) {
        int flag = 1;

        for (i = 0; string[i] != '\0'; i++) {
          
            if ((string[i] >= 'A' && string[i] <= 'Z') || (string[i] >= 'a' && string[i] <= 'z')) {
                if (flag == 1) {
                  
                    if (string[i] >= 'a' && string[i] <= 'z') {
                        string[i] = string[i] - 32;
                    }
                    flag = 0;
                } else {
                  
                    if (string[i] >= 'A' && string[i] <= 'Z') {
                        string[i] = string[i] + 32;
                    }
                    flag = 1;
                }
            }
        }
        printf("%s", string);
    }
    return 0;
}
