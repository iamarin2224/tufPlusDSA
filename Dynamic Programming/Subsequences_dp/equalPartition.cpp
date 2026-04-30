#include <iostream>
#include <numeric>
using namespace std;

//! First Approach with 3 states
// bool helper(vector<int> &arr, int i, int target1, int target2){
//     if (i == 0) return (abs(target1-target2) == arr[0]);

//     bool take1 = helper(arr, i-1, target1+arr[i], target2);
//     bool take2 = helper(arr, i-1, target1, target2+arr[i]);

//     return take1 || take2;
// }

// bool equalPartition(int n, vector<int> arr) {
//     return helper(arr, n-1, 0, 0);
// }

//! Second approach, not the standard way
// bool helper(vector<int> &arr, int sum, int i, int sum1, vector<vector<int>> &dp){
//     if (sum1 > sum/2) return false;

//     if (dp[i][sum1] != -1) return dp[i][sum1];

//     if (i == 0) return (
//         (dp[0][sum1] = (sum == 2*sum1)) ||
//         (dp[0][sum1+arr[0]] = (sum == 2*(sum1+arr[0])))
//     );

//     bool notTake = helper(arr, sum, i-1, sum1, dp);

//     bool take = false;
//     if (sum1+arr[i] <= sum/2) take = helper(arr, sum, i-1, sum1+arr[i], dp); 

//     return dp[i][sum1] = take || notTake;
// }

// bool equalPartition(int n, vector<int> arr) {
//     int sum = accumulate(arr.begin(), arr.begin()+n, 0);

//     if (sum%2 == 1) return false;

//     vector<vector<int>> dp(n, vector<int>((sum/2)+1, -1));

//     return helper(arr, sum, n-1, 0, dp);
// }

//? Memoization
bool helper(vector<int>& arr, int i, int target, vector<vector<int>>& dp) {
    if (target == 0) return true;
    if (i == 0) return arr[0] == target;

    if (dp[i][target] != -1) return dp[i][target];

    bool notTake = helper(arr, i-1, target, dp);

    bool take = false;
    if (arr[i] <= target) take = helper(arr, i-1, target - arr[i], dp);

    return dp[i][target] = take || notTake;
}

bool equalPartition(int n, vector<int> arr) {
    int sum = accumulate(arr.begin(), arr.end(), 0);

    if (sum % 2 != 0) return false;

    int target = sum / 2;   //Qn basically to find target equal to half of sum

    vector<vector<int>> dp(n, vector<int>(target+1, -1));

    return helper(arr, n-1, target, dp);
}

//? Tabulation
bool equalPartition(int n, vector<int> arr) {
    int sum = accumulate(arr.begin(), arr.end(), 0);

    if (sum%2 != 0) return false;

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

    return dp[n-1][target];
}

//? Optimised Tabulation
bool equalPartition(int n, vector<int> arr) {
    int sum = accumulate(arr.begin(), arr.end(), 0);

    if (sum%2 != 0) return false;

    int target = sum/2;

    vector<bool> prev(target+1, false);

    prev[0] = true;
    prev[arr[0]] = true;

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