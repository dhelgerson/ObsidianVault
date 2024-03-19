#include "Node.h"

#include <iostream>

class Stack{
    private:
        Node *head;
        Node *tail;
        int len;
    public:
        Stack():head(nullptr),tail(nullptr){}
        ~Stack();

        void push(int payload);
        int peek(int &output);
        int pop();
        // void append(int payload);
        void display(std::ostream &output);
};

Stack::~Stack(){
    head->cascade();
    delete head;
}
void Stack::push(int payload){
    if (head == nullptr){
        head = new Node(payload);
        tail = head;
    }
    else{
        Node *tmp = head;
        head = new Node(payload);
        head->next = tmp;
    }
}
int Stack::peek(int &output){
    if (head){
        output = head->payload;
        return 1;
    }
    else {
        return 0;
    }
}

int Stack::pop(){
    Node *tmp = head;
    if (head){
        head = head->next;
        delete tmp;
        return 1;
    }
    else {
        return 0;
    }
}


// For Queues

// void Stack::push(int payload){
//     if (head == nullptr){
//         head = new Node(payload);
//         tail = head;
//     }
//     else {
//         Node *tmp = tail;
//         tail = new Node(payload);
//         tmp->next = tail;
//     }
// }

void Stack::display(std::ostream &output){
    Node *tmp = head;
    while (tmp) {
        output << tmp->payload << ' ';
        tmp = tmp->next;
    }
    output << std::endl;
}