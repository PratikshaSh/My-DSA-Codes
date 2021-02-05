//O(2nlogn)+O(2n) TC == O(nlogn) TC
//O(1) space

#include<iostream>
#include<algorithm>
using namespace std;



int findPlatform(int arr[], int dep[], int n){
    sort(arr,arr+n);//(nlogn)
    sort(dep,dep+n);//(nlogn)

    int plotNeeded = 1, maxi = 1;
    int i=1,j=0;
    //O(2n)
    while(i<n and j<n){ 
        if(arr[i]<= dep[j]){
            plotNeeded++;
            i++;
        }
        else if(arr[i]> dep[j]){
            plotNeeded--;
            j++;
        }
        if(plotNeeded > maxi){
            maxi = plotNeeded;
        }
    }
    return maxi;
}

int main(){
    int N = 6 ;
int arr[N] = {900, 940, 950, 1100, 1500, 1800};
int dep[N] = {910, 1200, 1120, 1130, 1900, 2000};
cout<<findPlatform(arr, dep,N);
}