#include <iostream>
using namespace std;

//? Memoization
int lisHelper(vector<int>& nums, int i, int nextInd, vector<vector<int>> &dp){
    if (i == 0){
        if (nextInd == nums.size() || nums[0] < nums[nextInd]){
            return 1;
        }
        else{
            return 0;
        }
    }

    if (dp[i][nextInd] != -1) return dp[i][nextInd];

    int notTake = lisHelper(nums, i-1, nextInd, dp);

    int take = 0;
    if (nextInd == nums.size() || nums[i] < nums[nextInd]) 
        take = 1 + lisHelper(nums, i-1, i, dp);

    return dp[i][nextInd] = max(notTake, take);
}

int LIS(vector<int>& nums) {
    int n = nums.size();

    vector<vector<int>> dp(n, vector<int>(n+1, -1));

    return lisHelper(nums, n-1, n, dp);
}

//? Tabulation
int LIS(vector<int>& nums) {
    int n = nums.size();

    vector<vector<int>> dp(n, vector<int>(n+1, 0));

    dp[0][n] = 1;
    for (int nI=1; nI<n; nI++){
        if (nums[0] < nums[nI]) dp[0][nI] = 1;
    }

    for (int i=1; i<n; i++){
        for (int nI=1; nI<=n; nI++){
            int notTake = dp[i-1][nI];
            int take = 0;
            if (nI == n || nums[i] < nums[nI])
                take = 1 + dp[i-1][i];
            
            dp[i][nI] = max(notTake, take);
        }
    }

    return dp[n-1][n];
}

//? Optimised Tabulation
int LIS(vector<int>& nums) {
    int n = nums.size();

    vector<int> prev(n+1, 0);

    prev[n] = 1;
    for (int nI=1; nI<n; nI++){
        if (nums[0] < nums[nI]) prev[nI] = 1;
    }

    for (int i=1; i<n; i++){
        vector<int> cur(n+1, 0);

        for (int nI=1; nI<=n; nI++){
            int notTake = prev[nI];
            int take = 0;
            if (nI == n || nums[i] < nums[nI])
                take = 1 + prev[i];
            
            cur[nI] = max(notTake, take);
        }

        prev.swap(cur);
    }

    return prev[n];
}

//? Binary Search
int LIS(vector<int>& nums) {
    int n = nums.size();

    vector<int> temp;
    temp.push_back(nums[0]);

    for (int i=1; i<n; i++){
        if (nums[i] > temp.back()){
            temp.push_back(nums[i]);
        }
        else{
            int ind = lower_bound(temp.begin(), temp.end(), nums[i])-temp.begin();

            temp[ind] = nums[i];
        }
    }

    return temp.size();
}

//? Standard LIS (uses tabulation)
int LIS(vector<int>& nums) {
    int n = nums.size();

    vector<int> dp(n, 1); //max size of LIS ending at i

    int maxLen = 0;

    for (int i=0; i<n; i++){
        for (int j=0; j<i; j++){
            if (nums[j] < nums[i] && dp[i] < dp[j]+1){
                dp[i] = dp[j]+1;
            }
        }

        maxLen = max(maxLen, dp[i]);
    }

    return maxLen;
}