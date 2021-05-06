
#include<bits/stdc++.h>
using namespace std;

// Inorder Traversal of Binary Tree
void inorder(int arr[], vector<int> &v, int n, int idx)
{
    if(idx >= n) return;
    
    inorder(arr, v, n, 2*idx +1);
    v.push_back(arr[idx]);
    
    inorder(arr,v,n, 2*idx+2);
}

int minSwaps(vector<int> arr, int n){
  
    
    vector<pair<int, int>> v(n);
      
    for(int i=0; i<n; i++){
        v[i] = {arr[i], i};
    }
    
    
    int count =0;
    sort(v.begin(), v.end());
    for(int i=0; i<v.size(); i++){
        if(v[i].second == i) continue;
        else{
            swap(v[i], v[v[i].second]);
            count++;
        
            i--;
        }
    }
    return count;
}


// Driver code
int main()
{
	int a[] = { 5, 6, 7, 8, 9, 10, 11 };
	int n = sizeof(a) / sizeof(a[0]);
    vector<int> v;
	inorder(a, v, n, 0);
	cout << minSwaps(v,n) << endl;
}

