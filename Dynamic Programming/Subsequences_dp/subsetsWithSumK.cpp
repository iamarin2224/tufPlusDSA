#include <iostream>
using namespace std;

#define MOD 1000000007

//? Memoization
int helper(vector<int> &arr, int i, int target, vector<vector<int>> &dp){
    if (target == 0) return dp[i][target] = 1;

    if (dp[i][target] != -1) return dp[i][target];

    if (i == 0) return dp[0][target] = int(arr[0] == target);

    int notTake = helper(arr, i-1, target, dp);

    int take = 0;
    if (arr[i] <= target) take = helper(arr, i-1, target-arr[i], dp);

    return dp[i][target] = (notTake+take)%MOD;
}

int perfectSum(vector<int>&arr, int K){
    int n = arr.size();

    vector<vector<int>> dp(n, vector<int>(K+1, -1));

    return helper(arr, n-1, K, dp);
}

//? Tabulation
int perfectSum(vector<int>&arr, int K){
    int n = arr.size();

    vector<vector<int>> dp(n, vector<int>(K+1, 0));

    for (int i=0; i<n; i++){
        dp[i][0] = 1;
    }

    if (arr[0] <= K) dp[0][arr[0]] = 1;

    for (int i=1; i<n; i++){
        for (int t=0; t<=K; t++){
            int notTake = dp[i-1][t];
            int take = 0;
            if (arr[i] <= t) take = dp[i-1][t-arr[i]];

            dp[i][t] = (notTake+take) % MOD;
        }
    }

    return dp[n-1][K];
}

//? Optimised Tabulation
int perfectSum(vector<int>&arr, int K){
    int n = arr.size();

    vector<int> prev(K+1, 0);

    prev[0] = 1;
    if (arr[0] <= K) prev[arr[0]] = 1;

    for (int i=1; i<n; i++){
        vector<int> cur(K+1, 0);

        for (int t=0; t<=K; t++){
            int notTake = prev[t];
            int take = 0;
            if (arr[i] <= t) take = prev[t-arr[i]];

            cur[t] = (notTake+take) % MOD;
        }

        prev.swap(cur);
        prev[0] = 1;
    }

    return prev[K];
}