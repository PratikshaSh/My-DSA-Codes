//O(nlogn) time
// print nodes in same vertical order as they appear in tree.

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
void getVerticalOrderBetter(Node *root, long long int hd,long long int vd, map<long long int,vector<int>>&m)
{
    if(root==NULL)
    return;
    
    long long val = hd<<30 | vd;
    m[val].push_back(root->data);

    getVerticalOrderBetter(root->left,hd-1,vd+1,m);
    getVerticalOrderBetter(root->right,hd+1,vd+1,m);
}

void printVerticalOrder(Node* root){
    map<long long int, vector<int>>m;
    int hd = 0;
    int vd = 1;
    getVerticalOrderBetter(root,hd,vd,m);

    int prekey = INT_MAX;
    map<long long int,vector<int>> :: iterator it;
    for(it=m.begin(); it!=m.end(); it++){
        if(prekey != INT_MAX and(it->first>>30)!=prekey){
            cout<<endl;
        }
        prekey = it->first>>30;
        for(int i=0;i<it->second.size(); ++i)
          cout<<it->second[i]<<" ";
        
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
