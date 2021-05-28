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