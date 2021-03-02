//Count Binary Strings of Length of N, which have No consecutive ones?
#include<iostream>
using namespace std;

int fn(int n){
    if(n==0)
    return 1;

    if(n<0)
    return 0;

    if(n==1)
    return 2; 

    return fn(n-1)+fn(n-2);   
    }


int main(){
    int n;
    cin>>n;
    cout<<fn(n);
    return 0;
}