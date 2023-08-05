#include "main.h"

void start_tree(tree **tree)
{
    *tree = malloc(sizeof(tree));
    (*tree)->root = NULL;
}

void delete_nodes(node *node)
{
    if(node == NULL)
        return;
        
    delete_nodes(node->left);
    delete_nodes(node->right);
    free(node);
}

void delete_tree(tree *tree)
{
    delete_nodes(tree->root);
    free(tree);
}

void add(tree *tree, int data)
{
    node *new_node = malloc(sizeof(node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;

    if (tree->root == NULL)
    {
        tree->root = new_node;
    }
    else
    {
        node *current = tree->root;
        node *parent = NULL;

        while (1)
        {
            parent = current;

            if (data < parent->data)
            {
                current = current->left;

                if (current == NULL)
                {
                    parent->left = new_node;
                    return;
                }
            }
            else if (data > parent->data)
            {
                current = current->right;

                if (current == NULL)
                {
                    parent->right = new_node;
                    return;
                }
            }
            else
            {
                return;
            }
        }
    }
}

void print_tree(node *root, int level)
{
    int i = 0;

    if (root == NULL)
        return;

    print_tree(root->right, level + 1);

    for (; i < level; i++)
        printf("   ");

    printf("%d\n", root->data);

    print_tree(root->left, level + 1);
}

void add_cmd(tree *tree)
{
    int data;

    if (scanf("%d", &data) != 1) {
        printf("Error.\n");
        return;
    }

    add(tree, data);
}

void search_cmd(tree *tree)
{
    int data;
    node *current = tree->root;

    if (scanf("%d", &data) != 1) {
        printf("Error.\n");
        return;
    }

    while(current) {
        if(current->data == data) {
            printf("%d is in the tree\n", data);
            return;
        }
        else if(current->data > data)
            current = current->left;
        else
            current = current->right;
    }

    printf("%d is not in the tree\n", data);
}

void max_cmd(tree *tree)
{
    node *max_node = tree->root;

    while(max_node != NULL && max_node->right != NULL) {
        max_node = max_node->right;
    }

    if(max_node != NULL)
        printf("The max is %d\n", max_node->data);
}

void shell(tree *tree)
{
    int status = 1;
    char cmd;

    while (status)
    {
        cmd = getchar();
        switch (cmd)
        {
            case 'a':
                add_cmd(tree);
                break;
            case 'm':
                max_cmd(tree);
                break;
            case 's':
                search_cmd(tree);
                break;
            case 'p':
                print_tree(tree->root, 0);
                break;
            case 'q':
                delete_tree(tree);
                status = 0;
                break;
        }
    }
}

int main()
{
    tree *tree;

    start_tree(&tree);

    shell(tree);
    return 0;
}