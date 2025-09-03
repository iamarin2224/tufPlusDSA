#include <bits/stdc++.h>
using namespace std;

void func(vector<int>& nums, vector<vector<int>> &ans, vector<int> &current, int ind){

    if (ind == nums.size()){
        ans.push_back(current);
        return;
    }

    current.push_back(nums[ind]);
    func(nums, ans, current, ind+1);
    current.pop_back();

    //? While loop approach
    int indCopy = ind;
    while (indCopy+1 < nums.size() && nums[indCopy] == nums[indCopy+1]) indCopy++;
    indCopy++;
    func(nums, ans, current, indCopy);

    //? Alt For loop approach
    /*
    for (int i = ind+1; i < nums.size(); i++){
        if (nums[i] != nums[ind]){
            func(nums, ans, current, i);
            return;
        }
    }
    
    func(nums, ans, current, nums.size()); 
    ? --> as if all duplicates the return statement is not executed, so run this to push the current vector into ans
    */
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {

    vector<vector<int>> ans;
    vector<int> current;

    sort(nums.begin(), nums.end());

    func(nums, ans, current, 0);

    return ans;
    
}