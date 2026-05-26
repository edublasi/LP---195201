/* --------------------------------------------------------------------------
Disciplina  : Lógica de Programação, turma IB, 2026S1
Nome        : Eduardo Abreu
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1029
Data        : 26/05/2026
Objetivo    : Calcular a sequência de fibonacci usando recursão
Aprendizado : Introdução à recursão, uso de funções e struct
-------------------------------------------------------------------------- */
#include <stdio.h>

typedef struct Fibstruct
{
    int resultado;
    int calls;
} Fibstruct;

Fibstruct fib(int n)
{
    Fibstruct Fib;
    
    if (n == 0) {
        Fib.resultado = 0;
        Fib.calls = 0;
        return Fib;
    }
    
    if (n == 1) {
        Fib.resultado = 1;
        Fib.calls = 0;
        return Fib;
    }
    
    Fibstruct FibLeft = fib(n - 1);
    Fibstruct FibRight = fib(n - 2);
    
    Fib.resultado = FibLeft.resultado + FibRight.resultado;
    Fib.calls = FibLeft.calls + FibRight.calls + 2;
    
    return Fib;
}


int main() 
{
    int Sum = 0;
    int n;
    
    scanf("%d%*c", &n);
    while (n > 0)
    {
        int num;
        scanf("%d%*c", &num);
        
        Fibstruct final = fib(num);

        printf("fib(%d) = %d calls = %d\n", num, final.calls, final.resultado);
        
        n--;
    }
    return 0;
}
