/* 
   Autor: Francisco Schneedorf Leite Ferreira
   Disciplia: AEDs II - Prática
   Data: 13/08/2026
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include "lista_duplamente_encadeada.h"

struct lista
{
    struct node *inicio;
    int tamanho_atual;
};

struct node
{
    int valor;
    struct node *proximo;
    struct node *anterior;
};

struct lista *criar_lista()
{
    // Aloca a estrutura de dados fila
    struct lista *lista = (struct lista *)malloc(sizeof(struct lista));
    // Inicializa variáveis
    lista->tamanho_atual = 0;
    lista->inicio = NULL;

    return lista;
}

bool ehVazia(struct lista *lista)
{
    // Se lista->inicio = NULL, então a lista é vazia
    // Verificar que isto é verdade na criação da lista
    return (lista->inicio == NULL);
}

void push(struct lista *lista, int item)
{
    // Cria o novo nó
    struct node *novo_no = (struct node *)malloc(sizeof(struct node));
    novo_no->valor = item;
    // Condicionais
    if (ehVazia(lista))
    {
        lista->inicio = novo_no; // Inicio recebe o endereço do novo elemento da lista
        novo_no->proximo = NULL;
        novo_no->anterior = NULL;
    }
    else
    {
        // O próximo do novo nó aponta para o antigo primeiro
        novo_no->proximo = lista->inicio;
        // O anterior do antigo primeiro aponta para o novo nó
        lista->inicio->anterior = novo_no;
        // O anterior do novo nó é NULL (ele é o novo primeiro)
        novo_no->anterior = NULL;
        // Por fim, atualizamos o início da lista para o novo nó
        lista->inicio = novo_no;
    }
    // Atualiza o tamanho da lista
    lista->tamanho_atual++;
}

int pop(struct lista *lista)
{
    // Se a lista estiver vazia, não tem como remover nenhum elemento
    if (ehVazia(lista))
    {
        printf("\nlista  vazia. Impossível remover elementos");
        return -1;
    }
    struct node *tmp = lista->inicio;
    int valor_removido = tmp->valor;
    if (lista->tamanho_atual == 1)
    {
        lista->inicio = NULL;
        free(tmp);
    }
    else if (lista->tamanho_atual > 1)
    {
        lista->inicio = lista->inicio->proximo;
        lista->inicio->anterior = NULL;
        free(tmp);
    }
    // Atualiza o tamanho da lista
    lista->tamanho_atual--;
    return (valor_removido);
}

int obtem_elemento(struct lista *lista, int num)
{
    // Se a lista estiver vazia, não tem como obter nenhum elemento
    if (ehVazia(lista))
    {
        printf("\nlista  vazia. Impossível obter elementos");
        return INT_MIN;
    }
    struct node *atual = lista->inicio;
    // Laco para encontrar o elemento
    while (atual != NULL)
    {
        if (atual->valor == num)
        {
            return (atual->valor);
        }
        else
        {
            atual = atual->proximo;
        }
    }
    printf("Valor não encontrado.");
    return -1;
}

int main()
{
    int val, n;
    bool aux;
    // Cria lista
    struct lista *lista = criar_lista();
    do
    {
        printf("\n************************* MENU ************************");
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Obtém elemento");
        printf("\n4. lista vazia?");
        printf("\n5. Sair");
        printf("\n Digite sua escolha : ");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            printf("\nDigite o valor ");
            scanf("%d", &val);
            push(lista, val);
            break;
        case 2:
            printf("\nElemento retirado : %d", pop(lista));
            break;
        case 3:
        {
            int num;
            printf("\nElemento a ser buscado: ");
            scanf("%d", &num);
            printf("Resultado da busca: %d", obtem_elemento(lista, num));
            break;
        }
            case 4:
            aux = ehVazia(lista);
            if (aux)
            {
                printf("\nlista vazia");
            }
            else
            {
                printf("\nlista não está vazia");
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
