// A C++ program for Dijkstra's single source shortest path algorithm.
// The program is for adjacency matrix representation of the graph

#include <limits.h>
#include <stdio.h>
#include<iostream>
using namespace std;

// Number of vertices in the graph
#define V 9

// A utility function to print the constructed distance array
void printSolution(int dist[])
{
	printf("Vertex \t\t Distance from Source\n");
	for (int i = 0; i < V; i++)
		printf("%d \t\t %d\n", i, dist[i]);
}

// Function that implements Dijkstra's single source shortest path algorithm
// for a graph represented using adjacency matrix representation
int minValueNode(int value[] , bool visited[]){
int min = INT_MAX, min_idx;
for(int i=0; i<V; i++){
    if(!visited[i] and value[i]< min){
        min = value[i], min_idx = i;
    }
}
return min_idx;
}
void printSPG(int parent[], int value[]){
    int SPG[V][V];
    for(int i=0; i<V; i++){
        if(parent[i] != -1)
       SPG[parent[i]][i] =  value[i];
    }


    for(int i=0; i<V; i++)
     {
         for(int j=0; j<V; j++) 
         {
             if(SPG[i][j] == INT_MAX)
              cout<<-1<<",";
            cout<<SPG[i][j]<<",";

         }
         cout<<endl;
    }
      
}

void dijkstra(int graph[V][V], int src)
{
    int value[V];
    int parent[V];
    bool visited[V];

    //initialization
    for(int i=0; i<V; i++){
        value[i] = INT_MAX;
        parent[i] = -1;
        visited[i] = false;
    }
    value[src] = 0;
    for(int count= 0; count < V-1; count++){

        int u = minValueNode(value,visited);

        visited[u] = true;
        for(int v=0; v<V; v++){
            if(!visited[v] and graph[u][v] and value[u] != INT_MAX and value[u] + graph[u][v] < value[v]){
                value[v] = value[u] + graph[u][v] ;
                parent[v] = u;
            }
        }


    }
    printSolution(value);
    // printSPG(parent, value);
    cout<<endl;
    for(int i=0; i<V; i++){
        cout<<parent[i]<<"--->";
    }
		
}

// driver program to test above function
int main()
{
	/* Let us create the example graph discussed above */
	int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
						{ 4, 0, 8, 0, 0, 0, 0, 11, 0 },
						{ 0, 8, 0, 7, 0, 4, 0, 0, 2 },
						{ 0, 0, 7, 0, 9, 14, 0, 0, 0 },
						{ 0, 0, 0, 9, 0, 10, 0, 0, 0 },
						{ 0, 0, 4, 14, 10, 0, 2, 0, 0 },
						{ 0, 0, 0, 0, 0, 2, 0, 1, 6 },
						{ 8, 11, 0, 0, 0, 0, 1, 0, 7 },
						{ 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

	dijkstra(graph, 0);

	return 0;
}
