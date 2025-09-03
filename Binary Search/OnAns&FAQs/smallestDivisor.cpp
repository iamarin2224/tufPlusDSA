#include <bits/stdc++.h>
using namespace std;

int maxArr(vector<int>& nums){
    int maxN = INT_MIN;

    for(int i=0; i<nums.size(); i++){
        maxN = max(maxN, nums[i]);
    }

    return maxN;
}

int sumAfterDiv(vector<int>& nums, int d){
    int sum = 0;

    for (int i=0; i<nums.size(); i++){
        if (nums[i]%d != 0){
            sum += (nums[i]/d) + 1;
        }
        else {
            sum += nums[i]/d;
        }
    }

    return sum;
}

int smallestDivisor(vector<int>& nums, int threshold) {
    int maxN = maxArr(nums);

    int low = 1, high = maxN, mid;

    int ans = INT_MAX;

    while(low<=high){
        mid = low + (high-low)/2;

        int sumMidDiv = sumAfterDiv(nums, mid);

        if (sumMidDiv <= threshold) {
            ans = min(ans, mid);
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }

    return ans;
}