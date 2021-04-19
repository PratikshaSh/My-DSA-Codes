#include <iostream>
using namespace std;


bool isCooked(int rank[],int l, int p, int min_time){
	//min_time given to each cook
	int pratas =0;
	for(int i=0; i<l; i++){
		int timeSum = rank[i];
		int j =1;
		
		while(timeSum <= min_time){
			
			j++;
			pratas++;
			if(pratas == p)
			return true;
			
			timeSum += rank[i]*j;
		}
	}
	return false;
}

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
		int p;
		cin>>p;
		int l;
		cin>>l;
		int rank[l];
		for(int i=0; i<l; i++){
			cin>> rank[i];
		}
		int fastestCookTime = 0;
		for(int i=1; i<=p; i++){
			fastestCookTime += i*rank[0];
		}
		int s =0;
		int e = fastestCookTime;
		int ans = INT_MAX;
		while(s<=e){
			int m = (s+e)/2;
			
			if(isCooked(rank, l,p, m)){
				ans = min(ans,m);
				e = m-1;
			}
			else{
				s = m+1;
			}
			
		}
        cout<<ans<<endl;
	}
	return 0;
}