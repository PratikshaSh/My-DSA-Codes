class Node{
    public:
    int data;
    Node* left;
    Node* right;


    Node(int d){
        this->data = d;
        left = NULL;
        right = NULL;
    }
};