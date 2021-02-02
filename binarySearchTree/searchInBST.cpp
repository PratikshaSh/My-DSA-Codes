#include<iostream>
#include "NodeClass.h"
#include<queue>
using namespace std;

bool searchBST(Node *root, int data){
    if(root == NULL)
     return false;
    if(root->data == data)
     return true;

    if(data> root->data){
        return searchBST(root->right,data);

    }  
    else{
        return searchBST(root->left,data);
    }
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
if(searchBST(root,11)){
 cout<<"true";
}
else
{
    cout<<"false";
}


}