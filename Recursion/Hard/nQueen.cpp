#include <bits/stdc++.h>
using namespace std;

bool isPlacingSafe(int row, int col, vector<string> &board){
    int r = row, c = col;

    //check top
    while (r >= 0){
        if (board[r][c] == 'Q') return false;
        r--;
    }

    r = row, c = col;

    //check upper left
    while (r >= 0 && c >= 0){
        if (board[r][c] == 'Q') return false;
        r--, c--;
    }

    r = row, c = col;

    //check upper right
    while (r >= 0 && col < board.size()){
        if (board[r][c] == 'Q') return false;
        r--, c++;
    }

    //note as til now we have placed only in the upper rows, so we do not need to check any downward or same level direction, just the upper 3 directions

    return true;
}

void func(int row, vector<string> &board, vector<vector<string>> &ans){
    //put the current combination in ans if reached end
    if (row == board.size()){
        ans.push_back(board);
        return;
    }

    //try to place queen at every col
    for (int col = 0; col < board.size(); col++){
        if (isPlacingSafe(row, col, board)){    //check if placing safe
            board[row][col] = 'Q';  //place after check
            func(row+1, board, ans);    //try to place in next row
            board[row][col] = '.';  //backtrack and remove placing to explore other options
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    vector<string> board(n, string(n, '.'));

    func(0, board, ans);

    return ans;
}