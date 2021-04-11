#include<bits/stdc++.h>
using namespace std;


void snapshotIp(vector<string> &allIpAddresses, string s, int buildIdx, string *path, int segment){

//base case
 if(segment == 4 and buildIdx == s.length()){
     allIpAddresses.push_back(path[0]+'.'+path[1] + '.' + path[2] + '.' + path[3]);
     return ;
 }else if(segment == 4 or buildIdx == s.length()){
     return;
 }

 for(int len =1;len<=3 and buildIdx+len<= s.length(); len++){
     string snapshot = s.substr(buildIdx,len);
     int value =stoi(snapshot);
     //our constraints
     if(value>255 or (len>=2 and s[buildIdx]=='0')){
         break;
     }
     path[segment] = snapshot;
     snapshotIp(allIpAddresses,s,buildIdx+len,path,segment+1);
     //path[segment] = -1;
 }

}


//driver
vector<string> restoreIpAddress(string s){
    vector<string> allIpAddresses ;
    string path[4] ;
    snapshotIp(allIpAddresses,s,0, path,0);
    return allIpAddresses;
}

int main()
{
    string A = "25525511135";
    string B = "25505011535";
 
    vector<string> ans = restoreIpAddress(A);
    if(ans.empty()){
        cout<<"-1"<<endl;    }
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<endl;
    }
    //restoreIpAddress(B);
   cout<<"done";
    return 0;
}