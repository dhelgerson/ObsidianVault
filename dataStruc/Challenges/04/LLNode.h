class Node{
    // here we define the basic legos of the data structure. these will be dynamically allocated
    // by our next class
    public:
        int payload;
        Node *next;

        Node():payload(0),next(nullptr){};
        Node(int data):payload(data),next(nullptr){};
        Node(int data,Node *nextNode):payload(data),next(nextNode){};
        void cascade(){
            if (next != nullptr){
                next->cascade();
                delete next;
            }
        }
};