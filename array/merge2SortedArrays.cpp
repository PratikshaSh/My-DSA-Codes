//gap algorithm
//The intuition behind this is SHELL SORT
///O(1) space and O(nlogn) time
//////gap =  ceiling of n/2
#include<bits/stdc++.h>
using namespace std;

int nextGAP(int gap){
    if(gap<=1) return 0;
    else
    {
        return (gap/2)+(gap%2);
    }
    
}
void mergeGAP(int* arr1, int* arr2, int n, int m){
int gap=(m+n);
int i,j;
for( gap=nextGAP(gap); gap>0;gap=nextGAP(gap)){
    //in arr1
    for(i=0;i+gap<n;i++){
        if(arr1[i]>arr1[i+gap])
        swap(arr1[i],arr1[i+gap]);
    }
    //in both
    for(j=gap>n?gap-n:0;i<n and j<m;i++,j++){
        if(arr1[i]>arr2[j])
        swap(arr1[i],arr2[j]);
    }

    if(j<m){
        //in arr2
        for(j=0;j+gap<m;j++){
            if(arr2[j]>arr2[j+gap])
            swap(arr2[j],arr2[j+gap]);
        }
    }
}

}

int main(){
    int arr1[]={10,27,38,43,82};
    int arr2[]={3,9};
    int n=sizeof(arr1)/sizeof(int);
    int m=sizeof(arr2)/sizeof(int);

    mergeGAP(arr1,arr2,n,m);
    printf("First Array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr1[i]);
 
    printf("\nSecond Array: ");
    for (int i = 0; i < m; i++)
        printf("%d ", arr2[i]);
    printf("\n");
    return 0;

}