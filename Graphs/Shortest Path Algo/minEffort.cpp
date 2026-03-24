#include <iostream>
using namespace std;

int MinimumEffort(vector<vector<int>> &heights) {
    int n = heights.size();
    int m = heights[0].size();
    
    priority_queue<
        pair<int, pair<int, int>>,
        vector<pair<int, pair<int, int>>>,
        greater<pair<int, pair<int, int>>>
    > pq;

    vector<vector<int>> effort(n, vector<int>(m, 1e9));

    effort[0][0] = 0;
    pq.push({0, {0, 0}});

    int rows[4] = {0, 0, 1, -1};
    int cols[4] = {1, -1, 0, 0};

    while (!pq.empty()){
        int maxCurEffort = pq.top().first;
        int row = pq.top().second.first;
        int col = pq.top().second.second;
        pq.pop();

        for (int i=0; i<4; i++){
            int nRow = row + rows[i];
            int nCol = col + cols[i];

            if(
                nRow >= 0 && nRow < n &&
                nCol >= 0 && nCol < m
            ){
                if (max(abs(heights[row][col]-heights[nRow][nCol]), maxCurEffort) < effort[nRow][nCol]){
                    effort[nRow][nCol] = max(abs(heights[row][col]-heights[nRow][nCol]), maxCurEffort);
                    pq.push({effort[nRow][nCol], {nRow, nCol}});
                }
            }
        }
    }

    return effort[n-1][m-1];
}