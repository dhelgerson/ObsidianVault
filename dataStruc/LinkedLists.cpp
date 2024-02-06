/*
Jan 30, 2024 Data Structures Notes
Drew Helgerson - tah568
*/

/*
    linked lists require the following operations:
    - insertion: 
        many lists contain both an append and prepend function
        append: stick a new Node at the end
        prepend: stick a new Node at the beginning.
    - search:
    - delete:
    - display:
*/


#include <iostream>

using namespace std;

class LinkedList {
    private:
        int *head = NULL;
        int *tail = NULL;
        int *ptr = NULL;
    public:
        void append();
        void prepend();
        int search();

};

void LinkedList::append(){
    // append operation adds to the end of the list
    // 1. create a new Node and set its data members to the data being stored
    Node *tmp = new Node(data);
    // 2. set the tail's next pointer to the newly created Node
    Node *tail = Null;
    // 3. cleanup after ourselves by setting the tail to the newly created Node
    tail = tmp;
}

void LinkedList::append(){
    Node *tmp = new Node(data);
    if (head == nullptr){
        head = tmp;
    }
    else {
        tail->next = tmp;
    }
    tail = tmp;
}

int main(){

    cout << "Hello world" << endl;

    return 0;
}