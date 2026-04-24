#include <iostream>
using namespace std;

//? Memoization
int uniquePathsHelper(int m, int n, vector<vector<int>> &dp){
    if (m<0 || n<0) return 0;
    
    if (dp[m][n] != -1) return dp[m][n];

    if (m==0 && n==0) return dp[0][0] = 1;

    return dp[m][n] = uniquePathsHelper(m-1, n, dp) + uniquePathsHelper(m, n-1, dp);    
}

int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, -1));

    return uniquePathsHelper(m-1, n-1, dp);
}

//? Tabulation
int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, 0));

    dp[0][0] = 1;

    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            if (j>0) dp[i][j] += dp[i][j-1];
            if (i>0) dp[i][j] += dp[i-1][j];
        }
    }

    return dp[m-1][n-1];
}

//? Optimised Tabulation
int uniquePaths(int m, int n) {
    vector<int> prev(n, 0);

    for (int i=0; i<m; i++){
        vector<int> cur(n, 0);

        for (int j=0; j<n; j++){
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