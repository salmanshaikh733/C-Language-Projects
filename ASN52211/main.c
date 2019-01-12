#include <stdio.h>
#include "matrix.h"
#include "string.h"
#include <stdlib.h>

int main(){

    //initialize the matrix
    Matrix matrix = matrix_construction();
    Index index1[256];
    Index index2[256];
    //Value value;

    int condition=1;
    char resume[256];

    //ask for the user input
    while(condition ==1){
        printf("Please enter two strings.\n");
        scanf(" %s %s", &index1, &index2);

        //if the value is already in tree
        if(matrix_isin(matrix,index1,index2)==1){
            //increment the number of occurrences by 1
            //printf("ALREADY IN TREE... INCREMENTING!\n");
            matrix_inc(matrix,index1,index2,1);
        }
        else{
            //otherwise add the value to the tree
           // printf("ADDING VALUE TO TREE\n");
            matrix_set(matrix, index1, index2, 1);
        }

        printf("Would you like to continue inserting? Type y to continue, and n to end the program.\n");
        scanf("%s", &resume);

        if(strcmp(resume,"n")==0){
            condition=0;
        }

    }


    printf("String 1\tString 2\tOccurences\n");

    //print the tree
    matrix_list(matrix);

    //deallocate the memory for the tree
    matrix_destruction(matrix);
    return 0;
}