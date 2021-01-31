//BFS = L,root,R (here)
//DFS = R,root,L 

#include<iostream>
#include "binaryTreeNode.h"
#include<queue>
using namespace std;


void printRightView(BinaryTreeNode<int>* root, int level,int& maxLevel){
    if(root == NULL){
        return;
    }

    if(maxLevel < level){
        //dicovered a new level
        cout<<root->data<<" ";
        maxLevel = level;
    }

//left
printRightView(root->left , level+1, maxLevel);
//right
printRightView(root->right , level+1, maxLevel);

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
BinaryTreeNode<int>* root = takeInputLevelWise();
int level=0;
cout<<root->data<<" ";
printRightView(root,0,level);
}