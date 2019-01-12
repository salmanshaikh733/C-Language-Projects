//
// Created by Salman S on 2018-11-30.
//

#ifndef ASN52211_DATATYPE_H
#define ASN52211_DATATYPE_H


typedef int* Data;

typedef struct {
    char *skey1;
    char *skey2;

}Key_struct;

typedef Key_struct *Key;

//functions to implement
char * string_dup(char *str);

Key key_gen(char *skey, char *skey2);

int key_comp(Key key1, Key key2);

void key_print(Key key);

void key_free(Key key);

Data data_gen(int data);

void data_set(Data data, int idata);

void data_print(Data data);

void data_free(Data data);

#endif //ASN52211_DATATYPE_H
