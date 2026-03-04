#include <iostream>
using namespace std;

int dfs(int row, int col, int& nodeCount, vector<vector<int>>& grid, vector<vector<int>>& vis){
    int n = grid.size();
    int m = grid[0].size();

    vis[row][col] = 1;

    //To keep the count of nodes traversed in current traversal
    nodeCount++;

    int rows[4] = {-1, 1, 0, 0};
    int cols[4] = {0, 0, -1, 1};

    for (int i=0; i<4; i++){
        int newRow = row + rows[i];
        int newCol = col + cols[i];

        //Mark visited array as '2' if we can reach boundary from current

        if (newRow < 0 || newRow >= n || newCol < 0 || newCol >= m) {
            vis[row][col] = 2; 
            return 0;
        }

        if (vis[newRow][newCol] == 2) {
            vis[row][col] = 2;
            return 0;
        }

        if (
            grid[newRow][newCol] == 1 &&
            !vis[newRow][newCol]
        ){
            if (dfs(newRow, newCol, nodeCount, grid, vis) == 0) {
                vis[row][col] = 2;
                return 0;
            }
        }
    }

    //Return the nodes in current traversal if boundary can't be reached
    return nodeCount;
}

int numberOfEnclaves(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> vis(n, vector<int>(m, 0));

    int count = 0;
    int nodeCount = 0;

    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (grid[i][j] == 1 && !vis[i][j]){
                nodeCount = 0;
                count+= dfs(i, j, nodeCount, grid, vis);
            }
        }
    }

    return count;
}


// TUF Apprach (Standardised approach)

void bfs(vector<vector<int>> &grid, queue<pair<int,int>> &q, vector<vector<bool>> &vis) {
    int n = grid.size();
    int m = grid[0].size(); 

    while(!q.empty()) {
            // Get the cell from queue
            auto cell = q.front();
            q.pop();
            
            int row = cell.first;
            int col = cell.second;

            int rows[4] = {-1, 1, 0, 0};
            int cols[4] = {0, 0, -1, 1};
            
            for(int i=0; i < 4; i++) {
                int newRow = row + rows[i]; 
                int newCol = col + cols[i]; 
                
                if(
                    newRow >= 0 && newRow < n &&
                    newCol >=0 && newCol < m && 
                    grid[newRow][newCol] == 1 && 
                    vis[newRow][newCol] == false
                ){
                    vis[newRow][newCol] = true;
                    q.push({newRow, newCol});
                }
            }
        }
}

int numberOfEnclaves(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    
    queue <pair<int,int>> q;
    
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    
    //Traverse the grid and add border nodes, as they will be the starting points of traversals
    for(int i=0; i < n; i++) {
        for(int j=0; j < m; j++) {
            
            //If border cell, add to queue
            if((i == 0 || i == n-1 ||
                j == 0 || j == m-1) &&
                grid[i][j] == 1) {
                
                vis[i][j] = true;
                q.push({i, j});
            }
        }
    }
    
    //Perform bfs, visit all nodes reachable from boundary
    bfs(grid, q, vis);
    
    int count = 0;
    
    // Traverse the grid
    for(int i=0; i < n; i++) {
        for(int j=0; j < m; j++){
            //If unvisited, means can't reach from boundary, increase the count
            if(grid[i][j] == 1 && !vis[i][j])
                count++;
        }
    }

    return count;
}