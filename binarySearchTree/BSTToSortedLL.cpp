#include<bits/stdc++.h>
#include "NodeClass.h"
using namespace std;

class LL{
    public: Node* head;
    Node* tail;
};

LL flattenBST(Node* root){
    LL l;
    if(root==NULL){
      l.head=l.tail = NULL;
      return l;
    }
    // leaf node
    if(root->left ==NULL and root->right == NULL){
        l.head = l.tail = root;
        return l;
    }
    //left is not NULL
    if(root->left != NULL and root->right == NULL){
        LL leftAns = flattenBST(root->left);
        leftAns.tail ->right = root;
        l.head = leftAns.head;
        l.tail = root;
        return l;
    }
    // right is not NULL
    if(root->left == NULL and root->right != NULL){
        LL rightAns = flattenBST(root->right);
        root->right = rightAns.head;
        l.head = root;
        l.tail = rightAns.tail;
        return l;
    }
    //both are not NULL
    LL leftAns = flattenBST(root->left);
    LL rightAns = flattenBST(root->right);
    leftAns.tail->right = root;
    root->right= rightAns.head;
    l.head = leftAns.head;
    l.tail = rightAns.tail;
    return l;
}

int main(){
    
    Node* root = new Node(5); 
    root->left = new Node(3); 
    root->right = new Node(7); 
    root->left->left = new Node(2); 
    root->left->right = new Node(4); 
    root->right->left = new Node(6); 
    root->right->right = new Node(8); 
  
    // Calling required function 
    LL temp =flattenBST(root); 
    Node* headd = temp.head;
    while(headd != NULL){
        cout<<headd->data<<"->";
        headd = headd->right;
    }
    
  
    return 0; 
}