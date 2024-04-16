#include <iostream>
#include "BSTNode.h"

// using namespace std;

class BST{
    private:
        BSTNode* root;
        bool insert(BSTNode *&node, int data);
        bool remove(BSTNode *&node, int data);
        bool find(BSTNode* node, int data);
        void inOrder(BSTNode* node, std::ostream& os);
        void preOrder(BSTNode* node, std::ostream& os);
        void postOrder(BSTNode* node, std::ostream& os);
        void destroy(BSTNode*& node);
        int degree(BSTNode*& node);
    public:
        BST(): root(nullptr) {}
        // ~BST();
        bool insert(int data);
        bool remove(int data);
        bool find(int data);
        void inOrder(std::ostream& os);
        void preOrder(std::ostream& os);
        void postOrder(std::ostream& os);
};

int BST::degree(BSTNode*& node){
    int degree = 0;
    if (node->right != nullptr){
        degree = 1;
    }
    if (node->left != nullptr){
        degree += 1;
    }
    return degree;
}

void BST::postOrder(std::ostream& os){
    os << "postOrder:";
    postOrder(root,os);
    os << std::endl;
}

void BST::postOrder(BSTNode* node, std::ostream& os){
    if (node->left != nullptr){
        postOrder(node->left,os);
    }
    if (node->right != nullptr){
        postOrder(node->right,os);
    }
    os << " " << node->data;
}

void BST::preOrder(std::ostream& os){
    os << "preOrder:";
    preOrder(root,os);
    os << std::endl;
}

void BST::preOrder(BSTNode* node, std::ostream& os){
    os << " " << node->data;
    if (node->left != nullptr){
        preOrder(node->left,os);
    }
    if (node->right != nullptr){
        preOrder(node->right,os);
    }
}

void BST::inOrder(std::ostream& os){
    os << "inOrder:";
    inOrder(root,os);
    os << std::endl;
}

void BST::inOrder(BSTNode* node, std::ostream& os){
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

bool BST::insert(BSTNode *&node, int data){
    if (node == nullptr){
        node = new BSTNode (data);
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

bool BST::find(BSTNode* node, int data){
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

bool BST::remove(BSTNode *&node, int data){
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
        BSTNode *tmp = new BSTNode;
        if (degree(node) == 0){
            tmp = node;
            node = nullptr;
            delete tmp;
        }
        else if (degree(node) == 1){
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
        else {
            tmp = node->left;
            while (node->right != nullptr){
                tmp = tmp->right;
            }
            node->data = tmp->data;
            remove(node,tmp->data);
        }
    }
    return true;
}