#include <bits/stdc++.h>
using namespace std;

// Driver program to test above functions

int minDiff = INT_MAX;
vector<int> ans1, ans2;
void solve(int arr[], int n, vector<int> set1, vector<int> set2, int sum1, int sum2, int idx){
	if(idx == n){
		int delta = abs(sum1 - sum2);
		if(delta < minDiff){
			ans1 = set1;
			ans2 = set2;
			minDiff = delta;
		}
		return;
	}

	if(set1.size() <( n+1)/2){
	set1.push_back(arr[idx]);
	solve(arr, n, set1, set2, sum1+arr[idx], sum2, idx+1);
	set1.pop_back();}

	if(set2.size() <( n+1)/2){
	set2.push_back(arr[idx]);
	solve(arr, n, set1, set2, sum1, sum2+arr[idx], idx+1);
	set2.pop_back();
}
;
}
int main()
{
	int arr[] = {23, 45, -34, 12, 0, 98, -99, 4, 189, -1, 4};
	int n = sizeof(arr)/sizeof(arr[0]);


	vector<int> set1;
	vector<int> set2;
	int sum1 =0;
	int sum2 = 0;
	
	solve(arr, n, set1, set2, sum1, sum2, 0);
	cout<<"The first subset is: ";
	for(auto s1: ans1){
		cout<<s1<<" ";
	}
	cout<<endl;
	cout<<"The second subset is:";
	for(auto s1: ans2){
		cout<<s1<<" ";
	}
	return 0;
}
