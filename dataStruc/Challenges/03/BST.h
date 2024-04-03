#include <iostream>
#include "Node.h"

class BST{
    private:
        Node* root;
        bool insert(Node *&node, int data);
        bool remove(Node *&node, int data);
        bool find(Node* node, int data);
        void inOrder(Node* node, ostream& os);
        void preOrder(Node* node, ostream& os);
        void postOrder(Node* node, ostream& os);
        void destroy(Node*& node);
        int degree(Node*& node);
    public:
        BST(): root(nullptr) {}
        // ~BST();
        bool insert(int data);
        bool remove(int data);
        bool find(int data);
        void inOrder(ostream& os);
        void preOrder(ostream& os);
        void postOrder(ostream& os);
};

int BST::degree(Node*& node){
    int degree = 0;
    if (node->right != nullptr){
        degree = 1;
    }
    if (node->left != nullptr){
        degree += 1;
    }
    return degree;
}

void BST::postOrder(ostream& os){
    os << "postOrder:";
    postOrder(root,os);
    os << endl;
}

void BST::postOrder(Node* node, ostream& os){
    if (node->left != nullptr){
        postOrder(node->left,os);
    }
    if (node->right != nullptr){
        postOrder(node->right,os);
    }
    os << " " << node->data;
}

void BST::preOrder(ostream& os){
    os << "preOrder:";
    preOrder(root,os);
    os << endl;
}

void BST::preOrder(Node* node, ostream& os){
    os << " " << node->data;
    if (node->left != nullptr){
        preOrder(node->left,os);
    }
    if (node->right != nullptr){
        preOrder(node->right,os);
    }
}

void BST::inOrder(ostream& os){
    os << "inOrder:";
    inOrder(root,os);
    os << endl;
}

void BST::inOrder(Node* node, ostream& os){
    if (node->left != nullptr){
        inOrder(node->left,os);
    }
    os << " " << node->data;
    if (node->right != nullptr){
        inOrder(node->right,os);
    }
}

bool BST::insert(int data){
    return insert(root,data);
}

bool BST::insert(Node *&node, int data){
    if (node == nullptr){
        node = new Node (data);
        return true;
    }
    else if (data < node->data){
        return insert(node->left,data);
    }
    else{ // if (data > node->data){
        return insert(node->right,data);
    }
}

bool BST::find(int data){
    return find(root,data);
}

bool BST::find(Node* node, int data){
    if (node == nullptr){
        return false;
    }
    else if (data == node->data){
        return true;
    }
    else if (data < node->data){
        return find(node->left,data);
    }
    else { //(data > node->data){
        return find(node->right,data);
    }
}

bool BST::remove(int data){
    return remove(root,data);
}

bool BST::remove(Node *&node, int data){
    if (node == nullptr){
        return false;
    }
    else if (data < node->data){
        remove(node->left, data);
    }
    else if (data > node->data){
        remove(node->right,data);
    }
    else if (data == node->data){
        if (degree(node) == 0){
            delete node;
            node = nullptr;
        }
        else if (degree(node) == 1){
            Node *tmp = new Node;
            if (node->left != nullptr){
                tmp = node;
                node = node->left;
                delete tmp;
            }
            else {
                tmp = node;
                node = node->right;
                delete tmp;
            }
        }
        else if (degree(node) == 2){
            Node *tmp = node->left;
            while (tmp->right != nullptr){
                tmp = tmp->right;
            }
            node->data = tmp->data;
            remove(node->left,tmp->data);
        }
    }
    return true;
}