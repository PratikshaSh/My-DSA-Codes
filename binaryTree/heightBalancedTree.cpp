//abs(left.height- right.height)<=1 at every node
//recursive

#include<iostream>
#include "binaryTreeNode.h"
#include<queue>
using namespace std;

class HBPair{
    public:
    int height;
    bool balance;
};

HBPair isHeightBalanced( BinaryTreeNode<int>* root ){
    HBPair p;
    if(root == NULL){
        p.height = 0;
        p.balance = true;
        return p;
    }
    // recursive case

    HBPair left = isHeightBalanced(root->left);
    HBPair right = isHeightBalanced(root->right);

    p.height = max(left.height , right.height) +1;
    if(abs(left.height- right.height)<=1 and left.balance and right.balance){
        p.balance = true;
    }
    else{
        p.balance = false;
    }
    return p;
}

BinaryTreeNode<int>* takeInputLevelWise(){
    int rootData;
    cout<<"Enter data" <<endl;
    cin>>rootData;
    if(rootData == -1){
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);

    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size() != 0){
        BinaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout<<"Enter left chile of"<< front->data<<endl;
        int leftChildData;
        cin>>leftChildData;
        if(leftChildData != -1){
            BinaryTreeNode<int>* child = new BinaryTreeNode<int>(leftChildData);
            front->left=child;
            pendingNodes.push(child);
        }
        cout<<"Enter right chile of"<< front->data<<endl;
        int rightChildData;
        cin>>rightChildData;
        if(rightChildData != -1){
            BinaryTreeNode<int>* child = new BinaryTreeNode<int>(rightChildData);
            front->right=child;
            pendingNodes.push(child);
        }
    }
    return root;
}

int main(){

    BinaryTreeNode<int>* root= takeInputLevelWise();
    if(isHeightBalanced(root).balance){
        cout<<"Balanced";
       
    }
     else{
            cout<<"not balanced";
        }
}