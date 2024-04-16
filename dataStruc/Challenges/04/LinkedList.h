#include "LLNode.h"
#include <iostream>

class LinkedList{
    private:
        LLNode *head;
        LLNode *tail;
        int len;
    public:
        LinkedList():head(nullptr),tail(nullptr){}
        ~LinkedList();

        void prepend(int payload);
        void append(int payload);
        void remove(int match);
        void display(std::ostream &output);
        bool search(int key);
        void tailDisplay(std::ostream &output);
        void tailRemove(int match);
};

LinkedList::~LinkedList(){
    head->cascade();
    delete head;
}
void LinkedList::prepend(int payload){
    if (head == nullptr){
        head = new LLNode(payload);
        tail = head;
    }
    else{
        LLNode *tmp = head;
        head = new LLNode(payload);
        head->next = tmp;
    }
}
void LinkedList::append(int payload){
    if (head == nullptr){
        head = new LLNode(payload);
        tail = head;
    }
    else {
        LLNode *tmp = tail;
        tail = new LLNode(payload);
        tmp->next = tail;
    }
}
void LinkedList::display(std::ostream &output){
    LLNode *tmp = head;
    while (tmp) {
        output << tmp->payload << ' ';
        tmp = tmp->next;
    }
    output << std::endl;
}
bool LinkedList::search(int key){
    LLNode *tmp = head;
    while (tmp){
        if (tmp->payload == key){
            return true;
        }
        else{
            tmp = tmp->next;
        }
    }
    return false;
}
void LinkedList::remove(int key){
    LLNode *tmp = head;
    LLNode *prev;
    while (tmp){
        if (tmp->payload == key){
            break;
        }
        else {
            prev = tmp;
            tmp = tmp->next;
        }
    }
    if (tmp){
        prev->next = tmp->next;
        delete tmp;
    }
}
