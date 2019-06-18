#include<iostream>
#include<cmath>
using namespace std;

bool isSafe(int board [][9], int x, int y, int n, int num){
    
    //Check rows and cols
    for(int i=0; i<n; i++){
        if(board[x][i] == num) return false;
        if(board[i][y] == num) return false; 
    }

    //Check inner box
    int s = sqrt(n);
    // get upper left corner coords
    int x0 = (x/s)*s;
    int y0 = (y/s)*s;

    for(int i=x0; i<x0+s; i++){
        for(int j=y0; j<y0+s; j++){
            if(board[i][j] == num) return false;
        }
    }


    return true;
}


bool sudoku(int board [][9], int x, int y, int n){
    // cout<<x<<" "<<y<<"\n";
    // Base case
    if(x==n){
        // Gone through all rows, print the board
        for(int k=0; k<n; k++){
            for(int l=0; l<n; l++) cout<<board[k][l]<<" ";
            cout<<endl;
        }
        cout<<endl;
        return true;
    }

    if(y==n){
        // Go to next row
        return sudoku(board, x+1, 0, n);
    }

    if(board[x][y] != 0) return sudoku(board, x, y+1, n);

    // Recursion
    // Try all numbers
    for(int num =1; num<= n; num++){
        if(isSafe(board, x, y, n, num)){
            board[x][y] = num;
            bool restPlaced = sudoku(board, x, y+1, n);
            if(restPlaced) return true;
            board[x][y] = 0;  //Remove the placed number
        }
    }

    return false;  // Couldn't place anywhere...
}

int main(){
    int board[][9] = {{5, 3, 0, 0, 7, 0, 0, 0, 0},
                    {6, 0, 0, 1, 9, 5, 0, 0, 0},
                    {0, 9, 8, 0, 0, 0, 0, 6, 0},
                    {8, 0, 0, 0, 6, 0, 0, 0, 3},
                    {4, 0, 0, 8, 0, 3, 0, 0, 1},
                    {7, 0, 0, 0, 2, 0, 0, 0, 6},
                    {0, 6, 0, 0, 0, 0, 2, 8, 0},
                    {0, 0, 0, 4, 1, 9, 0, 0, 5},
                    {0, 0, 0, 0, 8, 0, 0, 7, 9}};
    
    
    sudoku(board, 0, 0, 9);

    return 0;
}