#include <iostream>

using namespace std;

// codium notes for stacks and queues
// stacks are akin to loading a pez dispenser 1 * 1
// stacks are a last-in first-out (LIFO)
// you only ever interact w/ the one on top
// stacks can be implemented with various data models. linked lists work well and will
// be used in this case.

class Node{
    // here we define the basic legos of the data structure. these will be dynamically allocated
    // by our next class
    public:
        int payload;
        Node *next;

        Node(): payload(0),next(nullptr) {}
        Node(int payload):payload(payload),next(nullptr) {}
        Node(int payload,Node *next):payload(payload), next(next) {}
};

class Stack{
    // here's where we do the real work, we dynamically allocate nodes and keep track of them w/ pointers
    private:
        Node *head = nullptr;
    public:
        Stack(){}
        void push (){}
        void push(int payload){}
        int pop(){}
};

int main(){

    
    

    return 0;
}