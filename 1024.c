/* --------------------------------------------------------------------------
Disciplina  : Lógica de Programação, turma IB, 2026S1
Nome        : Eduardo Abreu
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1024
Data        : 8/04/2026
Objetivo    : Realizar 3 passadas, realizando alterações na string respeitando suas condições.
Aprendizado : Uso de ponteiros, manipulação algébrica e de strings, aritmética de ponteiros.
-------------------------------------------------------------------------- */
#include "stdio.h"

int main() {
    
    char str[1001], temp;
    int i , N, j;
    scanf("%d%*c", &N);

    for(int t = 1; t <= N; t++) {
        char *p = str;
        
        fgets(str , 1001 , stdin);
        
        while(*p != '\0' && *p != '\n'){
            p++;
        }
        
        if(*p == '\n'){
            *p = '\0';
        }
        
        int len = (p - str); 
        int len1 = len / 2;
        j = len - 1;

        for (i = 0; i < len; i++) {
            if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z')) {
                str[i] = str[i] + 3;
            }
        }
        
        for (i = 0; i < len1; i++) {
            temp = str[i];
            str[i] = str[j];
            str[j] = temp;   
            j--;
        }

        for (i = len1; i < len; i++){
            str[i] = str[i] - 1;
        }
        
        printf("%s\n", str); 
        
    }
    return 0;
}
