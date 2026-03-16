#include <iostream>
using namespace std;

vector<vector<int>> nearest(vector<vector<int>> grid){
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<bool>> vis(n, vector<bool>(m, false));
    queue<pair<int, int>> q;
    
    vector<vector<int>> ans(n, vector<int>(m));

    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (grid[i][j] == 1){
                vis[i][j] = true;
                q.push({i, j});
                ans[i][j] = 0;
            }
        }
    }

    int rows[4] = {0, 0, -1, 1};
    int cols[4] = {-1, 1, 0, 0};

    while (!q.empty()){
        auto cell = q.front();
        q.pop();

        int row = cell.first;
        int col = cell.second;

        for (int i=0; i<4; i++){
            int newRow = row + rows[i];
            int newCol = col + cols[i];

            if (
                newRow >= 0 && newRow < n &&
                newCol >=0 && newCol < m &&
                grid[newRow][newCol] == 0 &&
                !vis[newRow][newCol]
            ){
                ans[newRow][newCol] = ans[row][col]+1;
                vis[newRow][newCol] = true;
                q.push({newRow, newCol});
            }
        }
    }

    return ans;
}