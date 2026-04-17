/* --------------------------------------------------------------------------
Disciplina  : Lógica de Programação, turma IB, 2026S1
Nome        : Eduardo Abreu
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1013
Data        : 8/04/2026
Objetivo    : Ler 3 valores inteiros e apresentar o maior dos 3.
Aprendizado : Uso básico de variáveis, "scanf", "printf" e manipulação algébrica em C.
-------------------------------------------------------------------------- */
#include <stdio.h>

int main() {
    int a, b, c, maiorAB, maior;

    scanf("%d %d %d", &a, &b, &c);

    maiorAB = (a + b + abs(a - b)) / 2;
    maior = (maiorAB + c + abs(maiorAB - c)) / 2;

    printf("%d eh o maior\n", maior);

    return 0;
}
