// CPP Program to find magic index.
#include <bits/stdc++.h>
using namespace std;

int magicIndex(int* arr, int start, int end)
{    if(start>end) return -1;
    int m = start +((end-start) /2);
    if(m == arr[m])
    return m;

    int left = magicIndex(arr,start, min(arr[m], m-1));
    if(left>=0)
    return left;

    return magicIndex(arr, max(m+1, arr[m]), end);
}

// Driver program
int main()
{
	int arr[] = { -10, -5, 2, 2, 2, 3, 4, 7,
								9, 12, 13 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int index = magicIndex(arr, 0, n - 1);
	if (index == -1)
		cout << "No Magic Index";
	else
		cout << "Magic Index is : " << index;
	return 0;
}
