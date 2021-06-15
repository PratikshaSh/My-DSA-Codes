/* C++ program to construct a binary tree from
the given string */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left
child and a pointer to right child */
struct Node {
	int data;
	Node *left, *right;
};
/* Helper function that allocates a new node */
Node* newNode(int data)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->left = node->right = NULL;
	return (node);
}

/* This function is here just to test */
void preOrder(Node* node)
{
	if (node == NULL)
		return;
	printf("%d ", node->data);
	preOrder(node->left);
	preOrder(node->right);
}


int start =0;
// function to construct tree from string
Node* treeFromString(string str)
{
    
    if(start>= str.length()){
        return NULL;
    }
    bool isNeg = false;
    if(str[start]=='-'){
        isNeg = true;
        start++;
    }
	int num =0;
	while(start<str.length() and str[start]>='0' and str[start] <= '9'){
	    int val = str[start]-'0';
	    num = num*10 + val;
	    start++;
	}
	if(isNeg == true){
	    num = -num;
	}
	struct Node* root = newNode(num);

	if(start >= str.length()) return root;
	
	if(start< str.length() and str[start] == '('){
	    start++;
	    root->left = treeFromString(str);
	}
	
	if(start< str.length() and str[start]==')'){
	    start++;
	    return root;
	}
	if(start< str.length() and str[start]=='('){
	    start++;
	    root->right = treeFromString(str);
	}
	if(start< str.length() and str[start]==')'){
	    start++;
	    return root;
	}
	return root;
}

// Driver Code
int main()
{
	string str = "4(2(3)(1))(6(5))";
	
	Node* root =treeFromString(str);
	preOrder(root);
}
