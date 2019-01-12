//
// Created by Salman S on 2018-11-12.
//

#include <stdio.h>
#include <stdlib.h>
#include "bst.h"


//creates the new Binary search tree allocates memory for tree
BStree bstree_ini(int size) {
    //allocate memory
    BStree newTree;
    newTree = (BStree) malloc(sizeof(BStree_struct));
    newTree->tree_nodes = (Node *) malloc((size + 1) * sizeof(Node));
    newTree->is_free = (unsigned char *) malloc((size + 1) * sizeof(unsigned char));
    //set member size to size
    newTree->size = size;
    //set everything to empty
    for (int i = 0; i < size + 1; i++) {
        newTree->is_free[i] = 1;
    }
    return newTree;
}

void bstreeinserteHelper(BStree bst, Key *key, int data, int index) {

    if (index>bst->size){
        /*printf("Tree is full, Printing rest of tree.\n");
        bstree_traversal(bst);
        exit(0);*/
        return;
    }
    else {
        ///if the index value we are at is free insert the node there
        if (bst->is_free[index] == 1) {
            bst->tree_nodes[index].key = key;
            bst->tree_nodes[index].data = data;
            bst->is_free[index] = 0;
        }

        //go to right
        else if (bst->is_free[index] == 0 && ((key_comp(*key, *bst->tree_nodes[index].key)) < 0)) {
            bstreeinserteHelper(bst, key, data, index * 2);
        }

        //go to left
        else if (bst->is_free[index] == 0 && (key_comp(*key, *bst->tree_nodes[index].key)) > 0) {
            bstreeinserteHelper(bst, key, data, ((index * 2) + 1));
        }
        //if the same value arlerayd exists
        else if(bst->is_free[index]==0 &&(key_comp(*key,*bst->tree_nodes[index].key)==0)) {
            //printf("Value is already in tree\n");
           // print_key(key);
            //printf("\n");
            //printf("Value is already in tree... printing key and rest of tree.\n");
            //bstree_traversal(bst);
            return;
        }
    }
}


//insert values into the binary search tree,  data is i
void bstree_insert(BStree bst, Key *key, int data) {

    //call the helper function ard start at index 1
    bstreeinserteHelper(bst, key, data, 1);
}

void traversalFunction_withIndex(BStree currentTree, int index) {

    if(index<currentTree->size+1) {
        if (currentTree->is_free[index * 2] == 0) {
            traversalFunction_withIndex(currentTree, (index * 2));
        }
        print_node(currentTree->tree_nodes[index]);

        if (currentTree->is_free[(index * 2) + 1] == 0) {
            traversalFunction_withIndex(currentTree, ((index * 2) + 1));
        }
    }
    else {
        return;
    }
}


//traverse the tree
void bstree_traversal(BStree bst) {
    traversalFunction_withIndex(bst, 1);
}

//free the memory allocated for the the binary search tree
void bstree_free(BStree bst) {
    free(bst);
}










