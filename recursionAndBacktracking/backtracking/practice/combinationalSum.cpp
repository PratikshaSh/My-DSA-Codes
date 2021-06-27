

#include <bits/stdc++.h>
using namespace std;


void findNumbers(vector<int>& ar, int sum,
				vector<vector<int> >& res, vector<int>& r,
				int i)
{
	if(i == ar.size()){
        if (sum == 0) {
		res.push_back(r);
	
	}
    	return;
    }
	

        if(ar[i] <= sum){
            r.push_back(ar[i]); 
            //picl
            findNumbers(ar, sum - ar[i], res, r, i);
            r.pop_back();
        }
		//non pick
		findNumbers(ar, sum , res, r, i+1);
	
}

vector<vector<int> > combinationSum(vector<int>& ar,
									int sum)
{
	// sort input array
	sort(ar.begin(), ar.end());

	// remove duplicates
	ar.erase(unique(ar.begin(), ar.end()), ar.end());

	vector<int> r;
	vector<vector<int> > res;
	findNumbers(ar, sum, res, r, 0);

	return res;
}

// Driver code
int main()
{
	vector<int> ar;
	ar.push_back(2);
	ar.push_back(4);
	ar.push_back(6);
	ar.push_back(8);
	int n = ar.size();

	int sum = 8; // set value of sum
	vector<vector<int> > res = combinationSum(ar, sum);

	// If result is empty, then
	if (res.size() == 0) {
		cout << "Emptyn";
		return 0;
	}

	// Print all combinations stored in res.
	for (int i = 0; i < res.size(); i++) {
		if (res[i].size() > 0) {
			cout << " ( ";
			for (int j = 0; j < res[i].size(); j++)
				cout << res[i][j] << " ";
			cout << ")";
		}
	}
}
