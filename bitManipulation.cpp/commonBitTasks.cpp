#include<iostream>
using namespace std;

bool isOdd(int n){
    return (n&1);
}
//get the ith bit
int getBit(int n, int i){
   int mask = (1<<i);
   int bit =(n & mask) > 0 ? 1 : 0;
    return bit;
}

int setBit(int n, int i){
    int mask = (1<<i);
    int ans = (n | mask);
    return ans;

}

void clearBit(int &n, int i){
    int mask = ~(1<<i);
    n = n & mask;
}

void updateBit(int &n, int i, int v){
    int mask = ~(1<<i);
    int cleared_n = n & mask;
    n = cleared_n | (v<<i);
}

int clearLastIBits(int n, int i){
    int mask = (-1 << i);
    return n & mask;
}

int clearRangeItoJ(int n, int i, int j){
int a = -1 << (j+1);
int b = (1<<i)-1;

int mask = a|b;
return n & mask;
}

int main(){
    int n;
    int i;
   n= 31; 
  // i= 3;//from pos i-1 to 0=== total 3 digits from last
  i=1;
  int j=3;
  cout<< clearRangeItoJ(n,i,j);
}