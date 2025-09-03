#include <bits/stdc++.h>
using namespace std;

int maxCol(vector<vector<int>>& mat, int col, int r){
    int max = INT_MIN;
    int maxInd = -1;

    for (int i=0; i<r; i++){
        if (mat[i][col] > max){
            max = mat[i][col];
            maxInd = i;
        }
    }

    return maxInd;
}

vector<int> findPeakGrid(vector<vector<int>>& mat) {
    int r = mat.size(), c = mat[0].size();

    int low = 0, high = c-1;

    while (low <= high){
        int mid = (low + high)/2;

        int maxInd = maxCol(mat, mid, r);

        int prev = 0, next = 0;

        if (mid == 0) prev = -1;
        else if (mid == c-1) next = -1;
        
        if (prev != -1) prev = mat[maxInd][mid-1];
        if (next != -1) next = mat[maxInd][mid+1];

        if (mat[maxInd][mid] > prev
            && mat[maxInd][mid] > next){
                return {maxInd, mid};
        }
        else if (mat[maxInd][mid] < prev){
            high = mid-1;
        }
        else low = mid+1;
    }

    return {};
}