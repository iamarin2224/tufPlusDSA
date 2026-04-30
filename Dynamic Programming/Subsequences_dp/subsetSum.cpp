#include <iostream>
using namespace std;

//? Memoization
bool helper(vector<int> &arr, int i, int target, vector<vector<int>> &dp){
    if (target == 0) return true;

    if (dp[i][target] != -1) return dp[i][target];

    if (i == 0) return arr[0] == target;

    bool notTake, take = false;

    notTake = helper(arr, i-1, target, dp);

    if (arr[i] <= target) take = helper(arr, i-1, target-arr[i], dp);

    return dp[i][target] = notTake || take;
}

bool isSubsetSum(vector<int>arr, int target){
    int n = arr.size();

    vector<vector<int>> dp(n, vector<int>(target+1, -1));

    return helper(arr, n-1, target, dp);
}

//? Tabulation
bool isSubsetSum(vector<int>arr, int target){
    int n = arr.size();

    vector<vector<bool>> dp(n, vector<bool>(target+1, false));

    if (arr[0] <= target) dp[0][arr[0]] = true;

    for (int i=0; i<n; i++){
        dp[i][0] = true;
    }

    for (int i=1; i<n; i++){
        for (int t=0; t<=target; t++){
            bool notTake = dp[i-1][t];
            bool take = false;
            if (arr[i] <= t) take = dp[i-1][t-arr[i]];

            dp[i][t] = notTake || take;
        }
    }

    return dp[n-1][target];
}

//? Optimised Tabulation
bool isSubsetSum(vector<int>arr, int target){
    int n = arr.size();

    vector<bool> prev(target+1, false);

    prev[0] = true;
    if (arr[0] <= target) prev[arr[0]] = true;

    for (int i=1; i<n; i++){
        vector<bool> cur(target+1, false);

        for (int t=0; t<=target; t++){
            bool notTake = prev[t];
            bool take = false;
            if (arr[i] <= t) take = prev[t-arr[i]];

            cur[t] = notTake || take;
        }

        prev.swap(cur);
        prev[0] = true;
    }

    return prev[target];
}