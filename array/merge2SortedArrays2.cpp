///using insertion sort
////O(m*n)time O(1)space
#include<bits/stdc++.h>
using namespace std;

void merge2(int* arr1,int* arr2,int m, int n){
    for(int i=n-1;i>=0;i--){
        int j;
        int last= arr1[m-1];
        for(j=m-2;j>=0 and arr1[j]>arr2[i];j--){
            arr1[j+1]=arr1[j];
        }

        if(j!=m-2 or last>arr2[i]){
            arr1[j+1]=arr2[i];
            arr2[i]=last;
        }
    }
}

int main()
{

    int ar1[] = {1, 5, 9, 10, 15, 20}; 
    int ar2[] = {2, 3, 8, 13}; 
    int m = sizeof(ar1)/sizeof(int); 
    int n = sizeof(ar2)/sizeof(int); 
    merge2(ar1, ar2, m, n); 
  
    cout << "After Merging nFirst Array: "; 
    for (int i=0; i<m; i++) 
        cout << ar1[i] << " "; 
    cout << "nSecond Array: "; 
    for (int i=0; i<n; i++) 
        cout << ar2[i] << " "; 
   return 0;
}