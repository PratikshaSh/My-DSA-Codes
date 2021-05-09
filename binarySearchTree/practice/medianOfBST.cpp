/* C++ program to find the median of BST in O(n)
time and O(1) space*/
#include<bits/stdc++.h>
using namespace std;

/* A binary search tree Node has data, pointer
to left child and a pointer to right child */
struct Node
{
	int data;
	struct Node* left, *right;
};

// A utility function to create a new BST node
struct Node *newNode(int item)
{
	struct Node *temp = new Node;
	temp->data = item;
	temp->left = temp->right = NULL;
	return temp;
}

/* A utility function to insert a new node with
given key in BST */
struct Node* insert(struct Node* node, int key)
{
	/* If the tree is empty, return a new node */
	if (node == NULL) return newNode(key);

	/* Otherwise, recur down the tree */
	if (key < node->data)
		node->left = insert(node->left, key);
	else if (key > node->data)
		node->right = insert(node->right, key);

	/* return the (unchanged) node pointer */
	return node;
}

/* Function to count nodes in a binary search tree
using Morris Inorder traversal*/
int countNodes(struct Node *root)
{
    int count = 0;
    Node* cur = root;
    Node* preo ;

    while(cur!=NULL){
        if(cur->left == NULL){
            count++;
            cur = cur->right;
        }
        else{
            preo = cur->left;
            while(preo->right != NULL and preo->right != cur ){
                preo = preo ->right;
            }
            if(preo->right == NULL){
                preo->right = cur;
                cur = cur->left;
            }
            else{
                preo->right = NULL;
                count++;
                cur = cur->right;
            }
        }
    }
	
	return count;
}


/* Function to find median in O(n) time and O(1) space
using Morris Inorder traversal*/
int findMedian(struct Node *root)
{
    if(root == NULL) return 0;
    int count =  countNodes(root);
    Node* cur = root;
    Node* preo ;
    Node* prev;
    int curCount =0;

    while(cur!=NULL){
        if(cur->left == NULL){
            curCount++;
            //check if current node is median or not
            //odd
            if(count % 2 != 0 and curCount == (count + 1)/2)
                return cur->data;
            //even 
            else if(count % 2 == 0 and curCount == (count/2)+1)
                return (prev->data + cur->data)/2;    

            prev = cur;
            cur = cur->right;
        }
        else{
            preo = cur->left;
            while(preo->right != NULL and preo->right != cur ){
                preo = preo ->right;
            }
            if(preo->right == NULL){
                preo->right = cur;
                cur = cur->left;
            }
            else{
                preo->right = NULL;
                prev = preo;
                 curCount++;
            //check if current node is median or not
            //odd
            if(count % 2 != 0 and curCount == (count + 1)/2)
                return cur->data;
            //even 
            else if(count % 2 == 0 and curCount == (count/2)+1)
                return (prev->data + cur->data)/2;    

            prev = cur;
                cur = cur->right;
            }
        }
    }
	
}

/* Driver program to test above functions*/
int main()
{

	/* Let us create following BST
				50
			/	 \
			30	 70
			/ \ / \
		20 40 60 80 */
	struct Node *root = NULL;
	root = insert(root, 50);
	insert(root, 30);
	insert(root, 20);
	insert(root, 40);
	insert(root, 70);
	insert(root, 60);
	insert(root, 80);

	cout << "\nMedian of BST is "
		<< findMedian(root);
	return 0;
}
