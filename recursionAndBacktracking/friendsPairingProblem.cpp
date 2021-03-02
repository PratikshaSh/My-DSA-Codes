#include<iostream>
using namespace std;

//Given N, friends who want to go to a party on bikes. Each guy can go as single, or as a couple.
//Find the number of ways in which N friends can go to party.
//N = 3
//Ways = 4

int pairingWays(int n){
    if(n==0){
        return 1;
    }
    if(n==1){
        return 1;
    }
    return pairingWays(n-1) + (n-1)*pairingWays(n-2);
}
int main(){
    int n;
    cin>>n;
    cout<< pairingWays(n);
    return 0;
}