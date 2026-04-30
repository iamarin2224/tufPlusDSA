#include <iostream>
using namespace std;

//? Memoization
int minCoinsHelper(vector<int>& coins, int i, int amount, vector<vector<int>> &dp){
    if (amount == 0) return dp[i][amount] = 0;

    if (dp[i][amount] != -2) return dp[i][amount];

    if (i == 0){
        if (amount%coins[0] == 0)  return dp[0][amount] = amount/coins[0];

        return 1e6;
    }

    int notTake = minCoinsHelper(coins, i-1, amount, dp);

    int take = 1e6;
    if (coins[i] <= amount){
        take = 1 + minCoinsHelper(coins, i, amount-coins[i], dp);
    }

    return dp[i][amount] = min(notTake, take);
}

int MinimumCoins(vector<int>& coins, int amount) {
    int n = coins.size();

    vector<vector<int>> dp(n, vector<int>(amount+1, -2));

    int ans = minCoinsHelper(coins, n-1, amount, dp);

    if (ans >= (int)1e6) return -1;

    return ans;
}

//? Tabulation
int MinimumCoins(vector<int>& coins, int amount) {
    int n = coins.size();

    vector<vector<int>> dp(n, vector<int>(amount+1, -2));

    for (int i=0; i<n; i++){
        dp[i][0] = 0;
    }

    for (int a=1; a<=amount; a++){
        dp[0][a] = a%coins[0]==0 ? a/coins[0] : 1e6;
    }

    for (int i=1; i<n; i++){
        for (int a=0; a<=amount; a++){
            int notTake = dp[i-1][a];
            int take = 1e6;;
            if (coins[i] <= a){
                take = dp[i][a-coins[i]] + 1;
            }

            dp[i][a] = min(notTake, take);
        }
    }

    if (dp[n-1][amount] >= 1e6) return -1;

    return dp[n-1][amount];
}

//? Optimised Tabulation
int MinimumCoins(vector<int>& coins, int amount) {
    int n = coins.size();

    vector<int> prev(amount+1, -2);

    prev[0] = 0;

    for (int a=1; a<=amount; a++){
        prev[a] = a%coins[0]==0 ? a/coins[0] : 1e6;
    }

    for (int i=1; i<n; i++){
        vector<int> cur(amount+1);

        for (int a=0; a<=amount; a++){
            int notTake = prev[a];
            int take = 1e6;
            if (coins[i] <= a){
                take = cur[a-coins[i]] + 1;
            }

            cur[a] = min(notTake, take);
        }

        prev.swap(cur);
        prev[0] = 0;
    }

    if (prev[amount] >= 1e6) return -1;

    return prev[amount];
}