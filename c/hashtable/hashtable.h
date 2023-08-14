#ifndef MAIN
#define MAIN

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
#define Size 53
#define Primo 151

typedef struct {
    char *key;
    char *value;
} Item;

typedef struct {
    int size;
    int count;
    Item ** items;
} Hash_Table;

static Item DELETED = {NULL, NULL};


#endif