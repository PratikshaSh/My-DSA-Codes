#include<iostream>
using namespace std;

char words[][10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};

void printSpellings(int n){
    if(n==0){
        return;
    }
    printSpellings(n/10);
    int dig = n%10;
    cout<<words[dig]<<" ";
}
int main(){int n;
cin>>n;
printSpellings(n);
}