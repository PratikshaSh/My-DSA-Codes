#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    bool isSS(int sum, int set[], int n)
    {
        if(sum == 0)
        return true;

        if(n==0)
        return false;

        if(set[n-1] > sum){
            return isSS(sum, set, n-1);
        }
        return isSS(sum-set[n-1], set, n-1) or isSS(sum, set, n-1);
    }
    bool isSS2(int sum, int set[], int n){
        bool dp[n+1][sum+1];
        for(int i=0; i<=n; i++){
            dp[i][0]= true;
        }
        for(int i=0; i<=sum; i++){
            dp[0][i] = false;
        
        }

        for(int i=1; i<= sum; i++){
            for(int j=1; j<=sum; j++){
                if(j<set[i-1]){
                    dp[i][j] = dp[i-1][j];
                }
                if(j>= set[i-1]){

                    dp[i][j] = dp[i-1][j] || dp[i-1][j-set[i-1]];
                }
            }
        }
        return dp[n][sum];
    }
}ss;

int main(){
    int set[] = { 3, 34, 4, 12, 5, 2 };
    int sum = 13;
    int n = sizeof(set) / sizeof(set[0]);
  
    if (ss.isSS(sum, set, n))
        printf("Found a subset with given sum");
    else
        printf("No subset with given sum");
    return 0;
}