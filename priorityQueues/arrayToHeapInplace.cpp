//O(NlogN)
//see ccomplexity proof (mathematical + intuitive
#include<iostream>
#include<vector>
using namespace std;


void print(vector<int> v){
    for(auto x : v){
        cout<<x<<" ";
    }
    cout<< endl;
}

void buildHeap(vector<int> &v){

    for(int i=1;i<v.size();i++){
        int idx = i;
        int parent = (i-1)/2;
        while(idx > 0 and v[idx] > v[parent] ){
            swap(v[idx], v[parent]);
            idx = parent;
            parent = (parent-1)/2;
        }
    }
}

int main(){
    vector<int> v{10, 20, 5, 6, 1, 8, 9,4}; //heap
    print(v);
    buildHeap(v);
    print(v);
}
