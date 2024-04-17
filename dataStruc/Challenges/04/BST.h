#pragma once
using namespace std;
#include <iostream>

class Node {
public:
	int data;
	Node* left;
	Node* right;

	Node() : data(0), left(nullptr), right(nullptr) {}
	Node(int data) : data(data), left(nullptr), right(nullptr) {}
	int degree() {
		int children = 0;
		if (left != nullptr) {
			children += 1;
		}
		if (right != nullptr) {
			children += 1;
		}
		return children;
	};
};

//************************************************************************\\

class BST {
private:
	Node* root;
	bool insert(Node*& node, int data);
	bool remove(Node*& node, int data);
	bool find(Node* node, int data);
	void inOrder(Node* node, ostream& os);
	void preOrder(Node* node, ostream& os);
	void postOrder(Node* node, ostream& os);
public:
	BST() : root(nullptr) {}
	//~BST();
	bool insert(int data);
	bool remove(int data);
	bool find(int data);
	void inOrder(ostream& os);
	void preOrder(ostream& os);
	void postOrder(ostream& os);
};

bool BST::insert(int data) {
	return insert(root, data);
}
bool BST::remove(int data) {
	return remove(root, data);
}
bool BST::find(int data) {
	return find(root, data);
}
void BST::inOrder(ostream& os) {
	os << "InOrder: ";
	inOrder(root, os);
	os << "\n";
}
void BST::preOrder(ostream& os) {
	os << "PreOrder: ";
	preOrder(root, os);
	os << "\n";
}
void BST::postOrder(ostream& os) {
	os << "PostOrder: ";
	postOrder(root, os);
	os << "\n";
}

bool BST::insert(Node*& node, int data)
{
	if (node == nullptr) {
		node = new Node(data);
		return true;
	}
	if (data < node->data)
		return insert(node->left, data);
	if (data > node->data)
		return insert(node->right, data);
	return false;
}

void BST::postOrder(Node* node, ostream& os)
{
	if (node == nullptr) return;
	postOrder(node->left, os);
	postOrder(node->right, os);
	os << node->data << " ";
}

void BST::inOrder(Node* node, ostream& os)
{
	if (node == nullptr) return;
	inOrder(node->left, os);
	os << node->data << " ";
	inOrder(node->right, os);
}

void BST::preOrder(Node* node, ostream& os)
{
	if (node == nullptr) return;
	os << node->data << " ";
	preOrder(node->left, os);
	preOrder(node->right, os);
}

bool BST::find(Node* node, int data) {
	if (node == nullptr) {
		return false;
	}
	else if (node->data == data) {
		return true;
	}
	else if (node->data > data) {
		return find(node->left, data);
	}
	else if (node->data < data) {
		return find(node->right, data);
	}
	else return false;
}

bool BST::remove(Node*& node, int data)
{
	if (node == nullptr)
		return false;
	if (data < node->data)
		return remove(node->left, data);
	if (data > node->data)
		return remove(node->right, data);
	int deg = node->degree();
	//from here on
	if (deg == 0)
	{
		delete node;
		node = nullptr;
	}
	else if (deg == 1)
	{
		Node* tmp = node;
		if (node->left != nullptr) {
			node = node->left;
		}
		else {
			node = node->right;
		}
		delete tmp;
	}
	else
	{
		Node* tmp = node->left;
		while (tmp->right != nullptr)
		{
			tmp = tmp->right;
		}
		node->data = tmp->data;
		remove(node->left, tmp->data);
	}
	return true;
}