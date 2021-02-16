#include<iostream>
#include<map>
#include<list>
#include<queue>
#include<cstring>
using namespace std;

class Graph{
    list<int>*l;
    int V;

    public:
    Graph(int V){
        this->V = V;
        l = new list<int>[V];
    }

    void addEdge(int x, int y){
        l[x].push_back(y);
    }

    void topological_sort_bfs(){
        //indegree
        int* indegree = new int[V];
        //0 indegree
        for(int i=0;i<V;i++){
            indegree[i]=0;
        }
        //update indegree by traversing edges x->y
        //indegree[y]++

        for(int i=0;i<V;i++){

            for(auto y:l[i]){
                indegree[y]++;
            }
        }

            //bfs
            queue<int> q;

            for(int i=0;i<V;i++){
                if(indegree[i]==0){
                    q.push(i);
                }
            }

            while(! q.empty()){
                int node = q.front();
                cout<< node <<" ";
                q.pop();

                for(auto nbr:l[node]){
                    indegree[nbr]--;
                    if(indegree[nbr] == 0){
                        q.push(nbr);
                    }
                }

        }

    }


};

int main(){
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(2,1);
    g.addEdge(3,4);
    g.addEdge(1,4);
    // g.addEdge(0,3);
    // g.addEdge(4,5);
    g.topological_sort_bfs();
    return 0;
}