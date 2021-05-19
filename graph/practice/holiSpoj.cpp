#include<iostream>
#include<list>
using namespace std;

int dfs(int s, bool *visited, int *&count, int &ans,int v, list<pair<int, int>> *l){
    visited[s] = true;
    count[s] = 1;

    for(auto nbr_pair : l[s]){
        int nbr = nbr_pair.first;
        int wt = nbr_pair.second;

        if(!visited[nbr]){
            count[s] += dfs(nbr, visited, count, ans,v, l);
            int nx = count[nbr];
            int ny = v-nx;
            ans += min(nx, ny) * 2 * wt;
        }
    }
    return count[s];
}



int main(){
    int t;
    // cout<<"v e"<<endl;
    cin>>t;
    while(t--){
    int v;
    cin>>v;
    list<pair<int, int>> *l;
    l = new list<pair<int, int>> [v];
    int e = v-1;
    for(int i=0; i<e; i++)
    {
        int x, y, w;
        // cout<<"x y w"<<endl;
        cin>>x>>y>>w;
        l[x].push_back({y,w});
        l[y].push_back({x,w});
    }

    bool *visited = new bool[v];
    int *count = new int[v];
    for(int i=0; i<v; i++){
        visited[i] = false;
        count[i] = 0;
    }
    int ans =0;
    dfs(0,visited,count, ans,v, l);
    cout<<"Case #"<<t+1<<": "<<ans<<endl;
  
    }

    return 0;
    
}
