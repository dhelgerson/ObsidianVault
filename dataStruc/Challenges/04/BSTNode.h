class BSTNode{
    // here we define the basic legos of the data structure. these will be dynamically allocated
    // by our next class
    public:
        int data;
        BSTNode *left;
        BSTNode *right;

        BSTNode():data(0),left(nullptr){};
        BSTNode(int data):data(data),left(nullptr){};
        BSTNode(int data,BSTNode *leftNode):data(data),left(leftNode){};
        
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

