/* 
   Autor: Francisco Schneedorf Leite Ferreira
   Disciplia: AEDs II - Prática
   Data: 05/08/2026
*/

#include <stdio.h> 
#include <stdlib.h> 
#include <limits.h> 
#include <stdbool.h>
#include "fila_apontadores.h"

struct fila { 
	struct node *frente;
    struct node *fundo;
	int tamanho_atual; 
}; 

struct node {
    int valor;
    struct node *proximo;
};

struct fila* criar_fila() { 
	// Aloca a estrutura de dados fila
    struct fila* fila = (struct fila*)malloc(sizeof(struct fila));
    // Inicializa variáveis
    fila->tamanho_atual = 0;
    fila->frente = NULL;
    fila->fundo = NULL;

    return fila;
} 

bool ehVazia(struct fila* fila) { 
	// Se fila->frente = NULL, então a fila é vazia
    // Verificar que isto é verdade na criação da fila
    if (fila->frente == NULL) {
        return (true);
    } 
    return (false);
} 

void push(struct fila* fila, int item) { 
    // Cria o novo nó
    struct node *novo_no = (struct node*)malloc(sizeof(struct node));
    // Guarda o valor no novo nó
    novo_no->valor = item;
    // Cria um próximo nó vaizo
    novo_no->proximo = NULL;
    // Conecta o nó
    if (ehVazia(fila))
    {
        fila->frente = novo_no;
        fila->fundo = novo_no;
    }
    else
    {
        fila->fundo->proximo = novo_no; // Antigo elemento vazio na fila vira o novo nó
        fila->fundo = novo_no; // Aponta o fundo para o novo nó
    }
    // Atualiza o tamanho da fila
    fila->tamanho_atual++;
} 


int pop(struct fila* fila) { 
	// Se a fila estiver vazia, não tem como remover nenhum elemento
    if (ehVazia(fila)) {
		printf("\nfila  vazia. Impossível remover elementos");
        return -1; 
    }
    // Cria um nó temporário que aponta para o que está saindo da fila
    struct node* temp = fila->frente;
    // Salva o item da frente (o que será removido)
    int valor = fila->frente->valor;
    // Avança a fila
    fila->frente = fila->frente->proximo;
    // Decrementa o tamanho atual
    fila->tamanho_atual--;
    // Libera temp da memória
    free(temp);
    // Verifica se a fila esvaziou completamente e posiciona fila->fundo corretamente
    if (fila->frente == NULL)
    {
        fila->fundo = NULL;
    }
    // Remove o primeiro elemento a entrar na fila
	return (valor); 
} 

int obtem_elemento(struct fila* fila) { 
	// Se a fila estiver vazia, não tem como obter nenhum elemento
    if (ehVazia(fila)) {
		printf("\nfila  vazia. Impossível obter elementos");
        return INT_MIN; 
    }
    // Retorna o elemento da frente da fila
	return fila->frente->valor; 
} 

int main() { 
    int val, n;
    bool aux;
    // Cria fila
    struct fila* fila = criar_fila(); 
    do {
        printf("\n************************* MENU ************************");
	    printf("\n1. Push");
	    printf("\n2. Pop");
	    printf("\n3. Obtém elemento");
	    printf("\n4. fila vazia?");
	    printf("\n5. Sair");
	    printf("\n Digite sua escolha : ");
	    scanf("%d",&n);
	    switch(n) {
            case 1: 
		        printf("\nDigite o valor ");
                scanf("%d",&val);
                push(fila , val);
                break;
            case 2: 
                printf("\nElemento retirado : %d",pop(fila));
                break;
            case 3: 
                printf("\nElemento da frente: %d",obtem_elemento(fila));
                break;
            case 4: 
                aux = ehVazia(fila);
                if (aux) {
                    printf("\nfila vazia");
                } else {
                    printf("\nfila não está vazia");
                }
                break;      
            case 5:
                return (1);
                break;
            default: printf("\nOpção errada!");
                break;
        }
	} while(1);
    
    return (0);
 }





