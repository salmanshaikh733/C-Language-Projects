//
// Created by Salman S on 2018-11-09.
//

#ifndef CS2211ASSIGNMENT4_DATA_H
#define CS2211ASSIGNMENT4_DATA_H

typedef struct {
    char *name;
    int id;
} Key;

typedef struct {
    Key *key;
    int data;
} Node;


Key *key_construct(char *in_name, int in_id);

int key_comp(Key key1, Key key2);

void print_key(Key *key);

void print_node(Node node);

#endif //CS2211ASSIGNMENT4_DATA_H
