/*
    Autor: Francisco Schneedorf Leite Ferreira
    Disciplina: AEDS II - Prática
    Data: 11/10/2026
*/

#include <stdio.h>
#include <stdlib.h>

struct no
{
    int valor;
    struct no *esq;
    struct no *dir;
};

struct no *criaArvore(struct no *root, int valor)
{
    if (root == NULL)
    {                                                             // Verifica se a raiz e nula, se sim, valor da funcao vira a raiz e inicializa os filhos; se nao, faz as devidas atribuicoes
        struct no *raiz = (struct no *)malloc(sizeof(struct no)); // Aloca espaco na heap
        if (raiz == NULL)
        {
            printf("Nao foi possivel alocar espaco na memoria.");
            return NULL;
        }
        raiz->valor = valor;
        raiz->dir = NULL;
        raiz->esq = NULL;
        return raiz;
    }
    else if (valor > root->valor)
    {
        root->dir = criaArvore(root->dir, valor);
    }
    else
    {
        root->esq = criaArvore(root->esq, valor);
    }

    return root; // Retorna o ponteiro para a raiz
}

struct no *balanceaArvore(struct no *root, int tam, int v[], int *i)
{
    if (root == NULL)
    {
        return root;
    }
    balanceaArvore(root->esq, tam, v, i);
    v[*i] = root->valor;
    (*i)++;
    balanceaArvore(root->dir, tam, v, i);
    return root;
}

struct no *imprimeArvore(struct no *root)
{
    if (root == NULL)
    {
        return root;
    }
    imprimeArvore(root->esq);
    printf("%d ", root->valor);
    imprimeArvore(root->dir);

    return root;
}

int main()
{
    struct no *root = NULL;
    int valor = 0;
    int num_nos = 0;
    int indice = 0;
    printf("Deseja alocar quantos nos?: ");
    scanf("%d", &num_nos);
    int v[num_nos];
    for (int i = 0; i < num_nos; i++) // Laco para alocar os nos na arvore
    {
        printf("Valor do %i no: ", i);
        scanf("%d", &valor);
        root = criaArvore(root, valor);
    }

    //imprimeArvore(root);
    balanceaArvore(root, num_nos, v, &indice);
    for(int j = 0; j < indice; j++){
        printf("%d ", v[j]);
    }
}