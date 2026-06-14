#include <iostream>
using namespace std;

//! My solution using TC: n³ 

bool checkPal(string &s, int i, int j){
    while (i <= j){
        if (s[i] != s[j]) return false;
        i++; j--;
    }

    return true;
}

//? Memoization
int f(string &s, int i, int j, vector<vector<int>>& dp){
    if (i == j) return 0;

    if (dp[i][j] != -1) return dp[i][j];

    if (checkPal(s, i, j)) return dp[i][j] = 0;

    int ans = 1e9;
    for (int k=i; k<j; k++){
        int cuts = 1 + f(s, i, k, dp) + f(s, k+1, j, dp);
        ans = min(ans, cuts);
    }

    return dp[i][j] = ans;
}

int minCut(string s){
    int n = s.size();

    vector<vector<int>> dp(n, vector<int>(n, -1));

    return f(s, 0, n-1, dp);
}

//? Tabulation
int minCut(string s){
    int n = s.size();

    vector<vector<int>> dp(n, vector<int>(n, -1));

    for (int i=n-1; i>=0; i--){
        for (int j=i; j<n; j++){
            if (checkPal(s, i, j)) dp[i][j] = 0;
        }
        dp[i][i] = 0;
    }

    for (int i=n-1; i>=0; i--){
        for (int j=i+1; j<n; j++){
            if (dp[i][j] == 0) continue;

            int ans = 1e9;

            for (int k=i; k<j; k++){
                int cuts = 1 + dp[i][k] + dp[k+1][j];
                ans = min(ans, cuts);
            }

            dp[i][j] = ans;
        }
    }

    return dp[0][n-1];
}

//! Standard Solution

//? Memoization
int helper(string &s, int i, vector<int> &dp){
    if (i == s.size()) return 0;

    if (dp[i] != -1) return dp[i];

    int ans = 1e9;
    for (int j=i; j<s.size(); j++){     
        if (checkPal(s, i, j)){
            int cuts = 1 + helper(s, j+1, dp);
            ans = min(ans, cuts);
        }
    }

    return dp[i] = ans;
}

int minCut(string s){
    int n = s.size();

    vector<int> dp(n, -1);

    return helper(s, 0, dp)-1;
}

//? Tabulation
int minCut(string s){
    int n = s.size();

    vector<int> dp(n+1, 0);

    for (int i=n-1; i>=0; i--){
        int ans = 1e9;
        for (int j=i; j<s.size(); j++){     
            if (checkPal(s, i, j)){
                int cuts = 1 + dp[j+1];
                ans = min(ans, cuts);
            }
        }

        dp[i] = ans;
    }

    return dp[0]-1;
}