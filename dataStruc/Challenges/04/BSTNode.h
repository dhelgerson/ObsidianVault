class Node{
    // here we define the basic legos of the data structure. these will be dynamically allocated
    // by our next class
    public:
        int data;
        Node *left;
        Node *right;

        Node():data(0),left(nullptr){};
        Node(int data):data(data),left(nullptr){};
        Node(int data,Node *leftNode):data(data),left(leftNode){};
        
        void cascade(){
            if (left != nullptr){
                left->cascade();
                delete left;
            }
            if (right != nullptr){
                right->cascade();
                delete right;
            }
        }
};

