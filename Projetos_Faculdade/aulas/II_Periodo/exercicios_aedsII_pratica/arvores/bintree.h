/*
    Autor: Francisco Schneedorf Leite Ferreira
    Disciplina: AEDS II - Prática
    Data: 21/09/2026
*/

#ifndef _H_ARVORE
#define _H_ARVORE

struct node {
    int valor;
    struct node *esquerda, *direita;
};

struct node* novo_no(int item);
struct node* inserir(struct node* node, int valor);
struct node* buscar(struct node* root, int valor);
struct node* remover(struct node* root, int valor);
struct node *predecessor(struct node *subarvore);

#endif // _H_ARVORE