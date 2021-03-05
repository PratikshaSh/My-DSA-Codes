#include<iostream>
using namespace std;

//Replace bits in N by M
//given a 3 32 bit nos, n and m and 2 biy pos, i and j,
//write a method to set all bits between i and j in n equal to m.
//N=10000000000, m=10101, i=2, j=6
//N=10001010100

int clearRangeItoJ(int n, int i, int j){
int a = -1 << (j+1);
int b = (1<<i)-1;

int mask = a|b;
return n & mask;
}

int replaceBits(int n, int m , int i, int j){
    int n_cleared = clearRangeItoJ(n, i, j);
    
    int ans = n_cleared |(m<<i);
    return ans;
}

int main(){
    int n,m,i, j;
    n=15;
    m=2;
    i=1;
    j=3;

    cout<<replaceBits(n, m, i, j);




    return 0;

}