//O(nh) TC --- bad

#include<iostream>
#include "NodeClass.h"
#include<queue>
using namespace std;

int minimum(Node* root){
    if(root == NULL){
        return INT_MAX;
    }
    return min(root->data,min(minimum(root->left),minimum(root->right)));
}
int maximum(Node* root){
    if(root ==NULL)
    return INT_MIN;

    return max(root->data,max(maximum(root->left), maximum(root->right)));
}
//O(nh) TC --- bad
bool isBST(Node* root){
    if(root == NULL)
     return true;

    int leftMax = maximum(root->left);
    int rightMin = minimum(root->right);

   bool output = (leftMax<root->data) and (rightMin>=root->data) and isBST(root->left) and isBST(root->right);
   return output; 
}


int main(){
    Node *root = new Node(5);
    root->left = new Node(10);
    root->right = new Node(6);
    cout<<isBST(root);
}