//O(n*w)TC , w is width of BT
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
void findMinMax(Node *node, int *min, int*max,int hd){
    if(node==NULL)
     return;

    if(hd<*min) *min=hd;
    else if(hd>*max) *max=hd;
    findMinMax(node->left,min,max,hd-1);
    findMinMax(node->right,min,max,hd+1);
}

void printVerticalLine(Node* node, int line,int hd){
    if(node==NULL)
    return;
    if(hd==line)
     cout<<node->data<<" ";

    printVerticalLine(node->left,line,hd-1) ;
    printVerticalLine(node->right,line,hd+1);
}
void verticalOrder(Node* root){
    int min=0, max=0;
    findMinMax(root,&min,&max,0);

    for(int line=min; line<=max ; line++){
        printVerticalLine(root,line,0);
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

    verticalOrder(root);
return 0;
}
