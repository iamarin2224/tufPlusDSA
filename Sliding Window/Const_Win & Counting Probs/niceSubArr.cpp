#include <bits/stdc++.h>
using namespace std;

int helperFn(vector<int>& nums, int k){
    if (k < 0) return 0;

    int n = nums.size();

    int l=0, r=0;
    int cnt = 0, oddCnt = 0;

    while (r < n){
        oddCnt += (nums[r]%2);

        while (oddCnt > k){
            oddCnt -= (nums[l]%2);
            l++;
        }

        cnt += (r-l+1);

        r++;
    }

    return cnt;
}

int numberOfOddSubarrays(vector<int>& nums, int k) {
    return ((helperFn(nums, k)) - (helperFn(nums, k-1)));
}