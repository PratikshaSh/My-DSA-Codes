#include<iostream>
#include "binaryTreeNode.h"
#include<stack>
using namespace std;

void inorderIterative(BinaryTreeNode<int> *root){
    stack<BinaryTreeNode<int>*>stk;
    BinaryTreeNode<int> * curr = root;
    while(!stk.empty() or curr != NULL){
        if(curr != NULL){
            stk.push(curr);
            curr=curr->left;
        }
        else{
            curr = stk.top();
            stk.pop();
            cout<<curr->data<<" ";
            curr=curr->right;
        }

    }

}