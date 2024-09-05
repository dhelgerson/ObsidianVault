#pragma once
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct Node {

    char *value;
    struct Node *left;
    struct Node *right;

};
typedef struct Node Node;

int insert(Node **n, const char *s);
void postOrder(Node **n);

Node *newNode(const char *s);