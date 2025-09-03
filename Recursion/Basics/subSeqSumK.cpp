#include <bits/stdc++.h>
using namespace std;

/*
void checker(vector<int>& nums, vector<int> &current,int ind, int k, bool &ans, int sum){
    if (sum == k){
        ans = true;
        return;
    }
    
    if (ind == nums.size()){
        return;
    }
    
    checker(nums, current, ind+1, k, ans, sum);
    
    current.push_back(nums[ind]);
    sum += nums[ind];
    checker(nums, current, ind+1, k, ans, sum);
    
    current.pop_back();
}

bool checkSubsequenceSum(vector<int>& nums, int k) {
    bool ans = false;
    
    vector<int> current;
    checker(nums, current, 0, k, ans, 0);
    
    return ans; 
}
*/

bool checker(vector<int> &nums, int sum, int ind){
    if (ind == nums.size()){
        return sum == 0;
    }

    return (checker(nums, sum - nums[ind], ind+1) || checker(nums, sum, ind+1));
}

bool checkSubsequenceSum(vector<int>& nums, int k) {
    return checker(nums, k, 0);
}