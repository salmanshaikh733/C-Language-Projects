//
// Created by Salman S on 2018-11-28.
//

#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

//create new bst called newMatrix
Matrix matrix_construction(void){
    Matrix newMatrix = bstree_ini();
    return newMatrix;
}

//check if the index1 and index2 are in the tree
unsigned char matrix_isin(Matrix m ,Index index1, Index index2){
    //create a new key using keygen function
    Key newKey = key_gen(index1,index2);
    //if not in tree return 0
    if(bstree_search(m,newKey)==NULL){
        return 0;
    }
    //if in tree return 1
    else {
        return 1;
    }

}

//get the data at the matrix value of index 1 and index 2
Value *matrix_get(Matrix m, Index index1, Index index2){

    //create the new key
    Key newKey = key_gen(index1,index2);
    if(bstree_search(m,newKey)!=NULL){
        return bstree_search(m,newKey);
    }
    else {
        return NULL;
    }
}
//set the matrix value that is passed in
void matrix_set(Matrix m, Index index1, Index index2, Value value){
    Key newKey = key_gen(index1,index2);
    bstree_insert(m,newKey,data_gen(value));



}
//increament the data value at the index value specified
void matrix_inc(Matrix m, Index index1, Index index2, Value value){
    //create new key
    Key newKey = key_gen(index1,index2);
    //get current data value
    Data returnVal= bstree_search(m,newKey);
    Value *newNumber=value;

    //calculate value
    Value result=value+*returnVal;

    //generate the data type
    Data newData=data_gen(result);

    //insert into tree
    bstree_insert(m, newKey, newData);
}

//print out matrix
void matrix_list(Matrix m){
    bstree_traversal(m);
}

//destroy the matrix.
void matrix_destruction(Matrix m){
    bstree_free(m);
    //printf("MEMORY IS NOW FREE");
}








