
#include <bits/stdc++.h>
using namespace std;

// structure of a node of BST
struct Node {
	int data;
	Node* left, *right;
};

// function to create and return a node of BST
Node* getNode(int data)
{
	// allocate space for the node
	Node* new_node = (Node*)malloc(sizeof(Node));

	// put in the data
	new_node->data = data;
	new_node->left = new_node->right = NULL;
}



void util1(Node* root, stack<Node*> &s){
    while(root){
        s.push(root);
        root= root->left;
    }
}
void util2(Node* root, stack<Node*> &s){
    while(root){
        s.push(root);
        root= root->right;
    }
}

int MycountPairs(Node* root1, Node* root2, int x){
    stack<Node*> s1;
    stack<Node*> s2;
    util1(root1, s1);
    util2(root2, s2);
  ;

    int count = 0;
     
    while( !s1.empty() and !s2.empty() and s1.top()->data <= s2.top()->data){
          Node* top1 = s1.top();
          Node* top2 = s2.top();
       
        if(top1->data + top2->data == x){
            
            cout<<top1->data<<","<<top2->data<<endl;
            s1.pop();
             if(top1->right) util1(top1->right, s1);
            //  top1 = s1.top();
            s2.pop();
             if(top2->left) util2(top2->left, s2);
            //  top2 = s2.top();
             
            count++;
            
        }
        else if( top1->data + top2->data < x){
           
            s1.pop();
             if(top1->right) util1(top1->right, s1);
            // top1 = s1.top();
        }
        else{
            s2.pop();
             if(top2->left) util2(top2->left, s2);
            // top2 = s2.top();
        }

    }
    return count;
}


int main()
{
	// formation of BST 1
	Node* root1 = getNode(5); /*			 5	 */
	root1->left = getNode(3); /*		 / \	 */
	root1->right = getNode(7); /*		 3	 7	 */
	root1->left->left = getNode(2); /* / \ / \ */
	root1->left->right = getNode(4); /* 2 4 6 8 */
	root1->right->left = getNode(6);
	root1->right->right = getNode(8);

	// formation of BST 2
	Node* root2 = getNode(10); /*		 10		 */
	root2->left = getNode(6); /*		 / \	 */
	root2->right = getNode(15); /*	 6	 15	 */
	root2->left->left = getNode(3); /* / \ / \	 */
	root2->left->right = getNode(8); /* 3 8 11 18 */
	root2->right->left = getNode(11);
	root2->right->right = getNode(18);

	int x = 16;
	cout << "Pairs = "
		<< MycountPairs(root1, root2, x);

	return 0;
}

