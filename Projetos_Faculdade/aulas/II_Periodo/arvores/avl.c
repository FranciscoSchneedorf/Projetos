/*
    Autor: Francisco Schneedorf Leite Ferreira
    Disciplina: AEDS II - Prática
    Data: 08/11/2026
*/

#include "avl.h"

int getHeight(struct node *n)
{
    if (n == NULL)
    {
        return 0;
    }
    return n->height;
}

static void updateHeight(struct node *n)
{
    int leftHeight = getHeight(n->left);
    int rightHeight = getHeight(n->right);
    n->height = 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

static struct node *rotateRight(struct node *root)
{
    struct node *new_root = root->left;

    root->left = new_root->right;
    new_root->right = root;

    updateHeight(root);
    updateHeight(new_root);

    return new_root;
}

static struct node *rotateLeft(struct node *root)
{
    struct node *new_root = root->right;

    root->right = new_root->left;
    new_root->left = root;

    updateHeight(root);
    updateHeight(new_root);

    return new_root;
}

struct node *rebalance(struct node *root)
{
    updateHeight(root);

    // verify if its unbalenced
    int balance = getHeight(root->left) - getHeight(root->right);

    // apply the rotations
    if (balance > 1) // tree is taller in the left
    {
        struct node *left = root->left;
        if (getHeight(left->right) > getHeight(left->left))
        {
            root->left = rotateLeft(left); // left-right cases
        }
        return rotateRight(root);
    }
    else if (balance < -1) // tree is taller in the right
    {
        struct node *right = root->right;
        if (getHeight(right->left) > getHeight(right->right))
        {
            root->right = rotateRight(right); // right-left case
        }
        return rotateLeft(root);
    }

    return root;
}

struct node *insert(struct node *root, int value)
{ // add the root or new sons to the tree
    if (root == NULL)
    { // inicializes the root and its sons
        struct node *new_node = malloc(sizeof *new_node);
        new_node->value = value;
        new_node->left = NULL;
        new_node->right = NULL;
        new_node->height = 1;
        return new_node;
    }
    // iterate through the child nodes
    if (value > root->value)
    {
        root->right = insert(root->right, value);
    }
    else if (value < root->value)
    {
        root->left = insert(root->left, value);
    }
    else
    {
        return root;
    }

    return rebalance(root);
}

struct node *predecessor(struct node *root)
{
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

struct node *removeNode(struct node *root, int value)
{
    struct node *temp = NULL;
    if (root == NULL)
    {
        return root;
    }
    // iterate throught the child nodes
    if (root->value < value)
    {
        root->right = removeNode(root->right, value);
    }
    else if (root->value > value)
    {
        root->left = removeNode(root->left, value);
    }
    else
    { // root->value == value
        if (root->right == NULL && root->left == NULL)
        {
            free(root);
            return NULL;
        }
        else if (root->left == NULL)
        {
            temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            temp = root->left;
            free(root);
            return temp;
        }

        struct node *pred = predecessor(root->left);
        root->value = pred->value;
        root->left = removeNode(root->left, root->value);
    }
    return rebalance(root);
}
