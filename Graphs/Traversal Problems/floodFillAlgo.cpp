#include <iostream>
using namespace std;

void dfs(int row, int col, int& stColor, int& newColor, vector<vector<int>>& image, vector<vector<int>>& vis){
    int n = image.size();
    int m = image[0].size();

    vis[row][col] = 1;
    image[row][col] = newColor;

    int rows[4] = {-1, 1, 0, 0};
    int cols[4] = {0, 0, -1, 1};

    for (int i=0; i<4; i++){
        int newRow = row + rows[i];
        int newCol = col + cols[i];

        if (
            newRow >= 0 && newRow < n &&
            newCol >=0 && newCol < m &&
            image[newRow][newCol] == stColor &&
            !vis[newRow][newCol]
        ){
            dfs(newRow, newCol, stColor, newColor, image, vis);
        }
    }
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor) {
    int n = image.size();
    int m = image[0].size();

    vector<vector<int>> vis(n, vector<int>(m, 0));

    int stColor = image[sr][sc];

    dfs(sr, sc, stColor, newColor, image, vis);

    return image;
}