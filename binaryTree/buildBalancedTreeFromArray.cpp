#include<iostream>
#include "binaryTreeNode.h"
#include<queue>
using namespace std;


BinaryTreeNode<int>* buildTreeFromArray(int *a, int s, int e){
    //base case
    if(s>e)
    return NULL;

    //rec case
    int mid= (s+e )/2;
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(a[mid]);
    root->left = buildTreeFromArray(a,s,mid-1);
    root->right = buildTreeFromArray(a,mid+1,e);
    return root;
}
void bfs(BinaryTreeNode<int>* root){
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        BinaryTreeNode<int>* f = q.front();
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
    int a[]={1,2,3,4,5,6,7};
    int n = 7;
    BinaryTreeNode<int>* root = buildTreeFromArray(a,0,n-1);
    bfs(root);
}