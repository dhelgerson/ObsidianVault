#pragma once
#include <string.h>

typedef struct {

    char value[0];
    Node *left;
    Node *right;

} Node;

struct BST {

    Node *root;

};