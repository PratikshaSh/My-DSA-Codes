#include <iostream>
#include<climits>
using namespace std;


bool isPossibleWithH(int arr[], int n, int m, long long int H){
	int woodHeight = 0;
	for(int i=0; i<n; i++){
		if(arr[i] > H)
		woodHeight += arr[i] - H;
	}
	if(woodHeight >= m) return true;
	return false;
}


int main() {
	// your code goes here
 
	int n, m;
	cin>>n>>m;
	int arr[n];
	int maxi = -1;
    int sum =0;
	for(int i=0; i<n; i++){
		cin>>arr[i];
		if(arr[i] > maxi) maxi = arr[i];
        sum += arr[i];
	}

	long long int s =0;
	long long int e = maxi;
	long long int mid,h=0;
	long long int count =0;
	while(s<=e){
		 mid = (s+e)/2;
		count = 0;
		for ( int i = 0 ; i < n ; i++ ) {
			long long int temp = arr[i] - mid;
			count += (temp > 0 ? temp : 0);
		}
		if ( count == m ) {
			h = mid;
			break;
		}
		else if ( count < m) {
			e = mid - 1;
		}
		else {
			s = mid + 1;
			
			if ( mid > h )
				h = mid;
		}

	}
	cout<<h<<endl;
	return 0;
}