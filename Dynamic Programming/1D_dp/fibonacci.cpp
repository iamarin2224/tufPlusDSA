#include <iostream>
#include <ctime>
using namespace std;

//Classic Recursive Solution
int fib(int n){
    if (n <= 1) return n;

    return fib(n-1)+fib(n-2);
}

//DP Memoization Solution
int fibDP(int n, vector<int> &dp){
    if (n <= 1) return n;

    if (dp[n] != -1) return dp[n];

    return dp[n] = fibDP(n-1, dp) + fibDP(n-2, dp);
}

//DP Tabulation Solution
int fibDPTab(int n, vector<int> &dp){
    if (n <= 1) return n;

    dp[0] = 0;
    dp[1] = 1;

    for (int i=2; i<=n; i++){
        dp[i] = dp[i-1]+dp[i-2];
    }

    return dp[n];
}

//DP Tabulation Space Optimised Solution
int fibDPTab(int n){
    if (n <= 1) return n;

    int prev2 = 0;
    int prev1 = 1;

    for (int i=2; i<=n; i++){
        int curI = prev1+prev2;
        prev2 = prev1;
        prev1 = curI;
    }

    return prev1;
}

int main(){
    int n; cin >> n;

    //? Recursive Way
    clock_t start = clock();
    cout << fib(n) << endl;
    clock_t end = clock();
    double time_taken = double(end - start) / CLOCKS_PER_SEC;
    cout << "Time take by recursive fib: " << time_taken << endl;

    //? DP Memoization Way
    vector<int> dp(n+1, -1);
    start = clock();
    cout << fibDP(n, dp) << endl;
    end = clock();
    time_taken = double(end - start) / CLOCKS_PER_SEC;
    cout << "Time take by dp fib: " << time_taken << endl;

    //? DP Tabulation Way
    vector<int> newDP(n+1, -1);
    cout << fibDPTab(n, newDP) << endl;

    //? DP Optimised Tabulation Way
    cout<< fibDPTab(n) << endl;
    return 0;
}