/* 
   Autor: Francisco Schneedorf Leite Ferreira
   Disciplia: AEDs II - Prática
   Data: 13/08/2026
*/

#ifndef _H_LISTA_DUPLAMENTE_ENCADEADA
#define _H_LISTA_DUPLAMENTE_ENCADEADA

struct node;
struct lista;

struct lista *criar_lista();
bool ehVazia(struct lista *lista);
void push(struct lista *lista, int item);
int pop(struct lista *lista);
int obtem_elemento(struct lista *lista, int num);

#endif // _H_LISTA_DUPLAMENTE_ENCADEADA