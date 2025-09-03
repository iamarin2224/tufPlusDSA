#include <bits/stdc++.h>
using namespace std;

void func(vector<vector<int>> &grid, string &path, vector<string> &ans, int row, int col){
    int n = grid.size();

    if (row == n-1 && col == n-1){
        ans.push_back(path);
        return;
    }

    //blocking the current cell so that we do not comeback here
    grid[row][col] = 0;

    //going right
    if (col != n-1 && grid[row][col+1] == 1){
        path += "R";
        func(grid, path, ans, row, col+1);
        path.pop_back();
    }
    
    //going left
    if (col != 0 && grid[row][col-1] == 1){
        path += "L";
        func(grid, path, ans, row, col-1);
        path.pop_back();
    }

    //going up
    if (row != 0 && grid[row-1][col] == 1){
        path += "U";
        func(grid, path, ans, row-1, col);
        path.pop_back();
    }

    //going down
    if (row != n-1 && grid[row+1][col] == 1){
        path += "D";
        func(grid, path, ans, row+1, col);
        path.pop_back();
    }

    grid[row][col] = 1;
}

vector<string> findPath(vector<vector<int>> &grid) {
    int n = grid.size();

    vector<string> ans = {};

    if (grid[0][0] == 0 || grid[n-1][n-1]) return {};

    string path = "";

    func(grid, path, ans, 0, 0);

    return ans;
}