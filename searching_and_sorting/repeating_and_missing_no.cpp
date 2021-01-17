//O(n) time - using bitwise operator(xor)
#include<bits/stdc++.h>
using namespace std;

void find2Nos(int arr[],int n, int* x,int *y){
    int xorr,i;
    int set;
    *x=0;
    *y=0;
    xorr=arr[0];
    for( i=1;i<n;i++)
    xorr ^= arr[i];

    for(i=1;i<=n;i++)
    xorr ^= i;

    set = xorr & ~(xorr-1);

    //separating 2 nos from xorr
    for(i=0;i<n;i++){
        if(arr[i] & set)
         *x = *x ^ arr[i];
        else
         *y = *y ^ arr[i];
         
    }
     for(i=1;i<=n;i++){
        if(i & set)
         *x = *x ^ i;
        else
         *y = *y ^ i;
         
    }

}

int main()
{
    int arr[] = { 1, 3, 4, 5, 5, 6, 2 };
    int* x = (int*)malloc(sizeof(int));
    int* y = (int*)malloc(sizeof(int));
    int n = sizeof(arr) / sizeof(arr[0]);
 
    find2Nos(arr, n, x, y);
    cout << " The missing element is " << *x << " and the repeating"
         << " number is " << *y;
    getchar();
}