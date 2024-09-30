#include "BST.h"

int main(){

    char buffer[50];

    printf("Please enter a series of words to store in a BST\n");
    printf("Type 'STOP' to end the series and output the BST\n");
    printf("In postorder\n");

    Node *root;

    while(1)
    {
        printf("Word = ");
        fgets(buffer,50,stdin);
        if (strcmp(buffer,"STOP\n") == 0 ) break;
        insert(&root,buffer);
    }

    printf("\n");
    postOrder(&root);

    return 0;
}