#include <stdio.h>
#include "data.h"
#include "bst.h"

int main(void) {

    /*//define the tree
    BStree newTree;
    int treeSize;
    int numNodes;

    //values to store the data for the ree
    char name[256];
    int id;
    int data;

    //get the size of the tree
    printf("Enter the size of the binary tree\n");
    scanf("%d",&treeSize);
    newTree = bstree_ini(treeSize);

    //get the number of nodes to be inserted
    printf("Enter the number of nodes to be inserted into the tree\n");
    scanf("%d",&numNodes);

    //for loop for ever how many nodes user wants to insert
    for(int i=0;i<numNodes;i++){
        printf("Enter the name, id and value of the node you want to enter:\n");
        scanf("%s %d %d", name, &id, &data);
        bstree_insert(newTree, key_construct(name, id), data);
    }

    printf("Printing Tree\n");
    printf("\n");
    //traverse the tree and free the memory*/

    BStree bst;
    bst = bstree_ini(1000);
    bstree_insert(bst, key_construct("Once", 1), 11);
    bstree_insert(bst, key_construct("Upon", 22), 2);
    bstree_insert(bst, key_construct("a", 3), 33);
    bstree_insert(bst, key_construct("Time", 4), 44);
    bstree_insert(bst, key_construct("is", 5), 55);
    bstree_insert(bst, key_construct("filmed", 6), 66);
    bstree_insert(bst, key_construct("in", 7), 77);
    bstree_insert(bst, key_construct("Vancouver", 8), 88);
    bstree_insert(bst, key_construct("!", 99), 9);
    bstree_insert(bst, key_construct("Once", 5), 50);
    bstree_insert(bst, key_construct("Once", 1), 10);
    bstree_traversal(bst);
    bstree_free(bst);

    bstree_traversal(bst);
    bstree_free(bst);
    return 0;
}

