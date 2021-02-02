//O(n) TC, where n is the total number of keys in tree

#include<iostream>
#include "NodeClass.h"
#include<queue>
using namespace std;
// inorder traversal as it is will print keys in sorted order
void printInRange(Node* root, int k1, int k2){
    if(root == NULL)
     return;

    if(k1<root->data) 
     printInRange(root->left,k1,k2);

    if(k1<= root->data and k2>=root->data) 
     cout<<root->data<<" ";

     if(k2>root->data)
     printInRange(root->right,k1,k2);
}

Node* insertInBST(Node *root, int data){
 //Base case
 if(root==NULL){
    
     return new Node(data);
 }
 //Rec case- insert in subtree and update point
 if(data > root->data){
     root->right = insertInBST(root->right,data);

    }
 else
 {
     root->left = insertInBST(root->left,data);

 }
     
 return root;
}

int main(){
    Node* root = insertInBST(root,5);
    insertInBST(root,3);
    insertInBST(root,1);
    insertInBST(root,7);
    insertInBST(root,6);
    insertInBST(root,8);
    printInRange(root, 2,7);
} 