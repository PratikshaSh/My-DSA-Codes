#include<iostream>
using namespace std;

int fn(int n, int k){
    if(n==0)
    return 1;
    if(n < 0)
    return 0;
    int ans = 0;
    for(int i=1; i<=k; i++){
        ans += fn(n-i, k);
    }
    
  return ans;
}
int main(){
    int n, k;
    cin>>n>>k;
    cout<<fn(n,k);
    return 0;
}