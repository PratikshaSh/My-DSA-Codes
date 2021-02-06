
#include<bits/stdc++.h>
#include "NodeClass.h"
#include "binaryTreeNode.h"
using namespace std;


vector<int>* getRootToNodePath(BinaryTreeNode<int>* root, int data){
    if(root == NULL)
    return NULL;

    if(root->data == data){
        vector<int>* output = new vector<int>();
        output->push_back(root->data);
        return output;
    }

    vector<int>* leftOutput = getRootToNodePath(root->left,data);
    if(leftOutput != NULL){
        leftOutput->push_back(root->data);
        return leftOutput;

    }
    vector<int>* rightOutput = getRootToNodePath(root->right,data);
    if(rightOutput != NULL){
        rightOutput-> push_back(root->data);
        return rightOutput;
    }
    else{
        return NULL;
    }
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
    // Node* root = insertInBST(root,5);
    // insertInBST(root,3);
    // insertInBST(root,1);
    // insertInBST(root,7);
    // insertInBST(root,6);
    // insertInBST(root,8);
    // //get(root, 2,7);
     BinaryTreeNode<int>* root = takeInputLevelWise();
    
    vector<int>* output = getRootToNodePath(root,8);
    for(int i=0;i<output->size(); i++){
        cout<<output->at(i)<<endl;
    }
    
  
} 