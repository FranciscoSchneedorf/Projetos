/* 
   Autor: Francisco Schneedorf Leite Ferreira
   Disciplia: AEDs II - Prática
   Data: 31/08/2026
*/

#include <stdio.h> 
#include <stdlib.h> 
#include <limits.h> 
#include <stdbool.h>
#include "fila.h"

struct fila { 
	int frente, fundo, tamanho_maximo, tamanho_atual; 
	int* items; 
}; 

struct fila* criar_fila(int tamanho_maximo) { 
	// Aloca a estrutura de dados fila
    struct fila* fila = (struct fila*)malloc(sizeof(struct fila)); 
	// Armazena o tamanho que ela foi criada
    fila->tamanho_maximo = tamanho_maximo; 
    // Diz que não existe nenhum elemento na fila
	fila->tamanho_atual = 0; 
    // Define tamanho inicial de frente e fundo
    fila->frente = 0;
    fila->fundo = 0;
    // Aloca o vetor de items utilizando o tamanho maximo passado para a função
	fila->items = (int*)malloc(fila->tamanho_maximo * sizeof(int)); 
    // Retorna a fila
	return fila; 
} 

bool ehCheia(struct fila* fila) { 
    // Se tamanho_atual = tamanho_maximo, quer dizer que a fila é cheia
	if (fila->tamanho_atual == fila->tamanho_maximo) {
        return (true);
    }
    // Caso contrário, ela não está cheia
    return (false);
} 

bool ehVazia(struct fila* fila) { 
	// Se o tamanho_atual = 0, então a fila é vazia
    // Verificar que isto é verdade na criação da fila
    if (fila->tamanho_atual == 0) {
        return (true);
    } 
    return (false);
} 

void push(struct fila* fila, int item) { 
	// Se a fila estiver cheia, não tem como inserir nenhum novo elemento
    if (ehCheia(fila)) {
		printf("\nPilha cheia. Impossível inserir elementos");
        return; 
    }

    // Insere o elemento na fila
    fila->items[fila->fundo] = item;
	fila->fundo = (fila->fundo + 1)%fila->tamanho_maximo; // Novo item entra no fim da fila
    fila->tamanho_atual++; // Acresce 1 ao tamanho atual

} 


int pop(struct fila* fila) { 
	// Se a fila estiver vazia, não tem como remover nenhum elemento
    if (ehVazia(fila)) {
		printf("\nfila  vazia. Impossível remover elementos");
        return -1; 
    }

    int item_removido = fila->items[fila->frente];
    fila->frente = (fila->frente + 1)%fila->tamanho_maximo; // Atualiza o fundo para a posição do próximo elemento 
    fila->tamanho_atual--;

    // Remove o primeiro elemento a entrar na fila
	return (item_removido); 
} 

int obtem_elemento(struct fila* fila) { 
	// Se a fila estiver vazia, não tem como obter nenhum elemento
    if (ehVazia(fila)) {
		printf("\nfila  vazia. Impossível obter elementos");
        return INT_MIN; 
    }
    // Retorna o elemento do frente da fila
	return fila->items[fila->frente]; 
} 


int main() { 
    int val, n;
    bool aux;
    // Cria fila com 5 posições
    struct fila* fila = criar_fila(5); 
    do {
        printf("\n************************* MENU ************************");
	    printf("\n1. Push");
	    printf("\n2. Pop");
	    printf("\n3. Obtém elemento");
	    printf("\n4. fila vazia?");
        printf("\n5. fila cheia?");
	    printf("\n6. Sair");
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
                aux = ehCheia(fila);
                if (aux) {
                    printf("\nfila cheia");
                } else {
                    printf("\nfila não está cheia");
                }
                break;         
            case 6:
                return (1);
                break;
            default: printf("\nOpção errada!");
                break;
        }
	} while(1);
    
    return (0);
 }





