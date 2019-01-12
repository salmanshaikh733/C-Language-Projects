//
// Created by Salman S on 2018-11-12.
//

#ifndef CS2211ASSIGNMENT4_BST_H
#define CS2211ASSIGNMENT4_BST_H
#include "data.h"

typedef struct {
    Node *tree_nodes;
    unsigned char *is_free;
    int size;

}BStree_struct;

typedef BStree_struct *BStree;

BStree bstree_ini(int size);

void bstree_insert(BStree bst, Key *key, int data);

void bstree_traversal(BStree bst);

//free the memory
void bstree_free(BStree bst);

#endif //CS2211ASSIGNMENT4_BST_H
