#include <bits/stdc++.h>
using namespace std;

void checker(vector<int> &nums, int sum, int ind, int &count){
    if (ind == nums.size()){
        if(sum == 0) count++;
        return;
    }

    checker(nums, sum - nums[ind], ind+1, count);
    checker(nums, sum, ind+1, count);
}

int countSubsequenceWithTargetSum(vector<int>& nums, int k){
    int count = 0;
    checker(nums, k, 0, count);

    return count;
}

//? Alt Way of counting
int func(vector<int> &nums, int sum, int ind){
    if (sum == 0) return 1;

    if (sum < 0 || ind == nums.size()) return 0;

    return (func(nums, sum - nums[ind], ind+1) + func(nums, sum, ind+1));
}

int countSubsequenceWithTargetSum(vector<int>& nums, int k){
    return func(nums, k, 0);
}