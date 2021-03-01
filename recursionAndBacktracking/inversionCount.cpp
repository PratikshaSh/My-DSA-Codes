#include<iostream>
using namespace std;

int merge(int arr[], int s, int e){
    int mid = (s+e)/2;
    int i=s;
    int j =(mid+1);
    int k = s;
    int temp[100000];
    int cnt = 0;
    while(i<=mid and j<=e){
        if(arr[i]<=arr[j]){
            temp[k++] = arr[i++];
        }
        else{
            cnt= cnt+mid-i+1;
            temp[k++] =arr[j++];
        }
    }
    while(i<=mid){
        temp[k++] = arr[i++];
    }
    while(j<=e){
        temp[k++] = arr[j++];
    }
    for(int i=s; i<=e; i++){
        arr[i] = temp[i];
    }
    return cnt;

}

int inversionCount(int arr[], int s, int e){
    if(s>=e){
        return 0;
    }
    //merge sort
    int mid = (s+e)/2;
    int x= inversionCount(arr,s,mid);
    int y= inversionCount(arr, mid+1, e);
    int z= merge(arr,s,e);//cross inversion
    return x+y+z;
}

int main(){
    int arr[] = {1,5,2,6,3,0};
    int n = sizeof(arr)/sizeof(int);
    cout<<inversionCount(arr, 0, n-1);
}