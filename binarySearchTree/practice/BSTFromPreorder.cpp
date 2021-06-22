/* A O(n^2) program for construction of BST from preorder
* traversal */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
and a pointer to right child */
class node {
public:
	int data;
	node* left;
	node* right;
};

// A utility function to create a node
node* newNode(int data)
{
	node* temp = new node();

	temp->data = data;
	temp->left = temp->right = NULL;

	return temp;
}
node* solve(int pre[],int s, int e){
    if(s>e) return NULL;
    node* root = newNode(pre[s]);
    if (s == e)
        return root;
 
    int i;
    for(i=s+1; i<=e; i++){
        if(pre[i] > root->data){
            break;
        }
    }
    root->left = solve(pre, s+1, i-1);
    root->right = solve(pre, i, e);

    return root;
}

node* constructTree(int pre[], int n){
    return solve(pre, 0, n-1);
}



void printInorder(node* node)
{
	if (node == NULL)
		return;
	printInorder(node->left);
	cout << node->data << " ";
	printInorder(node->right);
}

// Driver code
int main()
{
	int pre[] = { 10, 5, 1, 7, 40, 50 };
	int size = sizeof(pre) / sizeof(pre[0]);

	node* root = constructTree(pre, size);

	cout << "Inorder traversal of the constructed tree: \n";
	printInorder(root);

	return 0;
}

// This code is contributed by rathbhupendra
