#include <iostream>
using namespace std;

//? Memoization
int helper(vector<int> &arr, int k, int i, int buy, int sellCount, vector<vector<vector<int>>> &dp){
    if (i == arr.size()) return 0;

    if (sellCount == k) return 0;

    if (dp[i][buy][sellCount] != -1) return dp[i][buy][sellCount]; 

    int profit;

    if (buy){
        profit = max(
            -arr[i]+helper(arr, k, i+1, 0, sellCount, dp), //buy the current and go to next with "not to buy"
            helper(arr, k, i+1, 1, sellCount, dp) //do not buy, and go to next with "can buy"
        );
    }
    else{
        profit = max(
            arr[i]+helper(arr, k, i+1, 1, sellCount+1, dp), //sell the current and go to next with "can buy"
            helper(arr, k, i+1, 0, sellCount, dp) //do not sell thus go to next telling "not to buy"
        );
    }

    return dp[i][buy][sellCount] = profit;
}

int stockBuySell(vector<int> arr, int n, int k){
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k, -1)));

    return helper(arr, k, 0, 1, 0, dp);
}

//? Tabulation
int stockBuySell(vector<int> arr, int n, int k){
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1, 0)));

    int profit;

    for (int i=n-1; i>=0; i--){
        for (int buy=0; buy<=1; buy++){
            for (int sellCount=0; sellCount<k; sellCount++){
                if (buy == 1){
                    profit = max(-arr[i] + dp[i+1][0][sellCount], dp[i+1][1][sellCount]);
                }
                else{
                    profit = max(arr[i] + dp[i+1][1][sellCount+1], dp[i+1][0][sellCount]);
                }

                dp[i][buy][sellCount] = profit;
            }
        }
    }

    return dp[0][1][0];
}

//? Optimised Tabulation
int stockBuySell(vector<int> arr, int n, int k){
    vector<vector<int>> next(2, vector<int>(k+1, 0));

    int profit;

    for (int i=n-1; i>=0; i--){
        vector<vector<int>> cur(2, vector<int>(k+1, 0));

        for (int buy=0; buy<=1; buy++){
            for (int sellCount=0; sellCount<k; sellCount++){
                if (buy == 1){
                    profit = max(-arr[i] + next[0][sellCount], next[1][sellCount]);
                }
                else{
                    profit = max(arr[i] + next[1][sellCount+1], next[0][sellCount]);
                }

                cur[buy][sellCount] = profit;
            }
        }

        next.swap(cur);
    }

    return next[1][0];
}