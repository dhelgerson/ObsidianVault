#pragma once
#include <string.h>

typedef struct {

    char value[0];
    Node *left;
    Node *right;

} Node;

typedef struct {

    Node *root;

} BST;

BST createBST();
int insertNode(BST **BST, Node **node);
int insertString(BST **BST, const char *s);
int search(BST **BST, const char *s);
