#include<iostream>
using namespace std;

bool isSafe(int board [][100], int row, int c, int n){
    // Check diagonals for a queen
    //upper left
    int i=row, j=c;
    while(i >=0 && j >=0){
        if(board[i][j] == 1) return false;
        i--; j--;
    }
    //upper right
    i=row, j=c;
    while(j <n && i >=0){
        if(board[i][j] == 1) return false;
        i--; j++;
    }

    //check vertically
    i=row;
    while(i >= 0){
        if(board[i][c] == 1) return false;
        i--;
    } 

    return true;
}

//row -> row index, n is dim of board
bool placeQueens(int board [][100], int row, int n){
    // Base case
    if(row==n){
        // Gone through all rows, print the board
        for(int k=0; k<n; k++){
            for(int l=0; l<n; l++) cout<<board[k][l]<<" ";
            cout<<endl;
        }
        cout<<endl;
        return false;  // To print all solutions
    }

    // Recursion
    //traverse column wise
    for(int j=0; j<n; j++){
        if(isSafe(board, row, j, n)){
            // Place queen
            board[row][j] = 1;
            bool restPlaced = placeQueens(board, row+1, n);
            if(restPlaced) return true;
            else board[row][j] = 0;  //Remove the placed queen
        }
    }

    return false;  // Couldn't place anywhere...
}

int main(){
    int board[100][100];
    
    int n;
    cin>>n;

    placeQueens(board, 0, n);

    return 0;
}