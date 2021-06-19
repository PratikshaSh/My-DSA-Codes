
#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node *left, *right;
};

Node* getNode(int data)
{
	
	Node* new_node = (Node*)malloc(sizeof(Node));

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

int MycountPairs(Node* root,int x){
    stack<Node*> s1;
    stack<Node*> s2;
    util1(root, s1);
    util2(root, s2);
    // cout<<"Initial"<<endl;
    // while(!s1.empty()){
    //     cout<<s1.top()->data<<",";
    //     s1.pop();
    // }
    // cout<<endl;
    // while(!s2.empty()){
    //     cout<<s2.top()->data<<",";
    //     s2.pop();
    // }
    // cout<<endl;

    int count = 0;
     
    while( !s1.empty() and !s2.empty() and s1.top()->data < s2.top()->data){
          Node* top1 = s1.top();
          Node* top2 = s2.top();
       
        if(top1->data + top2->data == x){
            
            cout<<"pair = "<<top1->data<<","<<top2->data<<endl;
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
	// formation of binary tree
	Node* root = getNode(5); /*	 5	 */
	root->left = getNode(3); /*	 / \	 */
	root->right = getNode(7); /* 3 7	 */
	root->left->left = getNode(2); /* / \ / \ */
	root->left->right = getNode(4); /* 2 4 6 8 */
	root->right->left = getNode(6);
	root->right->right = getNode(8);

	int x = 10;

	cout << "Count = "
		<< MycountPairs(root, x);

	return 0;
}
