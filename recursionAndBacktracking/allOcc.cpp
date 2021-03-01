#include<iostream>
using namespace std;
int storeOcc(int *arr,int i, int n, int key,int *out, int j){
    if(i==n)
    return j;

    if(arr[i]==key){
        out[j] = i;
        return storeOcc(arr, i+1, n, key, out, j+1);
    }
    return storeOcc(arr, i+1, n, key, out, j);
}

void allOcc(int *arr,int i, int n, int key){
    if(i==n)
    return;

    if(arr[i] == key){
        cout<<i<<" ";
    }

    allOcc(arr,i+1, n, key);


}

int main(){
    int arr[] ={1,2,3,7,4,5,6,7,10};
    int key =7;
    int n = sizeof(arr)/sizeof(int);
    allOcc(arr,0, n, key);
    cout<<endl;
    int output[100];
    int cnt = storeOcc(arr,0,n,key,output,0);
    for(int i=0;i<cnt;i++){
        cout<<output[i]<<",";
    }
    return 0;
}