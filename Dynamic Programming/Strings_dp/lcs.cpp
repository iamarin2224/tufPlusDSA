#include <iostream>
using namespace std;

//? Memoization
int lcsHelper(string& str1, string& str2, int i, int j, vector<vector<int>>& dp){
    if (i < 0 || j < 0) return 0;

    if (dp[i][j] != -1) return dp[i][j];
    
    if (str1[i] == str2[j]) return dp[i][j] = 1 + lcsHelper(str1, str2, i-1, j-1, dp);
    
    return dp[i][j] = max(
        lcsHelper(str1, str2, i, j-1, dp),
        lcsHelper(str1, str2, i-1, j, dp)
    );
}

int lcs(string& str1, string& str2) {
    vector<vector<int>> dp(str1.size(), vector<int>(str2.size(), -1));

    return lcsHelper(str1, str2, str1.size()-1, str2.size()-1, dp);
}

//? Tabulation
int lcs(string& str1, string& str2) {
    int m = str1.size(); int n = str2.size();

    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

    for (int j=0; j<n; j++){
        dp[0][j] = 0;
        dp[j][0] = 0;
    }

    for (int i=1; i<=m; i++){
        for (int j=1; j<=n; j++){
            if (str1[i-1] == str2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];

            else dp[i][j] = max (dp[i][j-1],dp[i-1][j]);
        }
    }

    return dp[m][n];
}

//? Optiimised Tabulation
int lcs(string& str1, string& str2) {
    int m = str1.size(); int n = str2.size();

    vector<int> prev(n+1, 0);

    for (int i=1; i<=m; i++){
        vector<int> curr(n+1, 0);
        curr[0] = 0;

        for (int j=1; j<=n; j++){
            if (str1[i-1] == str2[j-1]) curr[j] = 1 + prev[j-1];

            else curr[j] = max (curr[j-1], prev[j]);
        }

        prev.swap(curr);
    }

    return prev[n];
}