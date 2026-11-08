/*
    Autor: Francisco Schneedorf Leite Ferreira
    Disciplina: AEDS II - Prática
    Data: 21/09/2026
*/

#include <stdio.h>
#include <stdlib.h>
#include "bintree.h"

// Cria um novo nó na árvore
struct node *novo_no(int item)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->valor = item;
    temp->esquerda = temp->direita = NULL;
    return temp;
}

// Inserir novo nó com determinado
// valor na árvore binária
struct node *inserir(struct node *node, int valor)
{
    // Se a árvore é vazia, então cria um novo nó
    if (node == NULL)
    {
        return novo_no(valor);
    }

    // Caso contrário, faz uma busca pelo local adequado de inserção
    if (valor < node->valor)
    {
        node->esquerda = inserir(node->esquerda, valor);
    }
    else if (valor > node->valor)
    {
        node->direita = inserir(node->direita, valor);
    }

    // Retorna o ponteiro para o nó
    return node;
}

// Procura por um valor na árvore
struct node *buscar(struct node *root, int valor)
{
    // Caso base - a raiz é vazia ou o valor está na raiz
    if (root == NULL || root->valor == valor)
    {
        return root;
    }

    // Valor é maior que a raiz
    if (root->valor < valor)
    {
        return buscar(root->direita, valor);
    }

    // Valor é menor que a raiz
    return buscar(root->esquerda, valor);
}

struct node *predecessor(struct node *subarvore)
{
    while (subarvore->direita != NULL)
    {
        subarvore = subarvore->direita;
    }
    return subarvore;
}

struct node *remover(struct node *root, int valor)
{
    if (root == NULL)
    {
        return root;
    }
    if (root->valor < valor)
    {
        root->direita = remover(root->direita, valor);
        return root;
    }
    else if (root->valor > valor)
    {
        root->esquerda = remover(root->esquerda, valor);
        return root;
    }
    else // root->valor == valor
    {
        if (root->esquerda == NULL && root->direita == NULL)
        {
            free(root);
            return NULL;
        }
        else if (root->esquerda == NULL && root->direita != NULL)
        {
            struct node *tmp = root->direita; // Salva o filho da direita em uma variavel temporaria
            free(root);
            return tmp;
        }
        else if (root->esquerda != NULL && root->direita == NULL)
        {
            struct node *tmp = root->esquerda; // Salva o filho da esquerda em uma variavel temporaria
            free(root);
            return tmp;
        }
        else
        { // root->esquerda != NULL && root->direita != NULL
            struct node *tmp = predecessor(root->esquerda);
            root->valor = tmp->valor;
            root->esquerda = remover(root->esquerda, tmp->valor);
        }
        return root;
    }
}

int main()
{
    // Define a árvore como uma estrutura vazia
    struct node *root = NULL;

    // Insere o nó inicial (raiz)
    root = inserir(root, 50);

    // Insere outros nós
    inserir(root, 30);
    inserir(root, 20);
    inserir(root, 40);
    inserir(root, 70);
    inserir(root, 60);
    inserir(root, 80);

    // Valor a ser buscado
    int valor = 6;

    // Buscando na árvore
    if (buscar(root, valor) == NULL)
    {
        printf("%d não encontrado\n", valor);
    }
    else
    {
        printf("%d encontrado\n", valor);
    }

    // Novo valor a ser buscado
    valor = 60;

    // Buscando na árvore
    if (buscar(root, valor) == NULL)
    {
        printf("%d não encontrado\n", valor);
    }
    else
    {
        printf("%d encontrado\n", valor);
    }

    // Removendo valor
    root = remover(root, 80);

    return 0;
}