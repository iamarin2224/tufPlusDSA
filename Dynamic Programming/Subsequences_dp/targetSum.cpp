#include <iostream>
#include <numeric>
using namespace std;

#define MOD 1000000007

//? Memoization
int targetSumhelper(vector<int> &arr, int sum, int i, int target, vector<vector<int>> &dp){
    if (target > sum || target < -sum) return 0;
    
    if (dp[i][target+sum] != -1) return dp[i][target+sum];

    if (i == 0){
        if (target==0 && arr[0]==0) return dp[0][0] = 2;
        
        return dp[0][target+sum] = (int)(abs(arr[0]) == abs(target));
    }

    int takeMinus = targetSumhelper(arr, sum, i-1, target+arr[i], dp);

    int takePlus = targetSumhelper(arr, sum, i-1, target-arr[i], dp);

    return dp[i][target+sum] = (takeMinus+takePlus)%MOD;
}

int targetSum(int n, int target, vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);

    vector<vector<int>> dp(n, vector<int>(2*sum+1, -1));

    return targetSumhelper(nums, sum, n-1, target, dp);
}

// * We can realise that this problem is exactly similar to count partitions with given diff
//* as here we assign some to + (s1) and some - (s2) diff of that = s1-s2 becomes target (diff)

//* for simplicity we rename target parameter as diff

//? Memoization
int helper(vector<int> &arr, int i, int target, vector<vector<int>> &dp){
    if (target==0 && i==0){
        if (arr[0] == 0){
            return dp[0][0] = 2;
        }
        return dp[0][0] = 1;
    }

    if (dp[i][target] != -1) return dp[i][target];

    if (i == 0) return dp[0][target] = int(arr[0] == target);

    int notTake = helper(arr, i-1, target, dp);

    int take = 0;
    if (arr[i] <= target) take = helper(arr, i-1, target-arr[i], dp);

    return dp[i][target] = (notTake+take)%MOD;
}

int targetSum(int n, int diff, vector<int>& arr) {
    int sum = accumulate(arr.begin(), arr.end(), 0);
    int required = sum-diff;

    if (required%2==1 || required<0) return 0;

    int target = (required/2)%MOD;

    vector<vector<int>> dp(n, vector<int>(target+1, -1));

    return helper(arr, n-1, target, dp);
}

//? Tabulation
int targetSum(int n, int diff, vector<int>& arr) {
    int sum = accumulate(arr.begin(), arr.end(), 0);
    int required = sum-diff;

    if (required%2==1 || required<0) return 0;

    int target = required/2;

    vector<vector<int>> dp(n, vector<int>(target+1, 0));

    if (arr[0] == 0){
        dp[0][0] = 2;
    }
    else{
        dp[0][0] = 1;
    }

    if (arr[0]<=target && arr[0]!=0) dp[0][arr[0]] = 1;

    for (int i=1; i<n; i++){
        for (int t=0; t<=target; t++){
            int notTake = dp[i-1][t];
            int take = 0;
            if (arr[i] <= t) take = dp[i-1][t-arr[i]];

            dp[i][t] = (notTake+take) % MOD;
        }
    }

    return dp[n-1][target];
}

//? Optimised Tabulation
int targetSum(int n, int diff, vector<int>& arr) {
    int sum = accumulate(arr.begin(), arr.end(), 0);
    int required = sum-diff;

    if (required%2==1 || required<0) return 0;

    int target = required/2;

    vector<int> prev(target+1, 0);

    if (arr[0] == 0){
        prev[0] = 2;
    }
    else{
        prev[0] = 1;
    }

    if (arr[0]<=target && arr[0]!=0) prev[arr[0]] = 1;

    for (int i=1; i<n; i++){
        vector<int> cur(target+1, 0);

        for (int t=0; t<=target; t++){
            int notTake = prev[t];
            int take = 0;
            if (arr[i] <= t) take = prev[t-arr[i]];

            cur[t] = (notTake+take) % MOD;
        }

        prev.swap(cur);
    }

    return prev[target];
}