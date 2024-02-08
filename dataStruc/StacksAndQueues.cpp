#include <iostream>

using namespace std;

// codium notes for stacks and queues
// stacks are akin to loading a pez dispenser 1 * 1
// stacks are a last-in first-out (LIFO)
// you only ever interact w/ the one on top
// stacks can be implemented with various data models. linked lists work well and will
// be used in this case.

#include "Node.h"
class Stack{
    // here's where we do the real work, we dynamically allocate nodes and keep track of them w/ pointers
    private:
        Node *top = nullptr;
    public:
        Stack(){}
        ~Stack(){}
        void push (){}
        void push(int payload){}
        int pop(){}
        int peak(){}
};

Stack::Stack(){
    // here we need to initialize our top and any other housekeeping
}

Stack::~Stack(){
    Node *tmp = nullptr;
    while (top != nullptr){
        tmp = top;
        top = top->next;
        delete tmp;
    }
    // this would better be a recursive function
}

int Stack::pop(){
    // here we need to:
    Node *tmp = top; // keep track of the current top
    int data = tmp->payload; // store the payload for returning
    top = tmp->next; // assign the next node as the top, getting ready for the current one to be removed
    delete tmp; // remove the current top, preventing memory leak
    return data; // return the data
}

int Stack::peak(){
    return top->payload;
}

int main(){

        

    return 0;
}