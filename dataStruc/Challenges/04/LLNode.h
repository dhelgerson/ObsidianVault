class LLNode{
    // here we define the basic legos of the data structure. these will be dynamically allocated
    // by our next class
    public:
        int payload;
        LLNode *next;

        LLNode():payload(0),next(nullptr){};
        LLNode(int data):payload(data),next(nullptr){};
        LLNode(int data,LLNode *nextNode):payload(data),next(nextNode){};
        void cascade(){
            if (next != nullptr){
                next->cascade();
                delete next;
            }
        }
};