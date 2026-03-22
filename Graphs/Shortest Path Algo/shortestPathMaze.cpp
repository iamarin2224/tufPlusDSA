#include <iostream>
using namespace std;

int shortestPath(vector<vector<int>> &grid, pair<int, int> source, pair<int, int> destination) {
    int n = grid.size();
    int m = grid[0].size();

    if (source == destination) return 0;

    if (grid[destination.first][destination.second] == 0) return -1;

    //?Not required as graph is undirected with unit weight
    // priority_queue<
    //     pair<int, pair<int, int>>,
    //     vector<pair<int, pair<int, int>>>,
    //     greater<pair<int, pair<int, int>>>
    // > pq;

    queue<pair<int, pair<int, int>>> q;

    vector<vector<int>> dist(n, vector<int>(m, 1e9));

    q.push({0, source});
    dist[source.first][source.second] = 0;

    int rows[4] = {0, 0, 1, -1};
    int cols[4] = {1, -1, 0, 0};

    while (!q.empty()){
        int dis = q.front().first;
        int row = q.front().second.first;
        int col = q.front().second.second;

        q.pop();

        for (int i=0; i<4; i++){
            int nRow = row + rows[i];
            int nCol = col + cols[i];

            if(
                nRow >= 0 && nRow < n &&
                nCol >= 0 && nCol < m &&
                grid[nRow][nCol] == 1
            ){
                if (dis + 1 < dist[nRow][nCol]){
                    dist[nRow][nCol] = dis + 1;
                    q.push({dist[nRow][nCol], {nRow, nCol}});
                }
            }
        }
    }

    if (dist[destination.first][destination.second] == 1e9) return -1;

    return dist[destination.first][destination.second];
}