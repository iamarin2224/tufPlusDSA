#include <iostream>
using namespace std;

//? Memoization
int minFallingPathSumHelper(vector<vector<int>>& matrix, int row, int col, vector<vector<int>> &dp){
    if (col<0 || col>=matrix[0].size()) return INT_MAX;

    if (dp[row][col] != -1) return dp[row][col];

    if (row == 0) return dp[0][col] = matrix[0][col];

    int minNextPath = INT_MAX;

    for (int i=-1; i<=1; i++){
        minNextPath = min(minNextPath, minFallingPathSumHelper(matrix, row-1, col+i, dp));
    }

    return dp[row][col] = matrix[row][col] + minNextPath;
}

int minFallingPathSum(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();

    vector<vector<int>> dp(n, vector<int>(m, -1));

    int ans = INT_MAX;

    for (int i=0; i<m; i++){
        ans = min(ans, minFallingPathSumHelper(matrix, n-1, i, dp));
    }

    return ans;
}

//? Tabulation
int minFallingPathSum(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();

    vector<vector<int>> dp(n, vector<int>(m, 0));

    int minPath;

    for (int i=0; i<m; i++){
        dp[0][i] = matrix[0][i];
    }

    for (int i=1; i<n; i++){
        for (int j=0; j<m; j++){
            minPath = INT_MAX;

            for (int k=-1; k<=1; k++){
                if (j+k>=0 && j+k<m) minPath = min(minPath, dp[i-1][j+k]);
            }

            dp[i][j] = matrix[i][j] + minPath;
        }
    }

    int ans = INT_MAX;

    for (int i=0; i<m; i++){
        ans = min(ans, dp[n-1][i]);
    }

    return ans;
}

//? Optimised Tabulation
int minFallingPathSum(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();

    vector<int> prev(m, 0);

    int minPath;

    for (int i=0; i<m; i++){
        prev[i] = matrix[0][i];
    }

    for (int i=1; i<n; i++){
        vector<int> temp(m, 0);

        for (int j=0; j<m; j++){
            minPath = INT_MAX;

            for (int k=-1; k<=1; k++){
                if (j+k>=0 && j+k<m) minPath = min(minPath, prev[j+k]);
            }

            temp[j] = matrix[i][j] + minPath;
        }

        for (int j=0; j<m; j++){
            prev[j] = temp[j];
        }
    }

    int ans = INT_MAX;

    for (int i=0; i<m; i++){
        ans = min(ans, prev[i]);
    }

    return ans;
}