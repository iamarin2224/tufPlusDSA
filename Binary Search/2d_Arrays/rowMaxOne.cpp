#include <bits/stdc++.h>
using namespace std;

int rowWithMax1s(vector < vector < int >> & mat) {
    int n = mat.size();
    int m = mat[0].size();

    int minZeroPos = INT_MAX;
    int ans = -1;

    for (int i=0; i<n; i++){
        int low = 0, high = m-1;

        while (low <= high){
            int mid = (low + high)/2; 

            if (mid == 1) high = mid-1;
            else low = mid+1;
        }

        if (high < minZeroPos){
            ans = i;
            minZeroPos = high;
        }
    }

    if (minZeroPos == m-1) return -1;

    return ans;
}