//minimum comparisons
#include<bits/stdc++.h> 
using namespace std; 

int middle(int a, int b, int c){
        
       
    int x = a - b; 
  
    int y = b - c;  
    int z = a - c;  
   
    if (x * y > 0) 
        return b; 
  
    else if (x * z > 0) 
        return c; 
    else
        return a;
    }

    int main() 
{ 
    int a = 20, b = 30, c = 40; 
    cout << middle(a, b, c); 
    return 0; 
} 