#include <bits/stdc++.h>
using namespace std;

int maxArr(vector<int>& nums){
    int maxN = INT_MIN;

    for(int i=0; i<nums.size(); i++){
        maxN = max(maxN, nums[i]);
    }

    return maxN;
}

int bouquetCount(vector<int>& nums, int k, int days){
    int curCount = 0, bqCount = 0;

    for (int i=0; i<nums.size(); i++){
        if (nums[i] <= days){
            curCount++;
        }
        else{
            curCount = 0;
        }
        if (curCount == k){
            bqCount += 1;
            curCount = 0;
        }
    }

    return bqCount;
}

int roseGarden(int n, vector<int>& nums, int k, int m) {
    if (m*k > n) return -1;

    int low = 1, high = maxArr(nums);

    int mid, ans = -1;

    while(low<=high){
        mid = low + (high-low)/2;

        int bqCount = bouquetCount(nums, k, mid);

        if (bqCount >= m){
            ans = min(ans, mid);
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }

    return ans;
}