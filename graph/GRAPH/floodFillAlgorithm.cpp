//Flood Fill is a simple variant of BFS/DFS that can be
//used to label(color) the various connected components present in a graph
//It is generally performed on implicit graphs(2d matrices)
//Stating from a particular call we call 'DFS' on the neighbouring cells to color them.
//Neighbours can be '4'( up, down,left, right) or '8' if we include diagonals also.

#include<bits/stdc++.h>
using namespace std;

int R,C;
//W, N,E,S
int dx[] = {-1,0,1,0};
int dy[] = {0,-1,0,1};

void printMat( char input[][50]){

    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cout<<input[i][j];
        }
        cout<<endl;
    }

}
//ch is the char to be replaced
//color is the char to be added

void floodFill(char mat[][50], int i, int j, char ch, char color){
//Base case - matrix bounds
if(i<0 or j<0 or i>=R or j>=C){
    return;
}


//Figure Boundary Condition
if(mat[i][j]!=ch){
    return;
}

//recursive call
mat[i][j] = color;
printMat(mat);
cout<<endl;
for(int k=0 ; k<4;k++){
    floodFill(mat, i+dx[k] , j+dy[k] , ch, color);
    }

}



int main(){
    cin>>R>>C;

    char input[15][50];
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cin>>input[i][j];
        }
    }
    printMat(input);

    floodFill(input, 8, 13, '.','r');

    printMat(input);

    return 0;
}

//input
// 15 30
// ..............................
// ..............................
// ..............#####...........
// ..............#...#...........
// ......#########...#######.....
// .....###.....######.....#####.
// ....##......................##
// ...##.......................##
// ...#......................##..
// ....##..................##....
// ......##..............##......
// ........##############........
// ..............................
// ........###############.......
// ..............................