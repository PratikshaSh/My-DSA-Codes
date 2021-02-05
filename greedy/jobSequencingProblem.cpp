//O(NlogN)+O(N*M) time
//O(M) space
//M= max deadline

//we can use disjoint set to remove the check from last day to first day.
#include<bits/stdc++.h>
using namespace std;

struct Job{
    int id;
    
    int dead;
    int profit;
};

bool comparison(Job a,Job b){
    return a.profit> b.profit;

}

pair<int, int> JobScheduling(Job arr[], int n){
    sort(arr,arr+n,comparison);
    int maxi = arr[0].dead;
    for(int i=1;i<n;i++){
        maxi = max(maxi, arr[i].dead);
    }
    int slot[maxi+1];
    for(int i=0;i<=maxi;i++)
    slot[i]=-1;

    int countJobs=0, jobProfit=0;

    for(int i=0;i<n;i++){
        for(int j=arr[i].dead;j>0;j--){
            if(slot[j]==-1){
                slot[j] = i;
                countJobs++;
                jobProfit +=arr[i].profit;
                break;
            }
        }
    }

    return make_pair(countJobs,jobProfit);
}

int main(){
int n;
        
        //size of array
        cin >> n;//4
        Job arr[n];
        //1 4 20 2 1 10 3 1 40 4 1 30
for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }

pair<int , int> ans= JobScheduling(arr,n);
cout<<ans.first<<" "<<ans.second;

}