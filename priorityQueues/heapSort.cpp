//O(NlogN)

#include<iostream>
#include<vector>
using namespace std;



void print(vector<int> v){
    for(auto x : v){
        cout<<x<<" ";
    }
    cout<< endl;
}

void heapify(vector<int> &v, int idx, int size){
    int left = 2*idx + 1;
    int right = 2*idx +2 ;

    int min_idx = idx;
    int last = size -1;

    if(left<= last and v[left]>v[idx]){
        min_idx = left;
    }
    if(right <= last and v[right]>v[min_idx]){
        min_idx = right;
    }
    if(min_idx != idx){
        swap(v[idx], v[min_idx]);
        heapify(v, min_idx, size);
    }
    
    }

    void buildHeap(vector<int> &v){

        for(int i= (v.size()-1)/2 ; i>=0; i--){
            heapify(v, i, v.size());
        }

    }


void heapsort(vector<int> &arr){
    buildHeap(arr);
    int n= arr.size();

    //remove n-1 elements from the heap
    while(n>0){
        swap(arr[0], arr[n-1]);
        //remove that element from the heap
        n--;
        heapify(arr,0,n);
    }
}

int main(){
    vector<int>v;
   // v.push_back(-1);
   int n;
   cin>>n;
   
   int temp;
   for(int i=0 ; i<n; i++){
       cin>>temp;
       v.push_back(temp);
   }
   heapsort(v);
   print(v);
}