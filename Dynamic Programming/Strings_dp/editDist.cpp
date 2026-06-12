#include <iostream>
using namespace std;

//? Memoization
int helper(string &s, string &t, int i, int j, vector<vector<int>> &dp){
    // base cases   
    if (i < 0) return j+1;
    if (j < 0) return i+1;

    if (dp[i][j] != -1) return dp[i][j];

    // main recurrance
    if (s[i] == t[j]) return dp[i][j] = helper(s, t, i-1, j-1, dp);

    int del = 1 + helper(s, t, i-1, j, dp);
    int ins = 1 + helper(s, t, i, j-1, dp);
    int rep = 1 + helper(s, t, i-1, j-1, dp);

    return dp[i][j] = min(del, min(ins, rep));
}

int editDistance(string start, string target) {
    int n = start.size(), m = target.size();

    vector<vector<int>> dp(n, vector<int>(m, -1));

    return helper(start, target, n-1, m-1, dp);
}

//? Tabulation
int editDistance(string start, string target) {
    int n = start.size(), m = target.size();

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for (int j=0; j<=m; j++){
        dp[0][j] = j;
    }

    for (int i=1; i<=n; i++){
        dp[i][0] = i;
    }

    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            if (start[i-1] == target[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            }
            else {
                int del = 1 + dp[i-1][j];
                int ins = 1 + dp[i][j-1];
                int rep = 1 + dp[i-1][j-1];

                dp[i][j] = min(del, min(ins, rep));
            }
        }
    }

    return dp[n][m];
}

//? Optimised Tabulation
int editDistance(string start, string target) {
    int n = start.size(), m = target.size();

    vector<int>prev (m+1, 0);

    for (int j=0; j<=m; j++){
        prev[j] = j;
    }

    for (int i=1; i<=n; i++){
        vector<int> curr(m+1, 0);
        curr[0] = i;

        for (int j=1; j<=m; j++){
            if (start[i-1] == target[j-1]) {
                curr[j] = prev[j-1];
            }
            else {
                int del = 1 + prev[j];
                int ins = 1 + curr[j-1];
                int rep = 1 + prev[j-1];

                curr[j] = min(del, min(ins, rep));
            }
        }

        prev.swap(curr);
    }

    return prev[m];
}