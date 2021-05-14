// A C++ program to print topological
// sorting of a DAG
#include <iostream>
#include <list>
#include <queue>
#include<stack>
using namespace std;

// Class to represent a graph
class Graph {
	// No. of vertices'
	int V;

	// Pointer to an array containing adjacency listsList
	list<int>* adj;

	// A function used by topologicalSort
	void topologicalSortUtil(int v, bool visited[],
							stack<int>& Stack);

public:
	// Constructor
	Graph(int V);

	// function to add an edge to graph
	void addEdge(int v, int w);

	// prints a Topological Sort of
	// the complete graph
	void topologicalSort();
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
	// Add w to v’s list.
	adj[v].push_back(w);
}



// The function to do Topological Sort.
// It uses recursive topologicalSortUtil()
void Graph::topologicalSort()
{
	queue<int> q;

    int *indegree = new int[V];
    for(int i=0; i<V; i++)
      indegree[i] = 0;

    for(int i=0; i<V; i++){
        for(auto y: adj[i]){
            indegree[y]++;
        }
    }

   

    for(int i=0; i<V; i++){
        if(indegree[i]==0)
         q.push(i);
    }

while(!q.empty()){
    int node = q.front();
    cout<<node<<" ";
    q.pop();
    for(auto nbr: adj[node]){
        indegree[nbr]--;
        if(indegree[nbr]==0){
            q.push(nbr);
        }
    }
}

	

}

// Driver Code

// 5 4 2 3 1 0 
int main()
{
	// Create a graph given in the above diagram
	Graph g(6);
	g.addEdge(5, 2);
	g.addEdge(5, 0);
	g.addEdge(4, 0);
	g.addEdge(4, 1);
	g.addEdge(2, 3);
	g.addEdge(3, 1);

	cout << "Following is a Topological Sort of the given "
			"graph \n";

	// Function Call
	g.topologicalSort();

	return 0;
}
