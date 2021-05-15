#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int prim_mst(vector<pair<int, int>> adj[], int V){

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;

bool *visited = new bool[V]{0};

int ans =0;

Q.push({0,0});// weight, node
 while(!Q.empty()){
     auto best = Q.top();
     Q.pop();

     int to = best.second;
     int weight = best.first;

     if(visited[to]){
         continue;
     }
     ans += weight;
     visited[to] = 1;

     for(auto x: adj[to]){
         if(visited[x.first] == 0){
             Q.push({x.second, x.first});
         }
     }


 }
 return ans;

}

int main(){
vector<pair<int, int>> *adj;
int V, E;
cin>>V>>E;

adj = new vector<pair<int, int>> [V];

while(E--){
    int x, y, w;
    cin>>x>>y>>w;
    adj[x].push_back({y,w});
    adj[y].push_back({x,w});
}

int ans = prim_mst(adj,  V);
}
