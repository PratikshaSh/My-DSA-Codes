//Accepts the old root node and data , and return the new root node
#include<iostream>
#include "NodeClass.h"
#include<queue>
using namespace std;

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


//read a list of numbers till -1 and also these no.s will be inserted into BST
Node* Build(){
    int d;
    cin>>d;
    Node* root =NULL;
    while(d != -1){
        root = insertInBST(root,d);
        cin>>d;
    }
    return root;
}

void inorder(Node* root){
    if(root == NULL)
    return ;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void bfs(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* f = q.front();
        if(f == NULL){
            cout<<endl;
            q.pop();
            if(!q.empty())
             q.push(NULL);

        }
        else{
            cout<<f->data<<",";
            q.pop();
            if(f->left)
            q.push(f->left);

            if(f->right)
            q.push(f->right);
        }
    }
}



int main(){
    
    Node *root = Build();
    inorder(root); //sorted for BST
    cout<<endl;
    bfs(root);
 

    return 0;
}
