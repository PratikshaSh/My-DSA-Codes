#include<iostream>
using namespace std;

int main(){
    // Problem - Unique no. 2N+1
    //Given a list of numbers where every no. accurs twice except one, fine it
    int n;
     cin>>n;

     int no;
     int ans = 0;

     for(int i=0; i<n ; i++){
         cin>>no;
         ans= ans ^ no;
     }
     cout<< ans<<endl;
}
