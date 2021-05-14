#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
 int V,E;
 cin>>V>>E;
 vector<int> adj[V+1];
 vector<int> indegree(V+1, 0);
 for(int i=0; i<E; i++){
     int x, y;
     cin>>x>>y;
     adj[x].push_back(y);
     indegree[y]++;
 }
 vector<int> ans(V+1 , 0);
 queue<int>q;

 for(int i=1; i<=V; i++){
     if(indegree[i] == 0){
         q.push(i);
         ans[i] = 1;
     }
 }

 while(!q.empty()){
     int val = q.front();
     q.pop();
     for(auto nbr : adj[val]){
         indegree[nbr]--;
         if(indegree[nbr] == 0){
             ans[nbr] = ans[val] + 1;
             q.push(nbr);
         }
     }
 }

for(int i=1; i<=V; i++)
cout<<ans[i]<<" ";
}
