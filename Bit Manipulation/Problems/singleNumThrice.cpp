#include <bits/stdc++.h>
using namespace std;

//? Brute
int singleNumber(vector<int>& nums) { 
    int ans = 0;       
    for (int bitInd = 0; bitInd <= 31; bitInd++){
        int cnt = 0;
        for (int i=0; i<nums.size(); i++){
            if (nums[i] & (1<<bitInd)){
                cnt++;
            }
        }
        if (cnt%3 == 1){
            ans |= (1<<bitInd);
        }
    }
    return ans;
}

//? Better
int singleNumber(vector<int>& nums) { 
    sort(nums.begin(), nums.end());

    int n = nums.size();

    for (int i=1; i<n; i+=3){
        if (nums[i-1] != nums[i]){
            return nums[i-1];
        }
    }

    return nums[n-1];
}