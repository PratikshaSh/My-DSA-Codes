//output is minimum weight hamiltonian cycle
//Hamiltonian Cycle -set of edges such tha every node is visited once and we back to starting node'
#include<iostream>
using namespace std;

#define INT_MAX 999999

int n=4;
int dp[16][4];
//Adj Matrix which defines the graph
int dist[10][10] = {
    {0,20,42,25},
    {20,0,30,34},
    {42,30,0,10},
    {25,34,10,0}
};

int VISITED_ALL = (1<<n)-1;///all 1s in the end(right)

int tsp(int mask, int pos){
   if(mask == VISITED_ALL){
        return dist[pos][0];
   }
   //lookup
   if(dp[mask][pos] != -1){
       return dp[mask][pos];
   }


    int ans = INT_MAX;
   //Try to goto an unvisited city
   
   for(int city=0;city<n;city++){
       if((mask&(1<<city)) == 0){
           int newAns = dist[pos][city] + tsp(mask|(1<<city) , city);
           ans = min(ans, newAns); 
       }
   }

   return dp[mask][pos]=ans;
}



int main(){

    for(int i=0;i<(1<<n);i++){
        for(int j=0;j<n;j++){
            dp[i][j] = -1;
        }
    }
    cout<<"Min Weight HAmiltonian path costs "<<tsp(1,0)<<endl;
    return 0;
}