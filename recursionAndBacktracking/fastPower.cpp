#include<iostream>
#include<math.h>
using namespace std;


int power(int a, int n){
    if(n==0){
        return 1;
    }
    return a* power(a,n-1);
}
int fast_power(int a, int n){
    if(n==0)
     return 1;
    if(n%2 == 0){
        return pow(fast_power(a,n/2),2);
    }
    else if(n&1){//n is odd
        return a*pow(fast_power(a,n/2),2);
    }
}
int main(){
    cout<<power(2,5)<<endl;
    cout<<fast_power(2,5)<<endl;
    return 0;
}