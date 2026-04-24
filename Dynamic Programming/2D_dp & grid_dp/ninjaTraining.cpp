#include <iostream>
using namespace std;

//? Memoization
int ninjaTrainingHelper(vector<vector<int>>& matrix, int curRow, int lastActivity, 
                        vector<vector<int>> &dp) {
    if (curRow < 0) return 0;

    if (dp[curRow][lastActivity] != -1) return dp[curRow][lastActivity];

    int maxPoints = INT_MIN;

    for (int i=0; i<3; i++){
        if (i != lastActivity){
            maxPoints = max(
                maxPoints, 
                matrix[curRow][i] + ninjaTrainingHelper(matrix, curRow-1, i, dp)
            );
        }
    }

    return dp[curRow][lastActivity] = maxPoints;
}

int ninjaTraining(vector<vector<int>>& matrix) {
    int n = matrix.size();

    vector<vector<int> >dp(n, vector<int>(3, -1));

    int ans = INT_MIN;

    for (int i=0; i<3; i++){
        ans = max(ans, ninjaTrainingHelper(matrix, n-1, i, dp));
    }

    return ans;
}

//? Tabulation
int ninjaTraining(vector<vector<int>>& matrix) {
    int n = matrix.size();

    vector<vector<int> >dp(n, vector<int>(3, 0));

    dp[0][0] = max(matrix[0][1], matrix[0][2]);
    dp[0][1] = max(matrix[0][0], matrix[0][2]);
    dp[0][2] = max(matrix[0][0], matrix[0][1]);

    int maxPoints = INT_MIN;

    for (int i=1; i<n; i++){
        for (int j=0; j<3; j++){
            maxPoints = INT_MIN;
            for (int k=0; k<3; k++){
                if (k != j){
                    maxPoints = max(maxPoints, matrix[i][k] + dp[i-1][k]);
                }
            }
            dp[i][j] = maxPoints;
        }
    }

    return max(dp[n-1][0], max(dp[n-1][1], dp[n-1][2]));
}

//? Optimised Tabulation
int ninjaTraining(vector<vector<int>>& matrix) {
    int n = matrix.size();

    vector<int> prev(3, 0);

    prev[0] = max(matrix[0][1], matrix[0][2]);
    prev[1] = max(matrix[0][0], matrix[0][2]);
    prev[2] = max(matrix[0][0], matrix[0][1]);

    vector<int> cur(3, 0);

    int maxPoints = INT_MIN;

    for (int i=1; i<n; i++){

        for (int j=0; j<3; j++){
            maxPoints = INT_MIN;
            for (int k=0; k<3; k++){
                if (k != j){
                    maxPoints = max(maxPoints, matrix[i][k] + prev[k]);
                }
            }
            cur[j] = maxPoints;
        }

        for (int j=0; j<3; j++){
            prev[j] = cur[j];
        }
    }

    return max(prev[0], max(prev[1], prev[2]));
}