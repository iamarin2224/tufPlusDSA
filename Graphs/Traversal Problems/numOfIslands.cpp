#include <iostream>
using namespace std;

void dfs(int row, int col, vector<vector<char>>& grid, vector<vector<int>>& vis){
    int n = grid.size();
    int m = grid[0].size();

    vis[row][col] = 1;

    int rows[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    int cols[8] = {-1, -1, -1, 0, 0, 1, 1, 1};

    for (int i=0; i<8; i++){
        int newRow = row + rows[i];
        int newCol = col + cols[i];

        if (
            newRow >= 0 && newRow < n &&
            newCol >=0 && newCol < m &&
            grid[newRow][newCol] == '1' &&
            !vis[newRow][newCol]
        ){
            dfs(newRow, newCol, grid, vis);
        }
    }
}

int numIslands(vector<vector<char>> &grid){
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> vis(n, vector<int>(m, 0));
    int count = 0;

    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (grid[i][j] == '1' && !vis[i][j]){
                count++;
                dfs(i, j, grid, vis);
            }
        }
    }

    return count;
}