/* C++ Program to flatten a given Binary
Tree into linked list */
#include <iostream>
using namespace std;

struct Node {
	int key;
	Node *left, *right;
};

/* utility that allocates a new Node
with the given key */
Node* newNode(int key)
{
	Node* node = new Node;
	node->key = key;
	node->left = node->right = NULL;
	return (node);
}

// Function to convert binary tree into
// linked list by altering the right node
// and making left node point to NULL


//first = head
//second = tail
pair<Node*, Node*> util(Node* &root){
    pair<Node*, Node*> p;
    if(root == NULL){
        p.first = NULL;
        p.second = NULL;
        return p;
    }
    //leaf node
    if(root->left == NULL and root->right == NULL){
        p.first = root;
        p.second = root;
        return p;
    }
    //left is not null
    if(root->left != NULL and root->right == NULL){
         pair<Node*, Node*> lans = util(root->left);
         lans.second->right = root;
         p.first = lans.first;
         p.second = root;
         return p;
    }
    //right is not null
    if(root->left == NULL and root->right != NULL){
        pair<Node*, Node*> rans = util(root->right);
        root->right = rans.first;
        p.first = root;
        p.second = rans.second;
        return p;
    }
    //both sides not null
   
        pair<Node*, Node*> lans = util(root->left);
        pair<Node*, Node*> rans = util(root->right);
        lans.second->right = root;
        root->right = rans.first;
        p.first = lans.first;
        p.second = rans.second;
        return p;
    
}
void flatten(struct Node* &root)
{   if(root == NULL) return;
	pair<Node*, Node*> ll = util(root);
    Node* temp = ll.first;

    while(temp != NULL){
        cout<< temp->key <<"--->";
        temp = temp->right;
    }
}

// To find the inorder traversal
void inorder(struct Node* root)
{
	// base condition
	if (root == NULL)
		return;
	inorder(root->left);
	cout << root->key << " ";
	inorder(root->right);
}

/* Driver program to test above functions*/
int main()
{
	/* 1
		/ \
	2	 5
	/ \	 \
	3 4	 6 */
	Node* root = newNode(5);
	root->left = newNode(3);
	root->right = newNode(7);
	root->left->left = newNode(1);
	root->right->left = newNode(6);
	root->right->right = newNode(8);

	flatten(root);
    cout<<endl;
    // inorder(root);
	
	return 0;
}
