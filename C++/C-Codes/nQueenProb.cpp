#include<unordered_map>
#include<vector>
#include <iostream>
using namespace std;

unordered_map<int,bool> rowCheck;
unordered_map<int, bool> upperLeftDiagonalCheck;
unordered_map<int, bool> lowerLeftDiagonalCheck;

void printSol(vector<vector<char>> &board, int n){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<board[i][j] <<" ";
        }
        cout<<endl;
    }
    cout<<endl<<endl;
}

bool isSafe(int row, int col, vector<vector<char>> &board, int n){
            if(rowCheck[row] = true){
                return false;}
            if(upperLeftDiagonalCheck[n-1+col-row] = true){
                return false;}
            if(lowerLeftDiagonalCheck[row+col] = true){
                return false;
            return true;
    // while (col >= 0)
    // {   //check row
    //     if(board[row][col] == 'Q'){
    //         return false;
    //     }
    //     col--;
    // }
    // while (row>= 0 && col >= 0)
    // {
    //     if (board[row][col] == 'Q')
    //     {
    //         return false;
    //     }
    //     row--, col--;
    // }
    // while (row< n && col >= 0)
    // {
    //   if (board[row][col] == 'Q')
    //    {
    //     return false;
    //    }
    //    col--;
    //    row++;
    // }
    // return true;
}

void solve(vector<vector<char>> &board, int col, int n){
    if (col>= n)
    {
        printSol(board, n);
        return;
    }
    for (int row = 0; row < n; row++)
    {
        if (isSafe(row, col, board, n))
        {
            board[row][col] = 'Q';
            rowCheck[row] = true;
            upperLeftDiagonalcheck[n-1+col-row] = true;
            lowerLeftDiagonalcheck[row+col] = true;

            //RR
            solve(board, col+1, n);

            //backtracking
            board[row][col] = '-';
            rowCheck[row] = false;
            upperLeftDiagonalcheck[n-1+col-row] = false;
            lowerLeftDiagonalcheck[row+col] = false;
        }
        
    }
        
}

int main()
{
int n = 4;
vector<vector<char>>board(n, vector<char>(n,'-'));
int col = 0;
solve(board, col,n);
return 0;
}
