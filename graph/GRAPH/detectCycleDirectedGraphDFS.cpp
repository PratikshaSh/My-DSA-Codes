//Dectect a back eddge (node to ancestor of that node)
//going to a visited node will not create cycle if that node is not in the current path off that node
//DFS

//Tricky thoda sa

#include<bits/stdc++.h>
using namespace std;

class graph{
    list<int> *l;
    int V;

    public:
    graph(int V){
        this->V = V;
        l = new list<int>[V];
    }

    void addEdge(int x, int y){
        l[x].push_back(y);
        //l[y].push_back(x);
    }

    bool cycle_helper(int node, bool* visited, bool* stack){

        //visit a  node
        visited[node] = true;
        stack[node] = true;

        //check + recursion to proceed
        for(int nbr:l[node]){
            if(stack[nbr]==true){
                return true;
            }
            else if(visited[nbr]== false){
                bool cycle_mila = cycle_helper(nbr,visited, stack);
                if(cycle_mila == true)
                return true;
            }
        }



        //leave a node
        stack[node] = false;
        return false;
    }
    bool contains_cycle(){
        //check for cycle in directed graph
        bool *visited = new bool[V];
        bool *stack = new bool[V];

        for(int i=0;i<V;i++){
            visited[i] = stack[i] =false;
        }
        return cycle_helper(0,visited,stack);

    }
};
int main(){
    graph g(7);

    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.addEdge(1,5);
    g.addEdge(5,6);
    g.addEdge(4,2); // Baccccccccck edge

    if(g.contains_cycle()){
        cout<<"YES";
    }else{
        cout<<"NO";
    }




}