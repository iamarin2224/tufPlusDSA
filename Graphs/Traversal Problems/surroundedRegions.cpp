#include <iostream>
using namespace std;

vector<vector<char>> fill(vector<vector<char>> mat) {
    int n = mat.size();
    int m = mat[0].size();
    
    queue<pair<int, int>> q;
    vector<vector<bool>> vis(n, vector<bool>(m, false));

    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if ((i == 0 || i == n-1 || j == 0 || j == m-1) && mat[i][j] == 'O'){
                vis[i][j] = true;
                q.push({i, j});
            }
        }
    }

    int rows[4] = {-1, 1, 0, 0};
    int cols[4] = {0, 0, -1, 1};

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
                mat[newRow][newCol] == 'O' &&
                vis[newRow][newCol] == false
            ){
                vis[newRow][newCol] = true;
                q.push({newRow, newCol});
            }
        }
    }

    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (mat[i][j] == 'O' && vis[i][j] == false){
                mat[i][j] = 'X';
            }
        }
    }

    return mat;
}