#include <iostream>
#include<algorithm>
using namespace std;


bool canPlaceCows(int arr[], int n, int c, int min_sep){
	int last_cow = arr[0]; 
	
	//place the first cow in the first stall
	int cow_cnt = 1;
	for(int i=1; i<n; i++ ){
		if(arr[i] - last_cow >= min_sep){
			last_cow = arr[i];
			cow_cnt++;
			if(cow_cnt == c)
			return true;
		}
	}
	return false;
}

int main() {
	int t;
	cin>>t;
	while(t--){
		int n, c;
		cin>>n>>c;
		int arr[n];
		for(int i=0; i<n; i++){
			cin>>arr[i];
            // cout<<arr[i]<<" ";
		}
		sort(arr, arr+n);
		int s =0;
		int e = arr[n-1] - arr[0];
		
		int ans =0;
		while(s<=e){
			int m = (s+e)/2;
			
			bool cowsRakhPaye = canPlaceCows(arr,n,c,m);
			
			if(cowsRakhPaye){
                if(m>ans)
				ans = m;
				s = m+1;
			}
			else {
				e = m-1;
			}
			
			
		}
		cout<<ans<<endl;
	}
	return 0;
}