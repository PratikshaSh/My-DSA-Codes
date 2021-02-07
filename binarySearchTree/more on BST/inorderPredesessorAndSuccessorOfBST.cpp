//Inorder Predecessor of given key
//case 1 - left subtree is present = go root->left and then go right till NULL
//case2 - left subtree of key node is absent = Inorder pred will be the node from 
// from where we took the last right turn
//case 1
// if(key->left != NULL){
//     temp = root->left;
//     while(temp->right != NULL){
//         temp = temp ->left;
//     }
//     return temp->data;
// }

// //case2
// while(  key->data != root->data){
//     if(key->data >root->data){
//         int store = root->data;
//         root= root->right;
//     }else{
//         root=root->left;
//     }
//     return store; 
// }

// // inorder succesor of key node in BST
// //case1 ; right subtree is present = go left RRRRR.. till NULL
//  if(key->right = NUll){
//      temp= key->right;
//      while(temp->left!=NULL)
//      temp = temp->left;

//      return temp->data;
//  }

//  //case2 - if right sub tree is absent
//  // search key from root to the node from where wetook the last left is the answerj
//  //'

//  s= root;
//  while(s->data==key->data)
//  {
//      if( p->data <=s->data)
//      {
//          int store = s->data;
//          s=s->left;
//      }
//      else s=s->right;

//      return store;
//  }
// Input: root node, key
// output: predecessor node, successor node

// 1. If root is NULL
//       then return
// 2. if key is found then
//     a. If its left subtree is not null
//         Then predecessor will be the right most 
//         child of left subtree or left child itself.
//     b. If its right subtree is not null
//         The successor will be the left most child 
//         of right subtree or right child itself.
//     return
// 3. If key is smaller then root node
//         set the successor as root
//         search recursively into left subtree
//     else
//         set the predecessor as root
//         search recursively into right subtree




//Final Code
#include<iostream>

using namespace std;

// C++ program to find predecessor and successor in a BST 
#include <iostream> 
using namespace std; 

// BST Node 
struct Node 
{ 
	int key; 
	struct Node *left, *right; 
}; 

// This function finds predecessor and successor of key in BST. 
// It sets pre and suc as predecessor and successor respectively 
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key) 
{ 
	// Base case 
	if (root == NULL) return ; 

	// If key is present at root 
	if (root->key == key) 
	{ 
		// the maximum value in left subtree is predecessor 
		if (root->left != NULL) 
		{ 
			Node* tmp = root->left; 
			while (tmp->right) 
				tmp = tmp->right; 
			pre = tmp ; 
		} 

		// the minimum value in right subtree is successor 
		if (root->right != NULL) 
		{ 
			Node* tmp = root->right ; 
			while (tmp->left) 
				tmp = tmp->left ; 
			suc = tmp ; 
		} 
		return ; 
	} 

	// If key is smaller than root's key, go to left subtree 
	if (root->key > key) 
	{ 
		suc = root ; 
		findPreSuc(root->left, pre, suc, key) ; 
	} 
	else // go to right subtree 
	{ 
		pre = root ; 
		findPreSuc(root->right, pre, suc, key) ; 
	} 
} 

// A utility function to create a new BST node 
Node *newNode(int item) 
{ 
	Node *temp = new Node; 
	temp->key = item; 
	temp->left = temp->right = NULL; 
	return temp; 
} 

/* A utility function to insert a new node with given key in BST */
Node* insert(Node* node, int key) 
{ 
	if (node == NULL) return newNode(key); 
	if (key < node->key) 
		node->left = insert(node->left, key); 
	else
		node->right = insert(node->right, key); 
	return node; 
} 

// Driver program to test above function 
int main() 
{ 
	int key = 65; //Key to be searched in BST 

/* Let us create following BST 
			50 
		/	 \ 
		30	 70 
		/ \ / \ 
	20 40 60 80 */
	Node *root = NULL; 
	root = insert(root, 50); 
	insert(root, 30); 
	insert(root, 20); 
	insert(root, 40); 
	insert(root, 70); 
	insert(root, 60); 
	insert(root, 80); 


	Node* pre = NULL, *suc = NULL; 

	findPreSuc(root, pre, suc, key); 
	if (pre != NULL) 
	cout << "Predecessor is " << pre->key << endl; 
	else
	cout << "No Predecessor"; 

	if (suc != NULL) 
	cout << "Successor is " << suc->key; 
	else
	cout << "No Successor"; 
	return 0; 
} 
