//assumption : both a and b are present in the tree and all keys are unique

#include<iostream>
#include "binaryTreeNode.h"
#include<queue>
using namespace std;

BinaryTreeNode<int>* lca(BinaryTreeNode<int>* root, int a, int b){
    if(root == NULL){
        return NULL;
    }
    if(root->data == a or root->data == b){
        return root;
    }
    BinaryTreeNode<int>* leftans = lca(root->left,a,b);
    BinaryTreeNode<int>* rightans = lca(root->right,a,b);
    if(leftans != NULL and rightans != NULL){
        return root;
    }
    if(leftans != NULL){
        return leftans;
    }
    return rightans;
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

int main()
{
    BinaryTreeNode<int>* root = takeInputLevelWise();
    BinaryTreeNode<int>* ans = lca(root,10,9);
    cout<<ans->data;
}