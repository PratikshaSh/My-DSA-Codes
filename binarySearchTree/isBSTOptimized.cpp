//OPTIMIZED
//O(n) time

#include<iostream>
#include "NodeClass.h"
#include<queue>
using namespace std;

class IsBSTReturn{
    public:
    bool isBST;
    int mini;
    int maxi;
};

IsBSTReturn isBST2(Node* root){
    if(root == NULL)
    {
        IsBSTReturn output;
        output.isBST=true;
        output.mini = INT_MAX;
        output.maxi = INT_MIN;
        return output;
    }
    
    IsBSTReturn leftOutput = isBST2(root->left);
    IsBSTReturn rightOutput = isBST2(root->right);

    int minimum = min(root->data, min(leftOutput.mini , rightOutput.mini));

    int maximum =max(root->data , max( leftOutput.maxi , rightOutput.maxi));
    bool isBSTFinal = (root->data >= leftOutput.maxi)&&(root->data<rightOutput.mini)&& leftOutput.isBST && rightOutput.isBST;
    IsBSTReturn output;
    
    output.mini = minimum;
    output.maxi = maximum;
    output.isBST = isBSTFinal;
    return output;

}
//==========
//OR
bool isBST3(Node* root, int minV = INT_MIN , int maxV=INT_MAX){
    if(root==NULL)
     return true;

    if(root->data>=minV and root->data < maxV and isBST3(root->left,minV,root->data) and isBST3(root->right,root->data,maxV)) {
        return true;
    }
    return false;
}



int main(){
    Node *root = new Node(5);
    root->left = new Node(10);
    root->right = new Node(6);
    IsBSTReturn res= isBST2(root);
    cout<<res.isBST<<endl;
    cout<<isBST3(root);

}