// C++ program to find maximum sum from a subset of
// nodes of binary tree
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node structure */
struct node
{
	int data;
	struct node *left, *right;
};

/* Utility function to create a new Binary Tree node */
struct node* newNode(int data)
{
	struct node *temp = new struct node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

unordered_map<node*,int> mp;

int getMaxSum(node* root)
{
	if(root == NULL) return 0;

    if(mp.find(root) != mp.end())
    return mp[root];

    int inc = root->data;


   if(root->left)
    inc += getMaxSum(root->left->left) + getMaxSum(root->left->right);
   if(root->right) 
    inc += getMaxSum(root->right->left)+ getMaxSum(root->right->right);

    int exc = getMaxSum(root->left)+ getMaxSum(root->right);

    return mp[root] = max(inc, exc);
}


int main()
{
	node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->right->left = newNode(4);
	root->right->right = newNode(5);
	root->left->left = newNode(1);

	cout << getMaxSum(root) << endl;
	return 0;
}
