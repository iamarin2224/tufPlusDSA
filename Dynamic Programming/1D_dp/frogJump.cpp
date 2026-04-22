#include <iostream>
using namespace std;

//? Recursion
int frogJumpHelper(vector<int>& heights, int curIndex){
    if (curIndex == 0) return 0;

    int jumpOne = frogJumpHelper(heights, curIndex-1) + abs(heights[curIndex]-heights[curIndex-1]);

    int jumpTwo = INT_MAX;

    if (curIndex > 1) 
        jumpTwo = frogJumpHelper(heights, curIndex-2) + abs(heights[curIndex]-heights[curIndex-2]);
    
    return min(jumpOne, jumpTwo);
}

int frogJump(vector<int>& heights) {
    int n = heights.size();

    return frogJumpHelper(heights, n-1);   
}

//? Memoization 
int frogJumpHelper(vector<int>& heights, int curIndex, vector<int> &dp){
    if (curIndex == 0) return dp[0] = 0;

    if (dp[curIndex] != -1) return dp[curIndex];

    int jumpOne = frogJumpHelper(heights, curIndex-1, dp) + abs(heights[curIndex]-heights[curIndex-1]);

    int jumpTwo = INT_MAX;

    if (curIndex > 1) 
        jumpTwo = frogJumpHelper(heights, curIndex-2, dp) + abs(heights[curIndex]-heights[curIndex-2]);
    
    return dp[curIndex] = min(jumpOne, jumpTwo);
}

int frogJump(vector<int>& heights) {
    int n = heights.size();

    vector<int> dp(n,  -1);

    return frogJumpHelper(heights, n-1, dp);   
}

//? Tabulation
int frogJump(vector<int>& heights) {
    int n = heights.size();

    if (n == 1) return 0;

    vector<int> dp(n, -1);

    dp[0] = 0;
    dp[1] = abs(heights[1] - heights[0]);

    for (int i=2; i<n; i++){
        int jumpOne = dp[i-1] + abs(heights[i]-heights[i-1]);
        int jumpTwo = dp[i-2] + abs(heights[i]-heights[i-2]);

        dp[i] = min(jumpOne, jumpTwo);
    }

    return dp[n-1];
}

//? Optimised Tabulation
int frogJump(vector<int>& heights) {
    int n = heights.size();

    if (n == 1) return 0;

    int prevJump2 = 0;
    int prevJump1 = abs(heights[1] - heights[0]);

    for (int i=2; i<n; i++){
        int jumpOne = prevJump1 + abs(heights[i]-heights[i-1]);
        int jumpTwo = prevJump2 + abs(heights[i]-heights[i-2]);

        prevJump2 = prevJump1;
        prevJump1 = min(jumpOne, jumpTwo);
    }

    return prevJump1;
}