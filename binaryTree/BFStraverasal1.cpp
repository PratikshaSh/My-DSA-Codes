//O(n) TC
// iterative

//bfs= breadth first search
//pop
//print
//push child
// output in single line

#include<iostream>
#include "binaryTreeNode.h"
#include<queue>

using namespace std;
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
void bfs(BinaryTreeNode<int>* root){
    queue<BinaryTreeNode<int>*> q;
    q.push(root);

    while(!q.empty()){
        BinaryTreeNode<int>* f = q.front();
        cout<<f->data<<",";
        q.pop();

        if(f->left)
        q.push(f->left);

        if(f->right)
        q.push(f->right);
    }
    return;
}

int main(){
    
    BinaryTreeNode<int>* root= takeInputLevelWise();
    bfs(root);
}