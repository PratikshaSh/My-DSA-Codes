//O(NlogN+N) time/
//O(1) space
#include<bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};

bool comp( Item a,Item b){
 double r1 = (double)a.value /(double)a.weight;
 double r2 = (double)b.value /(double)b.weight;
 return r1>r2;

}

double fractionalKnapsack(int w, Item arr[], int n){
    sort(arr, arr+n, comp);

    int curWeight =0;
    double finalValue = 0.0;//could be fractional

    for(int i=0;i<n;i++){
        if(curWeight+arr[i].weight<=w){
            curWeight+=arr[i].weight;
            finalValue += arr[i].value;
        }
        else{
            int remain = w- curWeight;
            finalValue += (arr[i].value/(double)arr[i].weight) * (double)remain;
            break;
        }
    }

    return finalValue;
}

int main(){
    int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		cout<<fractionalKnapsack(W, arr, n)<<endl;
}
//N = 3, W = 50
//values[] = {60,100,120}
//weight[] = {10,20,30}