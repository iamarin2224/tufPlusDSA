#include <iostream>
using namespace std;

//? Memoization
int uniquePathsHelper(vector<vector<int>>& matrix, int m, int n, vector<vector<int>> &dp){
    if (m<0 || n<0 || matrix[m][n]==1) return 0;
    
    if (dp[m][n] != -1) return dp[m][n];

    if (m==0 && n==0) return dp[0][0] = 1;

    return dp[m][n] = uniquePathsHelper(matrix, m-1, n, dp) + uniquePathsHelper(matrix, m, n-1, dp);    
}

int uniquePathsWithObstacles(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();

    vector<vector<int>> dp(m, vector<int>(n, -1));

    return uniquePathsHelper(matrix, m-1, n-1, dp);
}

//? Tabulation
int uniquePathsWithObstacles(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();

    vector<vector<int>> dp(m, vector<int>(n, 0));

    if (matrix[0][0] != 1) dp[0][0] = 1;

    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            if (matrix[i][j] == 1) {
                dp[i][j] = 0;
                continue;
            }

            if (j>0) dp[i][j] += dp[i][j-1];
            if (i>0) dp[i][j] += dp[i-1][j];
        }
    }

    return dp[m-1][n-1];
}

//? Optimised Tabulation
int uniquePathsWithObstacles(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();

    vector<int> prev(n, 0);

    for (int i=0; i<m; i++){
        vector<int> cur(n, 0);

        for (int j=0; j<n; j++){
            if (matrix[i][j] == 1) {
                cur[j] = 0;
                continue;
            }

            if (i==0 && j==0) cur[0] = 1;

            if (i>0) cur[j] += prev[j];
            if (j>0) cur[j] += cur[j-1];
        }

        for (int j=0; j<n; j++){
            prev[j] = cur[j];
        }
    }

    return prev[n-1];
}