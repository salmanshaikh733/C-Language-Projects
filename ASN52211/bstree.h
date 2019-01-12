//
// Created by Salman S on 2018-11-30.
//

#ifndef ASN52211_BSTREE_H
#define ASN52211_BSTREE_H
#include "datatype.h"


//type definitions
typedef struct BStree_node {
    Key key;
    Data data;
    struct BStree_node *left,*right;

}BStree_node;

typedef BStree_node** BStree;


//implement these methods
BStree bstree_ini(void);

void bstree_insert(BStree bst, Key key, Data data);

Data bstree_search(BStree bst, Key key);

void bstree_traversal(BStree bst);

void bstree_free(BStree bst);

#endif //ASN52211_BSTREE_H
