#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include "pilha.h"

struct node
{
    int data;
    struct node *next;
};

struct pilha
{
    struct node *topo; // Ponteiro que aponta para cada elemento da pilha
};

struct pilha* criar_pilha()
{
    struct pilha *p = (struct pilha*)malloc(sizeof(struct pilha));
    if (p != NULL)
    {
        p->topo = NULL;
    }
    
    return p;
    
}

bool ehVazia(struct pilha *pilha)
{
    // Se o topo == NULL, então a pilha é vazia
    // Verificar que isto é verdade na criação da pilha
    if (pilha->topo == NULL)
    {
        return (true);
    }
    return (false);
}

void push(struct pilha *pilha, int item)
{
    struct node *tmp;

    // Reservando espaço na heap para a criação de um novo nó
    tmp = (struct node *)malloc(sizeof(struct node));

    tmp->data = item;        // Salva o item em data
    tmp->next = pilha->topo; // Next vira o topo da pilha
    pilha->topo = tmp;       // O topo aponta para o novo nó
}

int pop(struct pilha *pilha)
{
    struct node *tmp;
    int valor = 0;

    // Se a pilha estiver vazia, não tem como remover nenhum elemento
    if (ehVazia(pilha))
    {
        printf("\nPilha  vazia. Impossível remover elementos");
        return -1;
    }

    tmp = pilha->topo;
    valor = tmp->data;
    pilha->topo = tmp->next; // Atualizando o topo para apontar para o próximo nó
    free(tmp);               // Liberando o espaço antigo

    return (valor);
}

int obtem_elemento(struct pilha *pilha)
{
    struct node *tmp;
    int elemento = 0;

    // Se a pilha estiver vazia, não tem como obter nenhum elemento
    if (ehVazia(pilha))
    {
        printf("\nPilha  vazia. Impossível obter elementos");
        return INT_MIN;
    }

    tmp = pilha->topo;    // Tmp aponta para o topo
    elemento = tmp->data; // elemento recebe o que está no topo

    return (elemento);
}

int main()
{
    int val, n;
    bool aux;
    // Cria pilha com 5 posições
    struct pilha *pilha = criar_pilha();
    do
    {
        printf("\n************************* MENU ************************");
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Obtém elemento");
        printf("\n4. Pilha vazia?");
        printf("\n5. Sair");
        printf("\n Digite sua escolha : ");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            printf("\nDigite o valor ");
            scanf("%d", &val);
            push(pilha, val);
            break;
        case 2:
            printf("\nElemento retirado : %d", pop(pilha));
            break;
        case 3:
            printf("\nElemento do topo: %d", obtem_elemento(pilha));
            break;
        case 4:
            aux = ehVazia(pilha);
            if (aux)
            {
                printf("\nPilha vazia");
            }
            else
            {
                printf("\nPilha não está vazia");
            }
            break;
        case 5:
            return (1);
            break;
        default:
            printf("\nOpção errada!");
            break;
        }
    } while (1);

    return (0);
}
