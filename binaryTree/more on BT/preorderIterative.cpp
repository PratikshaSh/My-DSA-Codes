#include<iostream>
#include "binaryTreeNode.h"
#include<stack>
using namespace std;

void preorderIterative(BinaryTreeNode<int> *root){
    if(root==NULL)
     return;
    stack<BinaryTreeNode<int>*>stk;
    stk.push(root);
    while(!stk.empty() ){
        BinaryTreeNode<int> * curr = root;
        stk.pop();
        cout<<curr->data<<" ";
        if(curr->right)
         stk.push(curr->right);
        if(curr->left) 
         stk.push(curr->left);
         // the right child must be pushed first so that the left child
        // is processed first (FIFO order)

    }

}