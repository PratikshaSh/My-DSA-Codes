#include <bits/stdc++.h>
using namespace std;

void add_edge(vector<int> adj[], int src, int dest)
{
	adj[src].push_back(dest);
	adj[dest].push_back(src);
}
void bfs(int src, vector<int> adj[]){
    map<int, int> visited;
    queue<int> q;


 
   for(int i=0; i<8; i++){
       vector<int> v = adj[i];
       for(auto node: v){
           visited[node] = INT_MAX;
       }
   }
        q.push(src);
      visited[src] = 0;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        cout<<node<<" ";
        for(int nbr: adj[node]){
            if(visited[nbr] == INT_MAX){
                q.push(nbr);
                visited[nbr]= visited[node] + 1;
            }
        }
    }

    for(auto x: visited){
        cout<<x.first<<"--->"<<x.second<<endl;
    }
}







int main()
{
	// no. of vertices
	int v = 8;

	// array of vectors is used to store the graph
	// in the form of an adjacency list
    
	vector<int> adj[v];

	// Creating graph given in the above diagram.
	// add_edge function takes adjacency list, source
	// and destination vertex as argument and forms
	// an edge between them.
	add_edge(adj, 0, 1);
	add_edge(adj, 0, 3);
	add_edge(adj, 1, 2);
	add_edge(adj, 3, 4);
	add_edge(adj, 3, 7);
	add_edge(adj, 4, 5);
	add_edge(adj, 4, 6);
	add_edge(adj, 4, 7);
	add_edge(adj, 5, 6);
	add_edge(adj, 6, 7);
	int source = 0, dest = 7;
    bfs(source, adj);
	 
	return 0;
}
