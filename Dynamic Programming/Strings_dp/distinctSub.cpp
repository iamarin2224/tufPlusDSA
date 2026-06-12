#include <iostream>
using namespace std;

#define prime 1000000007

//? Memoization
int dSHelper(string &s, string &t, int i, int j, vector<vector<int>> &dp){
    if (j<0) return 1;
    if (i<0) return 0;

    if (dp[i][j] != -1) return dp[i][j];

    if (s[i]==s[j]){
        return dp[i][j] = (dSHelper(s, t, i-1, j-1, dp) + dSHelper(s, t, i-1, j, dp))%prime;
    }

    return dp[i][j] = dSHelper(s, t, i-1, j, dp);
}

int distinctSubsequences(string s, string t) {
    int n = s.size(), m = t.size();

    vector<vector<int>> dp(n, vector<int>(m, -1));

    return dSHelper(s, t, n-1, m-1, dp);
}

//?Tabulation
int distinctSubsequences(string s, string t) {
    int n = s.size(), m = t.size();

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for (int i=0; i<=n; i++){
        dp[i][0] = 1;
    }

    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            if (s[i-1] == t[j-1]){
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j])%prime;
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][m];
}

//? Optimised Tabulation
int distinctSubsequences(string s, string t) {
    int n = s.size(), m = t.size();

    vector<int> prev(m+1, 0);

    prev[0]=1;

    for (int i=1; i<=n; i++){
        for (int j=m; j>=1; j--){
            if (s[i-1] == t[j-1]){
                prev[j] = (prev[j-1] + prev[j])%prime;
            }
        }
    }

    return prev[m];
}