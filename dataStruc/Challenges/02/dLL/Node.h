class Node{
    // here we define the basic legos of the data structure. these will be dynamically allocated
    // by our next class
    public:
        int payload;
        Node *next;
        Node *prev;

        Node():payload(0),next(nullptr),prev(nullptr){};
        Node(int data):payload(data),next(nullptr),prev(nullptr){};
        Node(int data,Node *nextNode):payload(data),next(nextNode),prev(nullptr){};
        Node(int data,Node *nextNode,Node *prevNode):payload(data),next(nextNode),prev(prevNode){};
        void cascade(){
            if (next != nullptr){
                next->cascade();
                delete next;
            }
        }
};