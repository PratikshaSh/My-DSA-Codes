// C++ program for the above approach

#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string str){
    int s=0;
    int e= str.length()-1;
    while(s<e){
        if(str[s++]!= str[e--])
        return false;
    }
    return true;
}
void solve(string str, string ans, vector<string> &allAns){
    if(str.length()==0){
        allAns.push_back(ans);
        return;
    }
    
    for(int i=0; i<str.length(); i++){
        string prefix = str.substr(0, i+1);
        string rem = str.substr(i+1);
        if(isPalindrome(prefix)){
            solve(rem, ans+prefix+" ", allAns);
        }
    }
}

void allPalPartitions(string str){
    vector<string> allAns;
    string ans="";
    int n= str.length();
    solve(str, ans, allAns);
    
    //print allAns;
    for(auto s : allAns){
        cout<<s<<endl;
    }
}

// Driver Code
int main()
{
	string str = "nitin";
    allPalPartitions(str);
    return 0;
}
