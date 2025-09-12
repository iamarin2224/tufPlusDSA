#include <bits/stdc++.h>
using namespace std;

int longestOnes(vector<int>& nums, int k) {
    int n = nums.size();

    int l = 0, r = 0;
    int maxLen = 0;
    int curK = k;

    while (r < n){
        if (nums[r] == 0 && curK == 0){
            while (curK == 0 && l<n){
                if (nums[l] == 0) curK++;
                l++;
            }
            curK--;
        }
        else if (nums[r] == 0 && curK != 0){
            curK--;
        }
        
        maxLen = max(maxLen, r-l+1);
        r++;
    }
    return maxLen;
}