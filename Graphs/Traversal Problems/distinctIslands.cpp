#include <iostream>
#include <unordered_set>
using namespace std;

void dfs(int row, int col, vector<vector<int>>& grid, vector<vector<bool>>& vis, string& curPath){
    int n = grid.size();
    int m = grid[0].size();

    vis[row][col] = true;

    int rows[4] = {1, -1, 0, 0};
    int cols[4] = {0, 0, -1, 1};

    for (int i=0; i<4; i++){
        int newRow = row + rows[i];
        int newCol = col + cols[i];

        if (
            newRow >= 0 && newRow < n &&
            newCol >=0 && newCol < m &&
            grid[newRow][newCol] == 1 &&
            !vis[newRow][newCol]
        ){
            curPath += to_string(i); //add the direction in the path
            dfs(newRow, newCol, grid, vis, curPath);
            curPath += 'B'; //to imply backtrack in the path
        }
    }
}


int countDistinctIslands(vector<vector<int>> &grid){
    int n = grid.size();
    int m = grid[0].size();
    
    unordered_set<string> st;
    
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    
    string curPath = "";
    
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (grid[i][j] == 1 && vis[i][j] == false){
                curPath = "";
                dfs(i, j, grid, vis, curPath);
                st.insert(curPath);
            }
        }   
    }
    
    return st.size();
}

//Safer alternative to store the unique islands is to use relative coordinates by carrying baseRow and baseCol in dfs and putting row-baseRow in a list (vector<pair<int, int>>) and adding that to set