//O(log b)time
#include<bits/stdc++.h>
using namespace std;

int countSquares(int a, int b){
    return (floor(sqrt(b))-ceil(sqrt(a))+1);

}

int main(){
int a,b;
cin>>a>>b;
cout<<countSquares(a,b);

}
