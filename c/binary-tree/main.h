#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdio.h>

#define TRUE 1
#define FALSE 0

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;

typedef struct tree
{
    struct node *root;
} tree;

void shell(tree *tree);

void start_tree(tree **tree);

void delete_tree(tree *tree);
void delete_nodes(node *node);

void add(tree *tree, int data);

void add_cmd(tree *tree);
void max_cmd(tree *tree);
void search_cmd(tree *tree);

#endif