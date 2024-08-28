#include "BST.h"
#include <string.h>
// #include <stdio.h>

int main(){
    Node *root = newNode("doesthiswork?");

    insert(&root,"testing");
    insert(&root,"something else?");

    postOrder(&root);

    return 0;
}