#include <assert.h>
#include <iostream>
using namespace std;


void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void rightrotate(int arr[], int i, int j){

    int temp = arr[j];
    for(int x = j; x> i ; x--){
        arr[x] = arr[x-1];
    }
    arr[i] = temp;

}
void rearrange(int arr[], int n){
    int wrong= -1;
    int j;
    for(int i=0; i<n; ){
        if( arr[i] >=0 and i%2 == 0){
            j=i+1;
            while(arr[j]>=0 and j<n){j++;}
            rightrotate(arr, i, j);
            i = j+1;

        } 
        else if(arr[i]<0 and i%2 != 0){
            j=i+1;
            while(arr[j]<0 and j<n) j++;
            rightrotate(arr, i, j);
            i=j+1;
        }
        else i++;
        //printArray(arr, n);
    }
}
 
// Driver code
int main()
{
     
    int arr[] = { -5, -2, 5, 2, 
                 4, 7, 1, 8, 0, -8 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    cout << "Given array is \n";
    printArray(arr, n);
 
    rearrange(arr, n);
 
    cout << "Rearranged array is \n";
    printArray(arr, n);
 
    return 0;
}