/* 
   Autor: Francisco Schneedorf Leite Ferreira
   Disciplia: AEDs II - Prática
   Data: 31/08/2026
*/

#ifndef _H_PILHA
#define _H_PILHA

#include <stdbool.h>

struct node;
struct fila;

struct fila* criar_fila(int tamanho_maximo);
bool ehVazia(struct fila* fila);
void push(struct fila* fila, int item);
int pop(struct fila* fila);
int obtem_elemento(struct fila* fila);


#endif // _H_FILA