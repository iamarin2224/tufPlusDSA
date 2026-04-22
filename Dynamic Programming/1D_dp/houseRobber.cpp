#include <iostream>
using namespace std;

//? Memoization
int houseRobberHelper(vector<int>& money, int curIndex, int stopPoint, vector<int> &dp){
    if (curIndex < stopPoint) return 0;
    if (curIndex == stopPoint) return money[stopPoint];

    if (dp[curIndex] != -1) return dp[curIndex];

    return dp[curIndex] = max(
        houseRobberHelper(money, curIndex-1, stopPoint, dp),
        money[curIndex] + houseRobberHelper(money, curIndex-2, stopPoint, dp)
    );
}

int houseRobber(vector<int>& money) {
    int n = money.size();

    if (n == 1) return money[0];

    vector<int> dp(n, -1);

    int notFirst = houseRobberHelper(money, n-1, 1, dp);

    dp.assign(n, -1);

    int notLast = houseRobberHelper(money, n-2, 0, dp);

    return max(notFirst, notLast);
}

//? Tabulation
int houseRobber(vector<int>& money) {
    int n = money.size();

    if (n == 1) return money[0];
    if (n == 2) return max(money[0], money[1]);

    vector<int> dp(n);

    // Not taking the first
    dp[1] = money[1];
    dp[2] = max(money[1], money[2]);

    for (int i=3; i<n; i++){
        dp[i] = max(dp[i-1], money[i]+dp[i-2]);
    }

    int notFirst = dp[n-1];

    dp.clear();

    // Not taking the last
    dp[0] = money[0];
    dp[1] = max(money[0], money[1]);

    for (int i=2; i<n-1; i++){
        dp[i] = max(dp[i-1], money[i]+dp[i-2]);
    }

    int notLast = dp[n-2];

    return max(notFirst, notLast);
}

//? Optimised Tabulation
int houseRobber(vector<int>& money) {
    int n = money.size();

    if (n == 1) return money[0];
    if (n == 2) return max(money[0], money[1]);

    // Not taking the first
    int prev2 = money[1];
    int prev1 = max(money[1], money[2]);

    for (int i=3; i<n; i++){
        int cur = max(money[i] + prev2, prev1);

        prev2 = prev1;
        prev1 = cur;
    }

    int notFirst = prev1;

    // Not taking the last
    int prev2 = money[0];
    int prev1 = max(money[0], money[1]);

    for (int i=2; i<n-1; i++){
        int cur = max(money[i] + prev2, prev1);

        prev2 = prev1;
        prev1 = cur;
    }

    int notLast = prev1;

    return max(notFirst, notLast);
}