// C++ program to find shortest safe Route in
// the matrix with landmines
#include <bits/stdc++.h>
using namespace std;
#define R 12
#define C 10

// These arrays are used to get row and column
// numbers of 4 neighbours of a given cell
int dx[] = { -1, 0, 0, 1 };
int dy[] = { 0, -1, 1, 0 };



int minDist = INT_MAX;
int visited[R][C] ;
bool isSafe(int mat[R][C], int visited[R][C],
            int x, int y)
{
    if (mat[x][y] == 0 || visited[x][y])
        return false;
 
    return true;
}
 

bool isValid(int x, int y)
{
    if (x < R && y < C && x >= 0 && y >= 0)
        return true;
 
    return false;
}
void solve(int  mat[R][C], int i, int j, int dist){
    //base
    if(j==C-1){
       minDist = min(dist, minDist);
        return;
    }
    if(dist > minDist){
        return;
    }
    
    visited[i][j] = 1;
    for(int k=0; k<4; k++){
        // if(isValid(i+dx[k], j+dy[k]) and (mat[i+dx[k]][j+dx[k]] != 0) and (visited[i+dx[k]][j+dy[k]] == 0)){
        if(isValid(i+dx[k], j+dy[k]) and isSafe(mat, visited, i + dx[k], j + dy[k])){

            
            solve(mat, i+dx[k], j+dy[k], dist+1);
        }
    }
    visited[i][j] = 0;
}
int main()
{   
    int grid[R][C];
	// input matrix with landmines shown with number 0
	int mat[R][C] =
	{
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 0, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 0, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 0, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 0, 1, 1, 1, 1 },
		{ 1, 0, 1, 1, 1, 1, 1, 1, 0, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 0, 1, 1, 1, 1, 0, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 0, 1, 1, 1, 1, 1, 1 }
	};

    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            if(mat[i][j] == 0){
                for(int k=0; k<4; k++){
                     if (isValid(i + dx[k], j + dy[k]))
                    mat[i + dx[k]][j + dy[k]] = -1;
                }
            }
            
        }
    }
      for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (mat[i][j] == -1)
                mat[i][j] = 0;
        }
    }
    for(int i=0; i<R; i++){
        if(mat[i][0]==1){
            memset(visited, 0, sizeof(visited));
            solve(mat,i, 0, 0);
            if(minDist == C-1)
             break;
        }
    }
	// solve(grid, 0, 0, 0);
    // cout<<"Min Dist = "<<minDist;

    if (minDist != INT_MAX)
        cout << "Length of shortest safe route is "
             << minDist;
 
    else // if the destination is not reachable
        cout << "Destination not reachable from "
             << "given source";

	return 0;
}
