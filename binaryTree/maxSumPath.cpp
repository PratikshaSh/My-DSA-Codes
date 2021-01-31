#include<iostream>
#include "binaryTreeNode.h"
#include<queue>

using namespace std;

class Pair{
    public:
    int branchSum;
    int maxSum;
    Pair(){
        maxSum =0;
        branchSum=0;
    }
};
Pair maxSumPath(BinaryTreeNode<int>* root){
    Pair p;
    if(root==NULL){
        return p;
    }
    Pair left = maxSumPath(root->left);
    Pair right = maxSumPath(root->right);

    int op1= root->data;
    int op2= left.branchSum + root->data;
    int op3= right.branchSum + root->data;
    int op4= left.branchSum + root->data + right.branchSum;

    int ans_thru_root = max(op1, max(op2,max(op3,op4)));
    p.branchSum = max(left.branchSum, max(right.branchSum,0))+root->data;
    p.maxSum = max(left.maxSum, max(right.maxSum,ans_thru_root));
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
    Pair p = maxSumPath(root);
    cout<<"branch sum:"<<p.branchSum<<endl;
    cout<<"max sum:"<<p.maxSum;
}