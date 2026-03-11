#include <iostream>
using namespace std;

int orangesRotting(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();

    int time = 0;               
    
    int total = 0;              //Count of total oranges
    int countRotten = 0;        //Count of current rotten oranges

    queue<pair<int, int>> q;    //Queue required for bfs

    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (grid[i][j] != 0) total++;           //Have the initial total count
            if (grid[i][j] == 2) q.push({i, j});    //Push all existing rotten oranges
        }
    }

    int rows[4] = {-1, 1, 0, 0};
    int cols[4] = {0, 0, 1, -1};

    while (!q.empty()){
        int k = q.size();
        countRotten += k;   //Increase rotten count by the amount we have currently

        while (k--){
            //Get the top most rotten
            int row = q.front().first;
            int col = q.front().second; 
            q.pop();

            //Traverse its 4 neighbours and mark them rotten and push to queue
            for (int i=0; i<4; i++){
                int newRow = row + rows[i];
                int newCol = col + cols[i];

                if (
                    newRow >= 0 && newRow < n &&
                    newCol >=0 && newCol < m &&
                    grid[newRow][newCol] == 1
                ){
                    grid[newRow][newCol] = 2;
                    q.push({newRow, newCol});
                }
            }
        }

        if (!q.empty()) time++;     //If queue is not empty, oranges were rotten so inc time
    }

    if (total == countRotten) return time;

    return -1;
}