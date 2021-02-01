#include<iostream>
#include "binaryTreeNode.h"
#include<stack>
using namespace std;

void postorderIterative(BinaryTreeNode<int> *root){
    if(root==NULL)
     return;
    stack<BinaryTreeNode<int>*>stk;
    stk.push(root);
    // create another stack to store postorder traversal
    stack<int>out;

    while(!stk.empty() ){
        BinaryTreeNode<int> * curr = stk.top();
        stk.pop();
        out.push(curr->data);

        if(curr->right)
         stk.push(curr->right);
        if(curr->left) 
         stk.push(curr->left);
        

    }
    while(!out.empty()){
        cout<<out.top()<<" ";
        out.pop();
    }

}