#include<vector>
using namespace std;

class PriorityQueue{
    vector<int> pq;

    public:

    PriorityQueue(){

    }

    bool isEmpty(){
        return pq.size() == 0;
    }

    // no. of elements present in priority queue
    int getSize(){
        return pq.size();
    }
    int getMin(){
        if(isEmpty()){
            return 0;// Priority Queue is Empty
        }
        return pq[0];
    }
    
    void insert(int element){
        pq.push_back(element);

        int childIndex = pq.size()-1;

        while(childIndex > 0){
            int parentIndex = (childIndex-1)/2;

            if(pq[childIndex]<pq[parentIndex]){
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            }
            else{
                break;
            }
            childIndex = parentIndex;
        }
       
    }

    int removeMin(){

        if(isEmpty()){
            return 0;
        }
        int ans = pq[0];
        pq[0] = pq[pq.size()-1];
        pq.pop_back();

        //down heapify
        int parentIndex = 0;
        int leftChildIndex = (2*parentIndex) + 1;
        int rightChildIndex = (2*parentIndex) + 2;

        while(leftChildIndex < pq.size()){
            int minIndex = parentIndex;
            if(pq[minIndex] > pq[leftChildIndex]){
                minIndex = leftChildIndex;
            }
            if(rightChildIndex < pq.size() and pq[rightChildIndex] < pq[minIndex]){
                minIndex = rightChildIndex;
            }
            if(minIndex == parentIndex){
                break;
            }
            //swap
            int temp = pq[minIndex];
            pq[minIndex] = pq[parentIndex];
            pq[parentIndex] = temp;

            parentIndex = minIndex;
            leftChildIndex = 2*parentIndex + 1;
            rightChildIndex = 2*parentIndex + 2; 

        }

        return ans;
    }

};