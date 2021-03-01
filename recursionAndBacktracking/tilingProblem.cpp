#include<iostream>
using namespace std;

//Given a wall of size of 4 x N, and tiles of size (1,4) and (4,1).
//In how many ways you can build the wall?

int tilingWays(int n){
    if(n<=3)
    return 1;
    return tilingWays(n-1)+tilingWays(n-4);
}
int main(){
    int n;
     cin>>n;
    cout<< tilingWays(n);
}