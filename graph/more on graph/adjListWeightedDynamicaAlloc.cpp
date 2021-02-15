#include<vector>
using namespace std;
class Graph{
    vector<pair<int , int>>*l;

    public:
    Graph(int n){
       int  V=n;
       l = new vector<pair<int, int>>[n];
    }
    void addEdge(int x, int y, int w){
        l[x].push_back({y,w});
        l[y].push_back({x,w});
    }
};

