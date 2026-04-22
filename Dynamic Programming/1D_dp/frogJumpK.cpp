#include <iostream>
#include <list>
using namespace std;

//? Recursive
int frogJumpHelper(vector<int>& heights, int k, int curIndex){
    if (curIndex == 0) return 0;

    int minJump = INT_MAX;

    for (int i=1; i<=k; i++){
        if (curIndex-i < 0) break;

        minJump = min(minJump, 
            frogJumpHelper(heights, k, curIndex-i)+ abs(heights[curIndex]-heights[curIndex-i]));
    }

    return minJump;
}

int frogJump(vector<int>& heights, int k) {
    int n = heights.size();

    return frogJumpHelper(heights, k, n-1);
}

//? Memoization
int frogJumpHelper(vector<int>& heights, int k, int curIndex, vector<int> &dp){
    if (curIndex == 0) return dp[0] = 0;

    if (dp[curIndex] != -1) return dp[curIndex];

    int minJump = INT_MAX;

    for (int i=1; i<=k; i++){
        if (curIndex-i < 0) break;

        minJump = min(minJump, 
            frogJumpHelper(heights, k, curIndex-i, dp)+ abs(heights[curIndex]-heights[curIndex-i]));
    }

    return dp[curIndex] = minJump;
}

int frogJump(vector<int>& heights, int k) {
    int n = heights.size();

    vector<int> dp(n, -1);

    return frogJumpHelper(heights, k, n-1, dp);
}

//? Tabulation
int frogJump(vector<int>& heights, int k) {
    int n = heights.size();

    if (n == 1) return 0;

    vector<int> dp(n);

    dp[0] = 0;

    for (int i=1; i<n; i++){
        int minJump = dp[i-1] + abs(heights[i]-heights[i-1]);

        for (int j=2; j<=k; j++){
            if (i-j < 0) break;

            minJump = min(minJump, dp[i-j] + abs(heights[i]-heights[i-j]));
        }
        
        dp[i] = minJump;
    }

    return dp[n-1];
}

//? Optimised Tabulation
int frogJump(vector<int>& heights, int k) {
    int n = heights.size();

    if (n == 1) return 0;

    vector<int> dp(k);

    dp[0] = 0;

    for (int i=1; i<n; i++){
        int minJump = dp[(i-1)%k] + abs(heights[i]-heights[i-1]);

        for (int j=2; j<=k; j++){
            if (i-j < 0) break;

            minJump = min(minJump, dp[(i-j)%k] + abs(heights[i]-heights[i-j]));
        }

        dp[i%k] = minJump;
    }

    return dp[(n-1)%k];
}