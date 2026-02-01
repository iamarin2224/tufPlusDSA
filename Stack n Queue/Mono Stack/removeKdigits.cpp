#include <iostream>
using namespace std;

string removeKdigits(string nums, int k) {
    if (nums.size() == k){
        return "0";
    }    

    string ans = "";

    for (int i=0; i<nums.size(); i++){
        //pop is the current is smaller
        while (!ans.empty() && ans.back()>nums[i] && k>0){
            ans.pop_back();
            k--;
        }

        //No need to push zero into empty stack
        if (ans.empty() && nums[i] == '0') continue;

        ans.push_back(nums[i]);
    }

    while(!ans.empty() && k){
        ans.pop_back();
        k--;
    }

    if (ans.empty()) return "0";

    return ans;
}