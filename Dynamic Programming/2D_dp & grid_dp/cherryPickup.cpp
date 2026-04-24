#include <iostream>
using namespace std;

//? Memoization
int cherryPickupHelper (vector<vector<int>>& matrix, int i, int j1, int j2, 
                        vector<vector<vector<int>>> &dp){

    if (j1<0 || j1>=matrix[0].size() || j2<0 || j2>=matrix[0].size()) return INT_MIN;

    if (dp[i][j1][j2] != -1) return dp[i][j1][j2];

    if (i == matrix.size()-1){
        if (j1 != j2) return dp[i][j1][j2] = matrix[i][j1]+matrix[i][j2];
        else return dp[i][j1][j2] = matrix[i][j1];
    }

    int maxCherry = INT_MIN;

    for (int k1=-1; k1<=1; k1++){
        for (int k2=-1; k2<=1; k2++){
            maxCherry = max(
                maxCherry, 
                cherryPickupHelper(matrix, i+1, j1+k1, j2+k2, dp)
            );
        }
    }

    if (j1 == j2) return dp[i][j1][j2] = matrix[i][j1] + maxCherry;

    return dp[i][j1][j2] = matrix[i][j1] + matrix[i][j2] + maxCherry;
}

int cherryPickup(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();

    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));

    return cherryPickupHelper(matrix, 0, 0, m-1, dp);
}

//? Tabulation
int cherryPickup(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();

    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, 0)));

    for (int j1=0; j1<m; j1++){
        for (int j2=0; j2<m; j2++){
            if (j1 == j2) dp[n-1][j1][j2] = matrix[n-1][j1];
            else dp[n-1][j1][j2] = matrix[n-1][j1] + matrix[n-1][j2];
        }
    }

    int maxCherry;

    for (int i=n-2; i>=0; i--){
        for (int j1=0; j1<m; j1++){
            for (int j2=0; j2<m; j2++){
                maxCherry = INT_MIN;

                for (int k1=-1; k1<=1; k1++){
                    for (int k2=-1; k2<=1; k2++){
                        if (j1+k1>=0 && j1+k1<m && j2+k2>=0 && j2+k2<m){
                            maxCherry = max(
                                maxCherry, 
                                dp[i+1][j1+k1][j2+k2]
                            );
                        }
                    }
                }

                if (j1 != j2) dp[i][j1][j2] = matrix[i][j1] + matrix[i][j2] + maxCherry;
                else dp[i][j1][j2] = matrix[i][j1] + maxCherry;
            }
        }
    }

    return dp[0][0][m-1];
}

//? Optimised Tabulation
int cherryPickup(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();

    vector<vector<int>> next(m, vector<int>(m, 0));

    for (int j1=0; j1<m; j1++){
        for (int j2=0; j2<m; j2++){
            if (j1 == j2) next[j1][j2] = matrix[n-1][j1];
            else next[j1][j2] = matrix[n-1][j1] + matrix[n-1][j2];
        }
    }

    int maxCherry;

    for (int i=n-2; i>=0; i--){
        vector<vector<int>> cur(m, vector<int>(m, 0));

        for (int j1=0; j1<m; j1++){
            for (int j2=0; j2<m; j2++){
                maxCherry = INT_MIN;

                for (int k1=-1; k1<=1; k1++){
                    for (int k2=-1; k2<=1; k2++){
                        if (j1+k1>=0 && j1+k1<m && j2+k2>=0 && j2+k2<m){
                            maxCherry = max(
                                maxCherry, 
                                next[j1+k1][j2+k2]
                            );
                        }
                    }
                }

                if (j1 != j2) cur[j1][j2] = matrix[i][j1] + matrix[i][j2] + maxCherry;
                else cur[j1][j2] = matrix[i][j1] + maxCherry;
            }
        }

        for (int j1=0; j1<m; j1++){
            for (int j2=0; j2<m; j2++){
                next[j1][j2] = cur[j1][j2];
            }
        }        
    }

    return next[0][m-1];
}