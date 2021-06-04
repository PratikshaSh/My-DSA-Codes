// Recursive C++ program for insertion sort
#include <iostream>
#include<vector>
using namespace std;

void insert(vector<int> &arr, int temp){
    int n= arr.size();
    if(n==0 or arr[n-1] <= temp){
        arr.push_back(temp);
        return ;
    }
    int val = arr[n-1];
    arr.pop_back();
    insert(arr, temp);
    arr.push_back(val);
}

void recSort(vector<int> &arr){
    int n= arr.size();
    if(n==1){
        return ;
    }
    int temp = arr[n-1];
    arr.pop_back();
    recSort(arr);
    insert(arr, temp);
}

// A utility function to print an array of size n
void printArray(vector<int> arr)
{
	for (int i=0; i < arr.size(); i++)
		cout << arr[i] <<" ";
}

/* Driver program to test insertion sort */
int main(){
 
	int arr[] = {12, 11, 13, 5, 6};
	int n = sizeof(arr)/sizeof(arr[0]);
   vector<int>vec(arr, arr+n);

	recSort(vec);
	printArray(vec);

	return 0;
}
