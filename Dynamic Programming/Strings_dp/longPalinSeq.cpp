#include <iostream>
using namespace std;

//? Memoization
int lpsHelper(string &s, int i, int j, vector<vector<int>>& dp){
    if (i > s.size() || j<0 || i>j) return 0;

    if (i == j) return 1;

    if (dp[i][j] != -1) return dp[i][j];

    if (s[i] == s[j]) return dp[i][j] = lpsHelper(s, i+1, j-1, dp) + 2;

    return dp[i][j] = max(
        lpsHelper(s, i+1, j, dp),
        lpsHelper(s, i, j-1, dp)
    );
}

int longestPalinSubseq(string s) {
    int n = s.size();

    vector<vector<int>> dp(n, vector<int>(n, -1));

    return lpsHelper(s, 0, n-1, dp);
}

//? Tabulation
int longestPalinSubseq(string s) {
    int n = s.size();

    vector<vector<int>> dp(n+2, vector<int>(n+2, 0));

    for (int i=1; i<=n; i++){
        dp[i][i] = 1;
    }

    for (int i=n; i>=1; i--){
        for (int j=i+1; j<=n; j++){
            if (s[i-1] == s[j-1]) dp[i][j] = dp[i+1][j-1] + 2;
            else dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
        }
    }

    return dp[1][n];
}

//? Optimised Tabulation
int longestPalinSubseq(string s) {
    int n = s.size();

    vector<int> next(n+1, 0);

    for (int i=n; i>=1; i--){
        vector<int> curr(n+1, 0);
        curr[i] = 1;

        for (int j=i+1; j<=n; j++){
            if (s[i-1] == s[j-1]) curr[j] = next[j-1] + 2;
            else curr[j] = max(next[j], curr[j-1]);
        }

        next.swap(curr);
    }

    return next[n];
}