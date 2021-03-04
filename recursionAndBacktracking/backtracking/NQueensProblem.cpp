#include<iostream>
using namespace std;

//place N queens on a N X N chess board such that all queens are safe
//no two queens are under attack(row, col ,diagonal)
//all possible solutions-- backtracing
//if looking for optimal --go for Dp


bool isSafe(int board[][10], int i, int j, int n){
    //col check
    for(int row = 0; row<i; row++){
        if(board[row][j] == 1){
            return false;
        }
    }
    //left diag check
    int x=i;
    int y=j;

    while(x>=0 and y>=0){
        if(board[x][y]==1){
            return false;
        }
        x--;
        y--;
    }

    //right diag
    x= i; 
    y = j;
    while(x>=0 and y<n ){
        if(board[x][y]==1){
            return false;

        }
        x--;
        y++;
    }
    //pos is safe
    return true;
}

bool solveNQueen(int board[][10], int i, int n){
    if(i==n){
        //We have successfully palce queens in n rows(0..n-1)
        //Print the board
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] ==1){
                    cout<<"Q"<<" ";
                }
                else{
                    cout<<"_"<<" ";
                }
            }
            cout<<endl;
        }
        cout<<endl;

        return false;//for all configs
    }
    //Recurssive case 
    //try to place the queen in the current row and call on remaining part which will be solved by the recursion
    for(int j=0; j<n; j++){
        //first check isit safe to place queen on current pos
        if(isSafe(board, i, j, n)){
            //Place the Queen - Assuming i, j is the right position
            board[i][j] = 1;
        

        bool nextQueenRakhPaye = solveNQueen(board, i+1,n);
        if(nextQueenRakhPaye){
            return true;
        }
        //means i, j is not the right pos and our assumption is wrong
        board[i][j]=0;//Backtrack
        }
    }
    //You have tried all the positions in the current row but couldnt place the queen
    return false;
}


int main(){

    int n;
    cin>>n;
    int board[10][10] = {0};
    solveNQueen(board, 0, n);


    return 0;
}