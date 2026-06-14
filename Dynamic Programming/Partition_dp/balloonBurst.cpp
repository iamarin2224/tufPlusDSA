#include <iostream>
using namespace std;

//? Memoization
int f(vector<int>& nums, int i, int j, vector<vector<int>>& dp){
    if (i > j) return 0;

    if (dp[i][j] != -1) return dp[i][j];

    int ans = INT_MIN;
    for (int k=i; k<=j; k++){
        int sum = nums[i-1]*nums[k]*nums[j+1] + f(nums, i, k-1, dp) + f(nums, k+1, j, dp);
        ans = max(ans, sum);
    }

    return dp[i][j] = ans;
}

int maxCoins(vector<int>& nums){
    nums.push_back(1);
    nums.insert(nums.begin(), 1);

    int n = nums.size();

    vector<vector<int>> dp(n, vector<int>(n, -1));

    return f(nums, 1, n-2, dp);
}

//? Tabulation
int maxCoins(vector<int>& nums){
    nums.push_back(1);
    nums.insert(nums.begin(), 1);

    int n = nums.size();

    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int i=n-2; i>=1; i--){
        for (int j=i; j<=n-2; j++){
            int ans = INT_MIN;

            for (int k=i; k<=j; k++){
                int sum = nums[i-1]*nums[k]*nums[j+1] + dp[i][k-1] + dp[k+1][j];
                ans = max(ans, sum);
            }

            dp[i][j] = ans;
        }
    }

    return dp[1][n-2];
}