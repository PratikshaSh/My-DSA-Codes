#include<bits/stdc++.h>
#include "BSTClass.h"
using namespace std;

int main()
{
    BST b;
    b.insert(10);
    b.insert(5);
    b.insert(20);
    b.insert(7);
    b.insert(3);
    b.insert(15);
    
    b.printTree();
    cout<<b.hasData(12)<<endl;
    cout<<b.hasData(5)<<endl;

    b.deleteData(10);
    b.deleteData(100);
    b.printTree();
}