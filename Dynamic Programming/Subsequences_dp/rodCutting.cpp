#include <iostream>
using namespace std;

//? Memoization
int rodCuttingHelper(vector<int> &price, int i, int n, vector<vector<int>> &dp){
    if (dp[i][n] != -1) return dp[i][n];

    if (i == 1){
        if (n == 1) return price[0];

        return dp[i][n] = max(
            price[n-1],
            price[0] + price[n-2]
        );
    }

    int notCut = rodCuttingHelper(price, i-1, n, dp);

    int cut = 0;
    if (n != i) cut = price[n-i-1] + rodCuttingHelper(price, i-1, i, dp);

    return dp[i][n] = max(notCut, cut);
}

int rodCutting(vector<int> &price, int n) {
    vector<vector<int>> dp(n+1, vector<int>(n+1, -1));

    return rodCuttingHelper(price, n, n, dp);
}

//? Tabulation
int rodCutting(vector<int> &price, int N) {
    vector<vector<int>> dp(N+1, vector<int>(N+1, -1));

    dp[1][1] = price[0];
    for (int n=2; n<=N; n++){
        dp[1][n] = max(price[n-1], price[0]+price[n-2]);
    }

    for (int i=2; i<=N; i++){
        for (int n=2; n<=N; n++){
            int notCut = dp[i-1][n];
            int cut = 0;
            if (n != i) cut = price[n-i-1] + dp[i-1][i];

            dp[i][n] = max(notCut, cut);
        }
    }

    return dp[N][N];
}

//? Optimised Tabulation
int rodCutting(vector<int> &price, int N) {
    vector<int> prev(N+1);

    prev[1] = price[0];
    for (int n=2; n<=N; n++){
        prev[n] = max(price[n-1], price[0]+price[n-2]);
    }

    for (int i=2; i<=N; i++){
        vector<int> cur(N+1);

        for (int n=2; n<=N; n++){
            int notCut = prev[n];
            int cut = 0;
            if (n != i) cut = price[n-i-1] + prev[i];

            cur[n] = max(notCut, cut);
        }

        prev.swap(cur);
    }

    return prev[N];
}

//* Standard Rod Cutting Appraoch

//? Memoization
int rodCuttingHelper(vector<int> &price, int i, int n, vector<vector<int>> &dp){
    if (dp[i][n] != -1) return dp[i][n];

    if (i == 0){
        return n * price[0];
    }

    int notCut = rodCuttingHelper(price, i-1, n, dp);

    int cut = 0;
    if (i+1 <= n) cut = price[i] + rodCuttingHelper(price, i, n-i-1, dp);

    return dp[i][n] = max(notCut, cut);
}

int rodCutting(vector<int> &price, int n) {
    vector<vector<int>> dp(n, vector<int>(n+1, -1));

    return rodCuttingHelper(price, n-1, n, dp);
}

//? Tabulation
int rodCutting(vector<int> &price, int N) {
    vector<vector<int>> dp(N, vector<int>(N+1, 0));

    for (int n=1; n<=N; n++){
        dp[0][n] = n*price[0];
    }

    for (int i=0; i<N; i++){
        for (int n=1; n<=N; n++){
            int notTake = dp[i-1][n];
            int take = 0;
            if (i+1 <= n) take = price[i] + dp[i][n-i-1];

            dp[i][n] = max(notTake, take);
        }
    }

    return dp[N-1][N];
}

//? Optimsied Tabulation
int rodCutting(vector<int> &price, int N) {
    vector<int> prev(N+1, 0);

    for (int n=1; n<=N; n++){
        prev[n] = n*price[0];
    }

    for (int i=0; i<N; i++){
        vector<int> cur(N+1, 0);

        for (int n=1; n<=N; n++){
            int notTake = prev[n];
            int take = 0;
            if (i+1 <= n) take = price[i] + cur[n-i-1];

            cur[n] = max(notTake, take);
        }

        prev.swap(cur);
    }

    return prev[N];
}