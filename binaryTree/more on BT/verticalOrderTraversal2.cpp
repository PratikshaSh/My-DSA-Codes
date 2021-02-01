//O(nlogn) time
//solution may not print nodes in same vertical order as they appear in tree.

#include<bits/stdc++.h>
using namespace std;

struct Node
{
   int data;
   struct Node* left;
   struct Node* right;
   
};
Node* newNode(int data){
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
void getVerticalOrder(Node *root, int hd, map<int,vector<int>>&m)
{
    if(root==NULL)
    return;

    m[hd].push_back(root->data);

    getVerticalOrder(root->left,hd-1,m);
    getVerticalOrder(root->right,hd+1,m);
}

void printVerticalOrder(Node* root){
    map<int, vector<int>>m;
    int hd = 0;
    getVerticalOrder(root,hd,m);

    map<int,vector<int>> :: iterator it;
    for(it=m.begin(); it!=m.end(); it++){
        for(int i=0;i<it->second.size(); ++i)
          cout<<it->second[i]<<" ";
        cout<<endl;
    }
}


int main(){
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right= newNode(7);
    root->right->left->right = newNode(8);
    root->right->right->right= newNode(9);

    printVerticalOrder(root);
return 0;
}
