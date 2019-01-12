//
// Created by Salman S on 2018-11-12.
//#
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data.h"


//allocating space for new key
Key *key_construct(char *in_name, int in_id){

    //char newID=(char) in_id;
    Key *newKey =(Key*)malloc(sizeof(newKey));

    newKey->name=strdup(in_name);
    newKey->id=in_id;

    return newKey;
}


//key comparison method
int key_comp(Key key1, Key key2){

    int compareValue=strcmp(key1.name,key2.name);
    ///if key.name are same
    if (compareValue==0){
        compareValue=key1.id-key2.id;
    }
    return compareValue;

}
//method to print the key
void print_key(Key *key){
    printf("(%s\t%d)",key->name,key->id);
}

//print the node with the key
void print_node(Node node){
    print_key(node.key);
    printf("\t%d\n",node.data);
}





