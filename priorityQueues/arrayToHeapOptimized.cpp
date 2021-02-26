//O(N) time 
//BU
//here - max heap
#include<iostream>
#include<vector>
using namespace std;


void print(vector<int> v){
    for(auto x : v){
        cout<<x<<" ";
    }
    cout<< endl;
}
void heapify(vector<int>&v, int idx){
    int left = 2*idx +1;
    int right = 2*idx +2;

    int min_idx = idx;
    int last = v.size() - 1;

    if(left <= last and v[left]>v[idx]){
        min_idx = left;
    }
    if(right <= last and v[right]>v[idx]){
        min_idx = right;
    }
    if(min_idx != idx){
        swap(v[min_idx], v[idx]);
        heapify(v, min_idx);
    }

}

void buildHeapOptimised(vector<int> &v){

    for(int i= (v.size()-1)/2; i>=0;i--){
        heapify(v, i);
    }
}

int main(){
    vector<int> v{10, 20, 5, 6, 1, 8, 9,4}; //heap
    print(v);
    buildHeapOptimised(v);
    print(v);
}

