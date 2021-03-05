#include<iostream>
using namespace std;
//Given a num N, find no. of set bits in binary rep. of it


//First Method
int countBits(int n){
    int ans = 0;
    while(n>0){
        ans += (n&1);
        n = n>>1;
    }
    return ans;
}

//Second Method
//TC = O(no. of set bits)
int countBitsFast(int n){
    int ans = 0;
    while(n>0){
        n = n & (n-1);// this line removes last set bit
        ans++;
    }
    return ans;// ans is the no. of times above loop will run
}

int main(){
    int n;
    cin>>n;
    cout<<countBits(n)<<endl;
    cout<<countBitsFast(n)<<endl;
    cout<<__builtin_popcount(n)<<endl;

    return 0;
}