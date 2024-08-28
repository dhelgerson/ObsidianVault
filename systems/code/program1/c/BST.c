#include "BST.h"
#include <stdio.h>

Node *newNode(const char *s)
{
    Node *n = (Node*)malloc(sizeof(Node));
    n->left = NULL;
    n->right = NULL;
    n->value = (char*)malloc((strlen(s)+1)*sizeof(char));
    strcpy(n->value,s);
    return n;
}

int insert(Node **n, const char *s)
{
    if ((*n) == NULL)
    {
        (*n) = newNode(s);
        return 1;
    }
    else if (strcmp(s,(*n)->value) > 0)
    {
        insert(&(*n)->right,s);
    }
    else
    {
        insert(&(*n)->left,s);
    }
    return 0;

}

void postOrder(Node **n)
{
    if ((*n) == NULL)
    {
        return;
    }
    if ((*n)->left != NULL)
    {
        postOrder(&(*n)->left);
    }
    if ((*n)->right != NULL)
    {
        postOrder(&(*n)->right);
    }
    printf("%s\n",(*n)->value);

}