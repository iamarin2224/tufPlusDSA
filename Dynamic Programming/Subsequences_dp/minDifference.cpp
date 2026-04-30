#include <iostream>
#include <numeric>
using namespace std;

//? Memoization
bool isSubsetSumPossible(vector<int> &arr, int i, int target, vector<vector<int>> &dp){
    if (target == 0) return true;

    if (dp[i][target] != -1) return dp[i][target];

    if (i == 0) return arr[0] == target;

    bool notTake, take = false;

    notTake = isSubsetSumPossible(arr, i-1, target, dp);

    if (arr[i] <= target) take = isSubsetSumPossible(arr, i-1, target-arr[i], dp);

    return dp[i][target] = notTake || take;
}

int minDifference(vector<int>&arr, int n)  { 
    int sum = accumulate(arr.begin(), arr.end(), 0);

    int target = sum/2;

    vector<vector<int>> dp(n, vector<int>(target+1, -1));

    int i;
    for (i=0; i<=target; i++){
        if (isSubsetSumPossible(arr, n-1, target-i, dp)) break;
    }

    if (sum%2 == 1) return i*2 + 1;

    return i*2;
}

//? Tabulation
int minDifference(vector<int>&arr, int n)  { 
    int sum = accumulate(arr.begin(), arr.end(), 0);

    int target = sum/2;

    vector<vector<int>> dp(n, vector<int>(target+1, -1));

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

    int i;
    for (i=0; i<=target; i++){
        if (dp[n-1][target-i]) break;
    }

    if (sum%2 == 1) return i*2 + 1;

    return i*2;
}

//? Optimised Tabulation
int minDifference(vector<int>&arr, int n)  { 
    int sum = accumulate(arr.begin(), arr.end(), 0);

    int target = sum/2;

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

    int i;
    for (i=0; i<=target; i++){
        if (prev[target-i]) break;
    }

    if (sum%2 == 1) return i*2 + 1;

    return i*2;
}