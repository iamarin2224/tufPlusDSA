#include <bits/stdc++.h>
using namespace std;

bool func(vector<vector<char>> &board, string &word, int index, int row, int col){
    int n = board.size(), m = board[0].size();

    if (index == word.size()){
        return true;
    }

    char temp = board[row][col];

    board[row][col] = ' ';  //marking visited

    char letter = word[index];

    //going right
    if (col != m-1 && board[row][col+1] == letter){
        if (func(board, word, index+1, row, col+1)) return true;
    }
    
    //going left
    if (col != 0 && board[row][col-1] == letter){
        if (func(board, word, index+1, row, col-1)) return true;
    }

    //going up
    if (row != 0 && board[row-1][col] == letter){
        if (func(board, word, index+1, row-1, col)) return true;
    }

    //going down
    if (row != n-1 && board[row+1][col] == letter){
        if (func(board, word, index+1, row+1, col)) return true;
    }

    board[row][col] = temp; //backtracking and undoing the change
    return false;

}

bool exist(vector<vector<char> >& board, string word) {
    int n = board.size(), m = board[0].size();

    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (board[i][j] == word[0]){
                if (func(board, word, 1, i, j)) return true;
            }
        }
    }

    return false;
}