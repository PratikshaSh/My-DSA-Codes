
#include <bits/stdc++.h>
using namespace std;


void merge(int arr[], int start, int mid, int end)
{   int  i= start;
    int  j = mid +1;
    if (arr[mid] <= arr[j]) {
        return;
    }
	while(i<= mid and j<= end){
        if(arr[i] <= arr[j])
        {
            i++;
           
        }
        else{
            //shift 
            int temp = arr[j];
            int idx = j;
            while(idx != i){
                arr[idx ] = arr[idx -1];
                idx--;
            }

            arr[i] = temp;
            i++;
            mid++;
            j++;

        }
    }
}


void mergeSort(int arr[], int l, int r)
{
    if(l <r){
    int mid = l + (r - l) / 2;
     mergeSort(arr,l,mid);
     mergeSort(arr, mid+1, r);

     merge(arr, l, mid, r);
    }
	
}


void printArray(int A[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", A[i]);
	printf("\n");
}

/* Driver program to test above functions */
int main()
{
	int arr[] = { 12, 11, 13, 5, 6, 7 };
	int arr_size = sizeof(arr) / sizeof(arr[0]);

	mergeSort(arr, 0, arr_size - 1);

	printArray(arr, arr_size);
	return 0;
}
