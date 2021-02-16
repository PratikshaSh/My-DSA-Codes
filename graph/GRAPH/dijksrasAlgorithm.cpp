#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

template<typename T>
class Graph{
    unordered_map<T, list<pair<T, int>>>m;
    public:

    void addEdge(T u,T v, int dist, bool bidir = true){
    m[u].push_back(make_pair(v,dist));

    if(bidir){
        m[v].push_back(make_pair(u,dist));

    }
    }
    void printAdj(){
        for(auto j:m){
            cout<<j.first<<"-->";
            for(auto l:j.second){
                cout<<"("<<l.first<<","<<l.second<<")";
            }
            cout<<endl;
        }

    }
    void dijkstraSSSP(T src){

        unordered_map<T,int>dist;
        for(auto j: m){
            dist[j.first] = INT_MAX;
        }
        dist[src] = 0;

        //make a set to find out node with the minnimum distance
        set<pair<int,T>>s;

        s.insert(make_pair(0,src));

        while(!s.empty()){
            auto p = *(s.begin());
            T node = p.second;

            int nodeDist = p.first;
            s.erase(s.begin());

            //Iterate over neighbours/children of the current node
            for(auto childPair : m[node]){
                if(nodeDist + childPair.second <dist[childPair.first]){

                    //In the set updation of a particular is not possible
                    //we have to remove the old pair and insert the new pair to simulation updation

                    T dest = childPair.first;
                    auto f = s.find(make_pair(dist[dest], dest));
                    if(f!=s.end()){
                        s.erase(f);
                    }

                    //insert new pair
                    dist[dest] = nodeDist+childPair.second;
                    s.insert({dist[dest],dest});
                }
            }

        }
        //print
        for(auto d:dist){
            cout<<d.first<<" is located at distance of "<<d.second<<endl;
        }

    }
};

int main(){
    Graph<string> india;
    india.addEdge("Amritsar","Delhi",1);
    india.addEdge("Amritsar","Jai",4);
    india.addEdge("Jai","Delhi",2);
    india.addEdge("Jai","Mum",8);
    india.addEdge("Bhop","Agra",2);
    india.addEdge("Mum","Bhop",3);
    india.addEdge("Agra","Delhi",1);

    india.printAdj();
    india.dijkstraSSSP("Amritsar");
    return 0;


}