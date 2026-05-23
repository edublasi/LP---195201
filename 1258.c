/* --------------------------------------------------------------------------
Disciplina  : Lógica de Programação, turma IB, 2026S1
Nome        : Eduardo Abreu
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1258.c
Data        : 23/05/2026
Objetivo    : Receber as especificações das camisetas, organizá-las e imprimir os dados.
Aprendizado : Uso de structs, funções, lógica de ordenação.  
-------------------------------------------------------------------------- */
#include <stdio.h>
#include <string.h>

typedef struct camisa
{
    char nome[100];
    char cor[9];
    char tamanho;
} camisa;

int compara(camisa a, camisa b)
{
    if (a.cor[0] != b.cor[0])
    {
        return a.cor[0] - b.cor[0];   
    }

    if (a.tamanho != b.tamanho)
    {
        return b.tamanho - a.tamanho;   
    }

    return strcmp(a.nome, b.nome);
}

int main()
{
    camisa alunos[60];
    int N;
    int flagp = 1;

    while (1)
    {
        scanf("%d%*c", &N);
        if (N == 0)
        {
            break;
        }
        for (int i = 0; i < N; i++)
        {
            fgets(alunos[i].nome, 100, stdin);
            char *p = alunos[i].nome;
            
            while(*p)
            {
                if(*p == '\n')
                {
                    *p = '\0';
                }
                p++;
            }

            scanf("%s %c%*c", alunos[i].cor, &alunos[i].tamanho);
        }

        for (int i = 0; i < N - 1; i++)
        {
            for (int j = 0; j < N - i - 1; j++)
            {
                if (compara(alunos[j], alunos[j + 1]) > 0)
                {
                    camisa aux = alunos[j];
                    alunos[j] = alunos[j + 1];
                    alunos[j + 1] = aux;
                }
            }
        }

        if (!flagp)
        {
            printf("\n");    
        }
        flagp = 0;

        for (int i = 0; i < N; i++)
        {
            printf("%s %c %s\n", alunos[i].cor, alunos[i].tamanho, alunos[i].nome);
        }
    }

    return 0;
}
