#include <bits/stdc++.h>
using namespace std;

//? Better Soln, TC: O(2*N)
int longestOnes(vector<int>& nums, int k) {
    int n = nums.size();

    int l = 0, r = 0;
    int maxLen = 0;
    int remainingFlips = k;

    while (r < n){
        if (nums[r] == 0 && remainingFlips == 0){
            while (remainingFlips == 0 && l<n){
                if (nums[l] == 0) remainingFlips++;
                l++;
            }
            remainingFlips--;
        }
        else if (nums[r] == 0 && remainingFlips != 0){
            remainingFlips--;
        }
        
        maxLen = max(maxLen, r-l+1);
        r++;
    }
    return maxLen;
}

//? Optimal Soln, TC: O(N)
int longestOnes(vector<int>& nums, int k) {
    int n = nums.size();

    int l = 0, r = 0;
    int maxLen = 0;
    int zeroes = k;

    while (r < n){
        if (nums[r] == 0){
            zeroes++;
        }

        if (zeroes > k){
            if (nums[l] == 0){
                zeroes--;
            }
            l--;
        }

        if (zeroes <= k){
            maxLen = max(maxLen, r-l+1);
        }
        r++;
    }
    return maxLen;
}