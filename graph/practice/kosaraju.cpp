#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

void dfs(int src, vector<int> adj[], bool visited[], vector<int>& stack){

    visited[src] = true;
    for(auto nbr : adj[src]){
        if(!visited[nbr]){
            dfs(nbr, adj, visited, stack);
        }
    }
            stack.push_back(src);

}

void dfs2(int src, vector<int> adj[], bool visited[]){
    cout<<src<<" ";
    visited[src] = true;
    for(auto nbr : adj[src]){
        if(!visited[nbr]){
            dfs2(nbr, adj, visited);
        }
    }

}

void  kosaraju(vector<int> adj[],vector<int> rev_adj[],int v){
    
    bool visited[v];
    memset(visited, 0, v);

    vector<int>stack;
//step 1
    for(int i=0; i<v; i++){
        if (!visited[i])
        {
           dfs(i, adj, visited, stack);
        }
        
    }
    //step2
    //step 3
    memset(visited, 0, v);
    char comp_name = 'A';
    for(int i = stack.size()-1; i>=0; i--){
        int node = stack[i];
        if(!visited[node]){
            cout<<"component "<<comp_name<<"--->";
            dfs2(node, rev_adj, visited);
            cout<<endl;
            comp_name++;
        }

    }


}
int main(){
    int v, e;
    cin>>v>>e;
    vector<int> adj[v];
    vector<int> rev_adj[v];;

    while(e--){
        int x, y;
        cin>>x>>y;
        adj[x].push_back(y);
        rev_adj[y].push_back(x);
    }

        kosaraju(adj, rev_adj, v);
    
}