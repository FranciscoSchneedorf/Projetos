/*
    Autor: Francisco Schneedorf Leite Ferreira
    Disciplina: AEDS II - Prática
    Data: 08/11/2026
*/

#ifndef AVL_H
#define AVL_H

#include <stdlib.h>
#include <math.h>
#include <stdio.h>

struct node{
    int value;
    int height;
    struct node* left;
    struct node* right;  
};

static void updateHeight(struct node *n);
static struct node *rotateRight(struct node *root);
static struct node *rotateLeft(struct node *root);
int getHeight(struct node *n);
struct node *rebalance(struct node *root);
struct node *insert(struct node *root, int value);
struct node *predecessor(struct node *root);
struct node *removeNode(struct node *root, int value);

#endif