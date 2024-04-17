#pragma once
using namespace std;
#include <iostream>

class Nodee {
public:
	int data;
	Nodee* next;
	Nodee* prev;//add

	Nodee() : data(0), next(nullptr), prev(nullptr) {}//add ", prev(nullptr)"
	Nodee(int data) : data(data), next(nullptr), prev(nullptr) {}//add ", prev(nullptr)"
	Nodee(int data, Nodee* next, Nodee* prev) : data(data), next(next), prev(prev) {}//add "Node* prev" & ", prev(prev)"
};

class LinkedList {
public:
	LinkedList() : head(nullptr), tail(nullptr) {}
	~LinkedList();

	void append(int data);
	void prepend(int data);
	bool search(int data);
	bool remove(int data);

	//add the following
	bool tailRemove(int data);
	void tailDisplay(ostream& os);

	void display(ostream& os);

	friend ostream& operator<<(ostream& os, LinkedList& right);

private:
	Nodee* head;
	Nodee* tail;
};

LinkedList::~LinkedList() {
	Nodee* tmp = head;

	while (tmp != nullptr) {
		head = head->next;
		delete tmp;
		tmp = head;
	}
	tail = nullptr;
}

void LinkedList::append(int data) {
	Nodee* tmp = new Nodee(data);

	tmp->prev = tail;//add this

	if (head == nullptr) {
		head = tmp;
	}
	else {
		tail->next = tmp;
	}
	tail = tmp;
}

void LinkedList::prepend(int data) {//inverse of append... ex. head instead of tail
	Nodee* tmp = new Nodee(data);

	tmp->next = head;

	if (head == nullptr) {
		tail = tmp;
	}
	else {
		head->prev = tmp;
	}
	head = tmp;
}

bool LinkedList::search(int data) {//same
	Nodee* tmp = head;

	while (tmp != nullptr) {
		if (tmp->data == data) return true;

		tmp = tmp->next;
	}

	return false;
}

bool LinkedList::remove(int data) {
	Nodee* tmp = head;
	//Node* prev = nullptr;

	while (tmp != nullptr) {
		if (tmp->data == data) {
			/*if (tmp == head) {
				head = tmp->next;
			}
			else {
				prev->next = tmp->next;
			}
			if (tmp == tail) {
				tail = prev;
			}*/
			//----------------------------------
			if (tmp->prev != nullptr) {
				tmp->prev->next = tmp->next;
			}
			if (tmp->next != nullptr) {
				tmp->next->prev = tmp->prev;
			}
			if (tmp == head) {
				head = tmp->next;
			}
			if (tmp == tail) {
				tail = tmp->prev;
			}
			//----------------------------------
			delete tmp;
			return true;
		}
		tmp = tmp->next;
	}
	return false;
}

void LinkedList::display(ostream& os) {//mp change
	Nodee* tmp = head;
	while (tmp != nullptr) {
		os << tmp->data << " ";
		tmp = tmp->next;
	}
	os << endl;
}

//------------------additional ones----------------------------
bool LinkedList::tailRemove(int data) {
	Nodee* tmp = tail;
	//Node* prev = nullptr;

	while (tmp != nullptr) {
		if (tmp->data == data) {
			/*if (tmp == head) {
				head = tmp->next;
			}
			else {
				prev->next = tmp->next;
			}
			if (tmp == tail) {
				tail = prev;
			}*/
			//----------------------------------
			if (tmp->prev != nullptr) {
				tmp->prev->next = tmp->next;
			}
			if (tmp->next != nullptr) {
				tmp->next->prev = tmp->prev;
			}
			if (tmp == head) {
				head = tmp->next;
			}
			if (tmp == tail) {
				tail = tmp->prev;
			}
			//----------------------------------
			delete tmp;
			return true;
		}
		tmp = tmp->prev;
	}
	return false;
}

void LinkedList::tailDisplay(ostream& os) {
	Nodee* tmp = tail;
	while (tmp != nullptr) {
		os << tmp->data << " ";
		tmp = tmp->prev;
	}
	os << endl;
}

ostream& operator<<(ostream& os, LinkedList& right) {
	right.display(os);
	return os;
}