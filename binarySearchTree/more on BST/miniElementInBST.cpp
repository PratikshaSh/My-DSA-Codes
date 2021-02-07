#include<bits/stdc++.h>
#include "NodeClass.h"
using namespace std;

int minValue(Node* root)
{
    if(root == NULL)
    return -1;
    
    // Code here
    
    if(root->left == NULL)
    return root->data;
    
    while(root->left != NULL)
    {
        root = root->left;
    }
    return root->data;
}