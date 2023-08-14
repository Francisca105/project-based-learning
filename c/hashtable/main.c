#include "hashtable.h"

Item *createItem(char *key, char *value) {
    Item *item = malloc(sizeof(Item));
    item->key = strdup(key);
    item->value = strdup(value);
    return item;
}

Hash_Table *createHashTable() {
    Hash_Table *table = malloc(sizeof(Hash_Table));
    table->size = Size;
    table->count = 0;
    table->items = calloc((size_t) table->size, sizeof(Item *));
    return table;
}

void deleteItem(Item *item) {
    free(item->key);
    free(item->value);
    free(item);
}

void deleteHashTable(Hash_Table *table) {
    int i = 0;
    for(; i < table->size; i++) {
        Item *item = table->items[i];
        if(item != NULL) {
            deleteItem(item);
        }
    }
    free(table->items);
    free(table);
}

int hash(char *key, int a, int m) {
    long hash = 0;
    const int len_s = strlen(key);
    int i = 0;
    for(; i < len_s; i++) {
        hash += (long) pow(a, len_s - (i + 1)) * key[i];
        hash = hash % m;
    }
    return (int) hash;
}

void insertItem(Hash_Table * table, char *key, char *value) {
    Item *item = createItem(key, value);
    int index = hash(key, table->size, 0);
    Item *currentItem = table->items[index];
    int i = 1;
    while(currentItem != NULL) {
        if(currentItem != &DELETED) {
            index = hash(key, table->size, i);
            currentItem = table->items[index];
            i++;
        }
    }
    table->items[index] = item;
    table->count++;
}

char* searchItem(Hash_Table *table, char *key) {
    int index = hash(key, table->size, 0);
    Item *item = table->items[index];
    int i = 1;
    while(item != NULL) {
        if(item != &DELETED && strcmp(item->key, key) == 0) {
            return item->value;
        }
        index = hash(key, table->size, i);
        item = table->items[index];
        i++;
    }
    return NULL;
}   

void delete(Hash_Table *table, char *key) {
    int index = hash(key, table->size, 0);
    Item *item = table->items[index];
    int i = 1;
    while(item != NULL) {
        if(item != &DELETED && strcmp(item->key, key) == 0) {
            deleteItem(item);
            table->items[index] = &DELETED;
            return;
        }
        index = hash(key, table->size, i);
        item = table->items[index];
        i++;
    }
    table->count--;
}