#include<iostream>
using namespace std;

// linear time , const space

int main(){
    int n;
    cin>>n;
    int arr[100005];

    int xorr = 0;
    for(int i=0; i<n; i++){
        cin>>arr[i];
        xorr = xorr^arr[i];
    }
    int temp = xorr;
    int pos =0;
    while(temp&1 != 1){
        pos++;
        temp = temp>>1;
    }
    int mask = 1<<pos;

    int a=0;
    int b=0;
    for(int i=0; i<n; i++){
        if((arr[i]&mask)>0){
            a = a^arr[i];
        }
    
    }
    b= xorr^a;
  cout<<min(a,b)<<","<<max(a,b)<<endl;
    

    return 0;
}