// C++ program to sort a stack using recursion
#include <iostream>
#include<stack>
using namespace std;

stack<int> s;



void insert(int temp){
    if(s.size() == 0 or s.top() <= temp ){
        s.push(temp);
        return;
    }
    
    int value = s.top();
    s.pop();
    insert(temp);
    s.push(value);
}

void sortt()
{
   //Your code here
   if(s.size() == 1) return;
   
   int temp = s.top();
   s.pop();
   sortt();
   insert(temp);
}
int main(void)
{
	
    s.push(30);
    s.push(-5);
    s.push(18);
    s.push(14);
    s.push(-3);

	// cout << "Stack elements before sorting:\n";
	// while(!s.empty()){
    //     cout<<s.top()<<" ";
    //     s.pop();
    // }

	sortt();
	cout << "\n";

	cout << "Stack elements after sorting:\n";
	while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
	return 0;
}

// This code is contributed by SHUBHAMSINGH10
