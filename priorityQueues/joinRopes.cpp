#include<iostream>
#include<queue>
using namespace std;

// Given N ropes of diff sizez, join them. cost of joining 2 ropes is (A+B).Find minimum cost to join all together.


int join_ropes(int ropes[], int n){
    priority_queue<int, vector<int>, greater<int>> pq(ropes, ropes+n);

    int cost =0;
    while(pq.size() > 1){
        int A = pq.top();
        pq.pop();

        int B= pq.top();
        pq.pop();

        int new_rope = (A+B);
        cost += new_rope;
        pq.push(new_rope);
    }
    return cost;
}
int main(){
    int ropes[] = {4,3,2,6};
    int n=4;

    cout<<join_ropes(ropes,n)<<endl;

    return 0;
}