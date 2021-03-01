//D & C
//O(nlogn) on avg case - partitioning at the middle always
//O(n2) worst case - at beginning(asc) or end always(desc)
#include<iostream>
using namespace std;

int partition(int *a, int s , int e){
    int i = s;
    int j = e;
   
    int pivot = a[s];
    int p=s;
    while(i<=j){
        do{
            i++;
        }while(a[i]<pivot);

        while(a[j]>pivot){
            j--;
        };

        if(i<j){
            swap(a[i], a[j]);
        }
    }
    swap(a[j], a[p]);
    return j;
}
int partition2(int *a, int s, int e){
    int i = s-1;
    int j = s;
    int pivot = a[e];
    for(;j<=e-1; ){
        if(a[j]<=pivot){
            i++;
            swap(a[i],a[j]);
        }
        j++;
    }
    swap(a[i+1], a[e]);
    return i+1;
}
void quickSort(int *arr, int s, int e){
    //base case
    if(s>=e){
        return;
    }
    //rec
   
    int j= partition2(arr,s,e);
    quickSort(arr, s, j-1);
    quickSort(arr, j+1, e);
}

int main(){
     int arr[] = {2,7,8,6,1,5,4};
     int n = sizeof(arr) / sizeof(int);
    //  arr[n+1] = INT_MAX;
    //  n++;
    
     quickSort(arr,0,n-1);

     for(int i=0; i<n; i++){
         cout<<arr[i]<<" ";
     }
     return 0;
}