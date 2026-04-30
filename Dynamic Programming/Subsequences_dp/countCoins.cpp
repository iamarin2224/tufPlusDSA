#include <iostream>
using namespace std;

#define MOD 1000000007

//? Memoization
int countCoinsHelper(vector<int>& coins, int i, int amount, vector<vector<int>> &dp){
    if (amount == 0) return dp[i][amount] = 1;

    if (dp[i][amount] != -1) return dp[i][amount];

    if (i == 0){
        if (amount%coins[0] == 0)  return dp[0][amount] = 1;

        return 0;
    }

    int notTake = countCoinsHelper(coins, i-1, amount, dp);

    int take = 0;
    if (coins[i] <= amount){
        take = countCoinsHelper(coins, i, amount-coins[i], dp);
    }

    return dp[i][amount] = (notTake + take)%MOD;
}

int count(vector<int>&coins, int N, int amount) {
    vector<vector<int>> dp(N, vector<int>(amount+1, -1));

    return countCoinsHelper(coins, N-1, amount, dp);
}

//? Tabulation
int count(vector<int>&coins, int n, int amount) {
    vector<vector<int>> dp(n, vector<int>(amount+1, 0));

    for (int i=0; i<n; i++){
        dp[i][0] = 1;
    }

    for (int a=1; a<=amount; a++){
        dp[0][a] = a%coins[0]==0 ? 1 : 0;
    }

    for (int i=1; i<n; i++){
        for (int a=0; a<=amount; a++){
            int notTake = dp[i-1][a];
            int take = 0;
            if (coins[i] <= a){
                take = dp[i][a-coins[i]];
            }

            dp[i][a] = (notTake + take)%MOD;
        }
    }

    return dp[n-1][amount];
}

//? Optimised Tabulation
int count(vector<int>&coins, int n, int amount) {
    vector<int> prev(amount+1, 0);

    prev[0] = 1;

    for (int a=1; a<=amount; a++){
        prev[a] = a%coins[0]==0 ? 1 : 0;
    }

    for (int i=1; i<n; i++){
        vector<int> cur(amount+1);

        for (int a=0; a<=amount; a++){
            int notTake = prev[a];
            int take = 0;
            if (coins[i] <= a){
                take = cur[a-coins[i]];
            }

            cur[a] = (notTake + take)%MOD;
        }

        prev.swap(cur);
        prev[0] = 1;
    }

    return prev[amount];
}