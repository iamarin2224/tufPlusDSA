#include <iostream>
using namespace std;

//? Memoization
int helper(vector<int> &arr, int i, int buy, vector<vector<int>> &dp){
    if (i == arr.size()) return 0;

    if (dp[i][buy] != -1) return dp[i][buy];

    int profit;

    if (buy){
        profit = max(
            -arr[i]+helper(arr, i+1, 0, dp), //buy the current and go to next with "not to buy"
            helper(arr, i+1, 1, dp) //do not buy, and go to next with "can buy"
        );
    }
    else{
        profit = max(
            arr[i]+helper(arr, i+1, 1, dp), //sell the current and go to next with "can buy"
            helper(arr, i+1, 0, dp) //do not sell thus go to next telling "not to buy"
        );
    }

    return dp[i][buy] = profit;
}

int stockBuySell(vector<int> arr, int n){
    vector<vector<int>> dp(n, vector<int>(2, -1));

    return helper(arr, 0, 1, dp);
}

//? Tabulation
int stockBuySell(vector<int> arr, int n){
    vector<vector<int>> dp(n+1, vector<int>(2, 0));

    int profit;

    for (int i=n-1; i>=0; i--){
        for (int buy=0; buy<=1; buy++){
            if (buy == 1){
                profit = max(-arr[i]+dp[i+1][0], dp[i+1][1]);
            }
            else{
                profit = max(arr[i]+dp[i+1][1], dp[i+1][0]);
            }

            dp[i][buy] = profit;
        }
    }

    return dp[0][1];
}

//? Optimised Tabulation
int stockBuySell(vector<int> arr, int n){
    vector<int> next(2, 0);

    int profit;

    for (int i=n-1; i>=0; i--){
        vector<int> cur(2, 0);

        for (int buy=0; buy<=1; buy++){
            if (buy == 1){
                profit = max(-arr[i]+next[0], next[1]);
            }
            else{
                profit = max(arr[i]+next[1], next[0]);
            }

            cur[buy] = profit;
        }

        next[0] = cur[0];
        next[1] = cur[1];
    }

    return next[1];
}