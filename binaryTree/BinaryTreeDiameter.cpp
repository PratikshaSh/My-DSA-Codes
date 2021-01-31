#include<iostream>
#include "binaryTreeNode.h"
#include<queue>

using namespace std;


int height(BinaryTreeNode<int>* root){
    if(root ==NULL)
    return 0;
    
    return 1+ max(height(root->left), height(root->right));
}

//O(n^2) TC
int diameter(BinaryTreeNode<int>* root){
    if(root == NULL)
    return 0;

    int lh= height(root->left);
    int rh= height(root->right);
    int op1= lh+rh;
    int op2= diameter(root->left);
    int op3= diameter(root->right);
    return max(op1, max(op2,op3));
}

//O(n) TC
pair<int,int> fastDiameter(BinaryTreeNode<int>* root){
    pair<int,int>p;
    // first= height
    // second= dia
    if(root==NULL){
        p.first=p.second=0;
        return p;
    }

    pair<int,int> leftans = fastDiameter(root->left);
    pair<int,int> rightans = fastDiameter(root->right);
    p.first = 1+ max(leftans.first,rightans.first);
    p.second = max(leftans.first+rightans.first, max(leftans.second, rightans.second));

    return p;
}


BinaryTreeNode<int>* takeInputLevelWise(){
    int rootData;
    cout<<"Enter data" <<endl;
    cin>>rootData;
    if(rootData == -1){
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);

    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size() != 0){
        BinaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout<<"Enter left chile of"<< front->data<<endl;
        int leftChildData;
        cin>>leftChildData;
        if(leftChildData != -1){
            BinaryTreeNode<int>* child = new BinaryTreeNode<int>(leftChildData);
            front->left=child;
            pendingNodes.push(child);
        }
        cout<<"Enter right chile of"<< front->data<<endl;
        int rightChildData;
        cin>>rightChildData;
        if(rightChildData != -1){
            BinaryTreeNode<int>* child = new BinaryTreeNode<int>(rightChildData);
            front->right=child;
            pendingNodes.push(child);
        }
    }
    return root;
}

pair<int,int> heightDiameter(BinaryTreeNode<int>* root ){
    if(root == NULL){
        pair<int,int> p;
        p.first=0;
        p.second=0;
        return p;
    }
    pair<int,int> leftAns= heightDiameter(root->left);
    pair<int,int>rightAns= heightDiameter(root->right);
    int ld =leftAns.second;
    int lh = leftAns.first;
    int rd = rightAns.second;
    int rh = rightAns.first;

    int height = 1+ max(lh,rh);
    int diameter = max(lh+rh, max(ld,rd));
    pair<int,int> p;
    p.first = height;
    p.second = diameter;
    return p;


}
int main(){
    BinaryTreeNode<int>* root= takeInputLevelWise();
    cout<<"diameter: "<<diameter(root)<<endl;
    pair<int,int> pa = fastDiameter(root);
    cout<<"fast dia "<<pa.second<<endl;
    pair<int,int> p= heightDiameter(root);
    cout<<"Height"<<p.first<<endl;
    cout<<"Diameter"<<p.second<<endl;

}