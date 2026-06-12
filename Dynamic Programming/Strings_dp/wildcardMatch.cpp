#include <iostream>
using namespace std;

//? Memoization
bool helper(string &str, string &pat, int i, int j, vector<vector<int>> &dp){
    if (i<0 && j<0) return true;

    if (i>=0 && j<0) return false;

    if (i<0 && j>=0){
        for (int a=0; a<=j; a++){
            if (pat[a] != '*') return false;
        }

        return true;
    }

    if (dp[i][j] != -1) return (bool)dp[i][j];

    if (pat[j] == '*'){
        return dp[i][j] = (helper(str, pat, i-1, j, dp) || helper(str, pat, i, j-1, dp));
    }

    if (pat[j] == '?' || str[i] == pat[j]){
        return dp[i][j] = helper(str, pat, i-1, j-1, dp);
    }

    return dp[i][j] = false;
}

bool wildCard(string str, string pat) {
    int n = str.size(), m = pat.size();

    vector<vector<int>> dp(n, vector<int>(m, -1));

    return helper(str, pat, n-1, m-1, dp);
}

//? Tabulation
bool wildCard(string str, string pat) {
    int n = str.size(), m = pat.size();

    vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));

    dp[0][0] = true;

    for (int j=1; j<=m; j++){
        dp[0][j] = dp[0][j-1] && (pat[j-1] == '*');
    }

    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            if (pat[j-1] == '?' || pat[j-1] == str[i-1]){
                dp[i][j] = dp[i-1][j-1];
            }
            else if (pat[j-1] == '*'){
                dp[i][j] = dp[i][j-1] || dp[i-1][j];
            }
            else {
                dp[i][j] = false;
            }
        }
    }

    return dp[n][m];    
}

//? Optimised Tabulation
bool wildCard(string str, string pat) {
    int n = str.size(), m = pat.size();

    vector<bool> prev(m+1, false);

    prev[0] = true;

    for (int j=1; j<=m; j++){
        prev[j] = prev[j-1] && (pat[j-1] == '*');
    }

    for (int i=1; i<=n; i++){
        vector<bool> curr(m+1, false);

        for (int j=1; j<=m; j++){
            if (pat[j-1] == '?' || pat[j-1] == str[i-1]){
                curr[j] = prev[j-1];
            }
            else if (pat[j-1] == '*'){
                curr[j] = curr[j-1] || prev[j];
            }
            else {
                curr[j] = false;
            }
        }

        prev.swap(curr);
    }

    return prev[m];    
}