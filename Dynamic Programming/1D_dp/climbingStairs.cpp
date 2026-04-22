#include <iostream>
using namespace std;

//? Memoization
int climbStairsHelper(int n, vector<int>& dp){
    if (n <= 1) return 1;

    if (dp[n] != -1) return dp[n];

    return dp[n] = climbStairsHelper(n-1, dp) + climbStairsHelper(n-2, dp);
}

int climbStairs(int n) {
    vector<int> dp(n+1, -1);

    return climbStairsHelper(n, dp);
}

//? Tabulation
int climbStairs(int n) {
    if (n <= 1) return 1;

    vector<int> dp(n+1);

    dp[0] = 1;
    dp[1] = 1;
    
    for (int i=2; i<=n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}

//? Optimised Tabulation
int climbStairs(int n) {
    if (n <= 1) return 1;

    int prev2 = 1;
    int prev1 = 1;
    
    for (int i=2; i<=n; i++){
        int cur = prev1 + prev2;
        prev2 = prev1;
        prev1 = cur;
    }

    return prev1;
}