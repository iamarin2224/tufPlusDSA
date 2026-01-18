#include <iostream>
using namespace std;

bool isPlacingSafe(vector<vector<char>>& board, int row, int col, int num){
    //check box
    for (int i = row - (row%3); i <= ((row - (row%3))+2); i++){
        for (int j = col - (col%3); j <= ((col - (col%3))+2); j++){
            if (board[i][j] == '.') continue;
            if ((int)(board[i][j] - '0') == num) return false;
        }
    }

    //check row
    for (int i=0; i<9; i++){
        if (board[row][i] == '.') continue;
        if ((int)(board[row][i] - '0') == num) return false;
    }

    //check col
    for (int i=0; i<9; i++){
        if (board[i][col] == '.') continue;
        if ((int)(board[i][col] - '0') == num) return false;
    }

    return true;
}

bool func(vector<vector<char>>& board, int row, int col){
    if (row == 9){
        return true;
    }

    if (col == 9){
        return func(board, row+1, 0);
    }

    if (board[row][col] != '.'){
        return func(board, row, col+1);
    }

    for (int num = 1; num <= 9; num++){
        if (isPlacingSafe(board, row, col, num)){
            board[row][col] = (char)((int)'0' + num);
            if (func(board, row, col+1)) return true; //if filled don't backtrack
            board[row][col] = '.';
        }
    }
    
    return false;
}

void solveSudoku(vector<vector<char>>& board) {
    func(board, 0, 0);
}