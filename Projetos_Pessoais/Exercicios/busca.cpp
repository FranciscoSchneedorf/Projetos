/*
Autor: Francisco Schneedorf Leite Ferreira
Data: 10/08/2026
Disciplina: AEDs II - Prática
Objetivo: Desenvolver um script que realiza a busca de um elemento em um vetor e compará-lo com as outras duas versões ensinadas em aula
*/

#include <stdio.h>
#define TAM 10

// Versão 1

int busca(int vetor[], int n, int numero)
{
    int pos = -1;
    int i = 0;

    while (i < n)
    {
        if (vetor[i] == numero)
        {
            pos = i;
            break;
        }
        else
        {
            i++;
        }
    }

    return pos;
}

int main()
{
    int funcao = 0, numero = 0, vetor[TAM] = {3, 2, 4, 1, 5, 9, 6, 8, 7, 0};

    printf("Qual numero deseja buscar?\n");
    scanf("%i", &numero);
    printf("Buscando...\n");
    funcao = busca(vetor, TAM, numero);
    if (funcao != -1)
    {
        printf("O numero %i esta na posicao %i", numero, funcao);
    }
    else
    {
        printf("Numero nao encontrado.");
    }

    return 0;
}