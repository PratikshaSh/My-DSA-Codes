// C++ program for getting minimum character to be
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
public:
    string shortestPalindrome(string s) {
         
    string rev_s = s;
    reverse(rev_s.begin(), rev_s.end());
     string l = s+ "#" + rev_s;
        int n = l.length();
        int *p = new int[n]{0};
     // int p[n]={0};
    
    //building KMP partial match table
    //i=suffix boundary
    //j=prefix boundary
     for(int i=1;i<l.length();i++){
         int j = p[i-1];
         while(j>0 and l[i]!=l[j])
          j = p[j-1];

         if(l[i]==l[j]){
             p[i] = j+1;
         } 
     }

     return rev_s.substr(0, s.length() - p[l.length() -1]) +s;

    }
};