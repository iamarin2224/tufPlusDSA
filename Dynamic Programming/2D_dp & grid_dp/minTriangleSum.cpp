#include <iostream>
using namespace std;

//? Memoization
int minTriangleHelper(vector<vector<int>>& triangle, int row, int col, vector<vector<int>> &dp){
    if (col<0 || col>=triangle[row].size()) return INT_MAX;

    if (dp[row][col] != -1) return dp[row][col];

    if (row == 0) return dp[0][0] = triangle[0][0];

    return dp[row][col] = triangle[row][col] + min(
        minTriangleHelper(triangle, row-1, col, dp),
        minTriangleHelper(triangle, row-1, col-1, dp)
    );
}

int minTriangleSum(vector<vector<int>>& triangle) {
    int n = triangle.size();

    vector<vector<int>> dp(n);

    for (int i=0; i<n; i++){
        dp[i].resize(i+1, -1);
    }

    int ans = INT_MAX;

    for (int i=0; i<triangle[n-1].size(); i++){
        ans = min(ans, minTriangleHelper(triangle, n-1, i, dp));
    }

    return ans;
}

//? Tabulation
int minTriangleSum(vector<vector<int>>& triangle) {
    int n = triangle.size();

    vector<vector<int>> dp(n);

    for (int i=0; i<n; i++){
        dp[i].resize(i+1, 0);
    }

    dp[0][0] = triangle[0][0];

    int up, upLeft;

    for (int i=1; i<n; i++){
        for (int j=0; j<triangle[i].size(); j++){
            up = INT_MAX, upLeft = INT_MAX;

            if (j != triangle[i].size()-1) up = dp[i-1][j];
            if (j != 0) upLeft = dp[i-1][j-1];

            dp[i][j] = triangle[i][j] + min(up, upLeft);
        }
    }

    int ans = INT_MAX;
    
    for (int i=0; i<triangle[n-1].size(); i++){
        ans = min(ans, dp[n-1][i]);
    }

    return ans;
}

//? Optimised Tabulation
int minTriangleSum(vector<vector<int>>& triangle) {
    int n = triangle.size();

    vector<int> prev(triangle[n-1].size(), 0);
    prev[0] = triangle[0][0];

    int up, upLeft;

    for (int i=1; i<n; i++){
        vector<int> cur(triangle[i].size());
        
        for (int j=0; j<triangle[i].size(); j++){
            up = INT_MAX, upLeft = INT_MAX;

            if (j != triangle[i].size()-1) up = prev[j];
            if (j != 0) upLeft = prev[j-1];

            cur[j] = triangle[i][j] + min(up, upLeft);
        }

        for (int j=0; j<triangle[i].size(); j++){
            prev[j] = cur[j];
        }
    }

    int ans = INT_MAX;
    
    for (int i=0; i<triangle[n-1].size(); i++){
        ans = min(ans, prev[i]);
    }

    return ans;
}