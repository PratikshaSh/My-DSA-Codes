#include<bits/stdc++.h>
using namespace std;


 float squareRoot(float n) 
    { 
        /*We are using n itself as initial approximation 
          This can definitely be improved */
        float x = n; 
        float y = 1; 
        float e = 0.000001; /* e decides the accuracy level*/
        while (x - y > e) { 
            x = (x + y) / 2; 
            y = n / x; 
        } 
        return x; 
    } 
int main() 
{ 
 
    int n = 50; 
    cout << "Square root of " << n << " is " <<
    squareRoot(n); 
    getchar(); 
} 