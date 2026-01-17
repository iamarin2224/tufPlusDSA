#include <iostream>
using namespace std;

void func(vector<int>& nums, int ind, int sum, vector<int> &ans){

    if (ind >= nums.size()){
        ans.push_back(sum);
        return;
    }

    func(nums, ind+1, sum, ans);

    func(nums, ind+1, sum + nums[ind], ans);
  
}

vector<int> subsetSums(vector<int>& nums) {
    vector<int> ans;

    func(nums, 0, 0, ans);

    return ans;
}