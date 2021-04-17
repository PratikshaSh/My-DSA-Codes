// Write your code here
#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int n,q;
  
   
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cin>>q;
    int m;
    

    sort(arr, arr+n);

    int pre[n];
    pre[0]=0;
    for(int i=1; i<=n; i++){
        pre[i] = pre[i-1]+arr[i-1];
    }

    while(q--){
        cin>>m;
        int idx = upper_bound(arr, arr+n, m) - arr;
        int sum = pre[idx];
        cout<<idx<<" "<<sum<<endl;

    }
}