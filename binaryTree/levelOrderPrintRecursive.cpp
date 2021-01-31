//O(n^2) worst case time complexity
#include<iostream>
#include "binaryTreeNode.h"
#include<queue>
using namespace std;

int height(BinaryTreeNode<int>* root){
    if(root == NULL)
     return 0;
    return 1 + max(height(root->left),height(root->right)); 
}

void printAtLevelK(BinaryTreeNode<int>* root, int k){
    if(root == NULL){
        return;
    }
    if(k==1){
        cout<<root->data<<" ";
        return;
    }
    printAtLevelK(root->left,k-1);
    printAtLevelK(root->right, k-1);
    return;
}

void printAllLevels(BinaryTreeNode<int>* root){
    int H = height(root);
    
    for(int i=1;i<=H;i++){
        printAtLevelK(root,i);
        cout<<endl;
    }
}

///// to take input

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
//// to print tree
void printTree(BinaryTreeNode<int>* root){
    if(root == NULL)
     return;
    cout<< root->data<<":";
    if(root->left != NULL)
     cout<<"L"<< root->left->data;

    if(root->right != NULL)
     cout<<"R"<< root->right->data; 
     cout<<endl;
    printTree(root->left);
    printTree(root->right);
}



int main(){
    BinaryTreeNode<int>* root= takeInputLevelWise();
    printTree(root);
    cout<<endl; 
    printAllLevels(root);
}