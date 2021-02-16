//dfs gives us ordering that is represented to do topological sorting
//add_front
// order in which one should do the tasks

#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Graph{
    map<T, list<T>> l;

    public:
    void addEdge(int x, int y){
        l[x].push_back(y);
        //l[y].push_back(x);
    }

void dfs_helper(T src , map<T,bool> &visited, list<T> &ordering)
{//Recursive function that will traverse the graph

visited[src] = true;

for(T nbr : l[src]){
    if(!visited[nbr]){
        dfs_helper(nbr, visited, ordering);
    }
}

//at this point
ordering.push_front(src);
return;

}
void dfs(){
map<T,bool> visited;
    list<T> ordering;

for(auto p:l){
    T node = p.first;
    visited[node] = false;
}

for(auto p: l){
    T node = p.first;
    if(!visited[node]){
    dfs_helper(node, visited, ordering);

    }
}
for(auto node:ordering){
    cout<<node<<endl;
}

}
};

int main(){
    Graph<int> g;


    g.addEdge(1,2);
    g.addEdge(3,2);
    g.addEdge(4,5);
    g.addEdge(2,5);
    // g.addEdge(0,3);
    // g.addEdge(4,5);
g.dfs();
}