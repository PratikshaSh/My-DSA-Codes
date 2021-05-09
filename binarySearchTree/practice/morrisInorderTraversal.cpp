#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;
/* A binary tree tNode has data, a pointer to left child
and a pointer to right child */
struct tNode {
	int data;
	struct tNode* left;
	struct tNode* right;
};

/* Function to traverse the binary tree without recursion
and without stack */
void MorrisTraversal(struct tNode* root)
{	if(root==NULL) return;
	tNode* cur = root;
	tNode* predecessor;
    while(cur != NULL){
        if(cur->left == NULL){
            cout<<cur->data<<",";
			cur = cur->right;
        }
        else{
            predecessor = cur->left;
            while(predecessor->right != NULL and predecessor->right != cur){
                predecessor = predecessor->right;
            }

            if(predecessor->right == NULL){
            predecessor->right = cur;
            cur = cur->left;
            }
            else{
                predecessor->right == NULL;
                cout<<cur->data<<",";
                cur = cur -> right;
            }
        }
    }
		
}

/* UTILITY FUNCTIONS */
/* Helper function that allocates a new tNode with the
given data and NULL left and right pointers. */
struct tNode* newtNode(int data)
{
	struct tNode* node = new tNode;
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return (node);
}

/* Driver program to test above functions*/
int main()
{

	/* Constructed binary tree is
			1
		/ \
		2	 3
	/ \
	4	 5
*/
	struct tNode* root = newtNode(1);
	root->left = newtNode(2);
	root->right = newtNode(3);
	root->left->left = newtNode(4);
	root->left->right = newtNode(5);

	MorrisTraversal(root);

	return 0;
}
