// C++ program for getting minimum character to be
#include<bits/stdc++.h>
using namespace std;


bool ispalindrome(string s)
{ int i=0;
int j = s.size()-1;
while(i<=j){
    if(s[i++]!=s[j--])
    return false;
}
return true;
}

int main()
{
	string s = "AACECAAA";
    int cnt =0;
    
   while(s.size()>0){
       if(ispalindrome(s)){
          
           break;
       }else{
           cnt++;
           s = s.substr(0,s.size()-1);
        //  s.erase(s.begin() + s.length() - 1);
       }

   }

   cout<<"count"<<cnt;
}
