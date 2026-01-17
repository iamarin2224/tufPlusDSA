#include <iostream>
using namespace std;

void func(vector<int>& nums, vector<vector<int>> &ans, vector<int> current, int ind){
    if (ind == nums.size()){
        ans.push_back(current);
        return;
    };

    func(nums, ans, current, ind+1);

    current.push_back(nums[ind]);
    func(nums, ans, current, ind+1);

    current.pop_back();
}

vector<vector<int>> powerSet(vector<int>& nums) {
    vector<vector<int>> ans;

    vector<int> current;

    func(nums, ans, current, 0);

    return ans;
}