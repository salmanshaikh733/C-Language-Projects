//
// Created by Salman S on 2018-11-30.
//

//
// Created by Salman S on 2018-11-26.
//

#include <stdio.h>
#include <stdlib.h>
#include "bstree.h"

//initialize the tree
BStree bstree_ini(void) {
    BStree bst;
    bst = (BStree) malloc(sizeof(BStree_node *));
    *bst = NULL;
    return bst;


}

//helper method to create the node for inserting
BStree_node *new_node(Key key, Data data) {

    BStree_node *newNode = (BStree_node *) malloc(sizeof(BStree_node));
    (*newNode).key = key;
    (*newNode).data = data;
    (*newNode).left = bstree_ini();
    (*newNode).right = bstree_ini();

    return newNode;


}

//method to insert the node
void bstree_insert(BStree bst, Key key, Data data) {

    //get the root node
    BStree_node *newNode = new_node(key, data);

    //create the node we need to add
    //BStree node =bst;

    if (*bst == NULL) {
        *bst = newNode;
    } else {
        //node found
        if (key_comp((*bst)->key, key) == 0) {
            (*bst)->data = data;
        }
            //go to left
        else if (key_comp((*bst)->key, key) < 0) {
            bstree_insert((*bst)->right, key, data);
        }
            //else go to right
        else {
            bstree_insert((*bst)->left, key, data);
        }
    }
}

//method to search the tree
Data bstree_search(BStree bst, Key key) {

    if ((*bst) == NULL) {
        //printf("TREE IS NULL\n");
        return NULL;
    }
    //search the tree
    //else {
    //printf("TREE IS NOT NULL\n");
    if (key_comp((**bst).key, key) == 0) {
        //printf("MATCH FOUND\n");
        return (**bst).data;
    } else if (key_comp((**bst).key, key) < 0) {

        if ((**bst).right == NULL) {
            return NULL;
        } else {
            //printf("GOING RIGHT\n");
            bstree_search(((**bst).right), key);
        }

    } else if (key_comp((**bst).key, key) > 0) {

        if ((**bst).left == NULL) {
            return NULL;
        } else {
            //printf("GOING LEFT\n");
            bstree_search(((**bst).left), key);
        }

    }

    //}
}

//method to traverse and print out the tree
void bstree_traversal(BStree bst) {
    //BStree_node *root=bst;
    //if the tree is empty
    if (*bst == NULL) {
        return;
    }
        //if the tree is not empty traverse it then
    else {
        bstree_traversal((*bst)->left);
        key_print((*bst)->key);
        data_print((*bst)->data);
        bstree_traversal((*bst)->right);
    }
}

//free memory for the tree
void bstree_free(BStree bst) {

    if (*bst == NULL) {
        return;
    }

    bstree_free((**bst).left);
    key_free((**bst).key);
    data_free((**bst).data);
    bstree_free((**bst).right);
    free(bst);
    //printf("MEMORY IS NOW FREE");
}








