//
// Created by Salman S on 2018-11-26.
//

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "datatype.h"

//duplicate the string
char *string_dup(char *str){

    char *string=strdup(str);

    return string;
}

//generate a new key type
Key key_gen(char *skey, char *skey2){

    Key newKey =(Key*)malloc(sizeof(Key_struct));

    newKey->skey1=string_dup(skey);
    newKey->skey2=string_dup(skey2);

    return newKey;

}

//compare the keys
int key_comp(Key key1, Key key2){

    int compVal=strcmp(key1->skey1,key2->skey1);
    if(compVal==0){
        compVal=strcmp(key1->skey2,key2->skey2);
    }
    return compVal;
}

//print the key
void key_print(Key key){

    printf("%s\t\t%s",key->skey1,key->skey2);

}

//free the memoery for key
void key_free(Key key){
    free(key->skey1);
    free(key->skey2);
    free(key);
}


//generate the data type
Data data_gen(int data){

    Data newData =malloc(sizeof(Data));
    *newData=data;
    return newData;

}


//set the data to data
void data_set(Data data, int idata){

    *data=idata;
}

//print the data
void data_print(Data data){

    printf("\t\t%d\n",*data);
}

//free memeory for data
void data_free(Data data){
    free(data);
}





