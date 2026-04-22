#include <iostream>
using namespace std;

//? Memoization
int nonAdjacentHelper(vector<int>& nums, int curIndex, vector<int> &dp){
    if (curIndex < 0) return 0;
    if (curIndex == 0) return nums[0];

    if (dp[curIndex] != -1) return dp[curIndex];
    
    return dp[curIndex] = max(
        nonAdjacentHelper(nums, curIndex-1, dp),
        nums[curIndex] + nonAdjacentHelper(nums, curIndex-2, dp)
    );
}   

int nonAdjacent(vector<int>& nums) {
    int n = nums.size();

    vector<int> dp(n, -1);

    return nonAdjacentHelper(nums, n-1, dp);
}

//? Tabulation
int nonAdjacent(vector<int>& nums) {
    int n = nums.size();

    if (n == 1) return nums[0];

    vector<int> dp(n);

    dp[0] = nums[0];
    dp[1] = max(nums[1], nums[0]);
    
    for (int i=2; i<n; i++){
        dp[i] = max(nums[i]+dp[i-2], dp[i-1]);
    }

    return dp[n-1];
}

//? Optimied Tabulation
int nonAdjacent(vector<int>& nums) {
    int n = nums.size();

    if (n == 1) return nums[0];

    int prev2 = nums[0];
    int prev1 = max(nums[1], nums[0]);
    
    for (int i=2; i<n; i++){
        int cur = max(nums[i] + prev2, prev1);

        prev2 = prev1;
        prev1 = cur;
    }

    return prev1;
}