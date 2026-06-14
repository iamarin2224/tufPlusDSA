#include <iostream>
using namespace std;

int helper(vector<int>& nums, int i, int j, vector<vector<int>>& dp){
    if (i == j) return 0;

    if (dp[i][j] != -1) return dp[i][j];

    int ans = 1e9;
    int steps;
    for (int k=i; k<j; k++){
        steps = (nums[i-1]*nums[k]*nums[j]) + helper(nums, i, k, dp) + helper(nums, k+1, j, dp);
        ans = min(ans, steps);
    }

    return dp[i][j] = ans;
}

int matrixMultiplication(vector<int>& nums){
    int n = nums.size();

    vector<vector<int>> dp(n, vector<int>(n, -1));

    return helper(nums, 1, n-1, dp);
}

int matrixMultiplication(vector<int>& nums){
    int n = nums.size();

    vector<vector<int>> dp(n, vector<int>(n));

    for (int i=0; i<n; i++){
        dp[i][i] = 0;
    }

    for (int i=n-1; i>=1; i--){
        for (int j=i+1; j<n; j++){
            int ans = 1e9;

            for (int k=i; k<j; k++){
                int steps = nums[i-1]*nums[k]*nums[j] + dp[i][k] + dp[k+1][j];
                ans = min(ans, steps);
            }   

            dp[i][j] = ans;
        }
    }

    return dp[1][n-1];
}