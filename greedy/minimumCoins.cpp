//only for indian denominations
//O(V) time 
//why greedy : addition of 2 adjacent denominations is less than the next deno

#include<bits/stdc++.h>
using namespace std;

void minimumCoins(int V){
    int deno[] = {1,2,5,10,20,50,100,500,1000};
    int n=9;
    vector<int> ans;
    for(int i= n-1;i>=0;i--){
        while(V >= deno[i]){
            V-= deno[i];
            ans.push_back(deno[i]);
        }
    }
    for(int i=0;i<ans.size();i++)
      cout<<ans[i]<<" ";
}

int main(){
    minimumCoins(49);
}