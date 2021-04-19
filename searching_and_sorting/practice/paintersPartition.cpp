// { Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//

class Solution
{
    public:
    
    bool isPossibleInTime(int arr[], int n, int k, int min_time){
        int paintersUsed = 1;
        long long cur_time = 0;
        
        for(int i=0; i<n; i++){
            if(cur_time + arr[i] > min_time){
                  paintersUsed++;
                  cur_time = arr[i];
            }
                
            else{
            cur_time += arr[i];
            }
            
        }
          if(paintersUsed > k) return false;
           return true;
        
    } 
    long long minTime(int arr[], int n, int k)
    {
        // code here
        // return minimum time
        
        int maxi = INT_MIN;
        long long sum=0;
        long long ans = INT_MAX;
        for(int i=0; i<n; i++){
            maxi = max(maxi, arr[i]);
            sum += arr[i];
        }
        long long s = maxi;
        long long e = sum;
        
        while(s<=e){
            long long m = (s+e)/2;
            
            if(isPossibleInTime(arr,n,k,m)){
                ans = min(ans, m);
                e = m-1;
            }
            else{
                s = m+1;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}  // } Driver Code Ends