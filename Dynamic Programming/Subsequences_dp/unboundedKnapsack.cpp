#include <iostream>
using namespace std;

//? Memoization
int knapsackHelper(vector<int>& wt, vector<int>& val, int i, int W, vector<vector<int>> &dp){
    if (W == 0) return dp[i][W] = 0;

    if (dp[i][W] != -1) return dp[i][W];

    if (i == 0){
        if (wt[0] <= W) {
            int factor = W/wt[0];

            return factor*val[0];
        }
        else return dp[0][W] = 0;
    }

    int notTake = knapsackHelper(wt, val, i-1, W, dp);

    int take = 0;
    if (wt[i] <= W) take = val[i] + knapsackHelper(wt, val, i, W-wt[i], dp);

    return dp[i][W] = max(notTake, take);
}

int unboundedKnapsack(vector<int>& wt, vector<int>& val, int n, int W) {
    vector<vector<int>> dp(n, vector<int>(W+1, -1));

    return knapsackHelper(wt, val, n-1, W, dp);
}

//? Tabulation
int unboundedKnapsack(vector<int>& wt, vector<int>& val, int n, int W) {
    vector<vector<int>> dp(n, vector<int>(W+1, 0));

    for (int w=wt[0]; w<=W; w++){
        dp[0][w] = (w/wt[0]) * val[0];
    }

    for (int i=1; i<n; i++){
        for (int w=1; w<=W; w++){
            int notTake = dp[i-1][w];
            int take = 0;
            if (wt[i] <= w) take = val[i] + dp[i][w-wt[i]];

            dp[i][w] = max(notTake, take);
        }
    }

    return dp[n-1][W];
}

//? Optimised Tabulation
int unboundedKnapsack(vector<int>& wt, vector<int>& val, int n, int W) {
    vector<int> prev(W+1, 0);

    for (int w=wt[0]; w<=W; w++){
        prev[w] = (w/wt[0]) * val[0];
    }

    for (int i=1; i<n; i++){
        vector<int> cur(W+1, 0);

        for (int w=0; w<=W; w++){
            int notTake = prev[w];
            int take = 0;
            if (wt[i] <= w) take = val[i] + cur[w-wt[i]];

            cur[w] = max(notTake, take);
        }

        prev.swap(cur);
    }

    return prev[W];
}