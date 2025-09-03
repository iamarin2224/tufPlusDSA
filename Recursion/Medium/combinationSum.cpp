#include <bits/stdc++.h>
using namespace std;

void func(vector<vector<int>>& ans, vector<int>& current, vector<int>& candidates, int ind, int sum, int target){

    if (sum == target){
        ans.push_back(current);
        return;
    }

    if (sum > target || ind >= candidates.size()) return;

    func(ans, current, candidates, ind+1, sum, target);

    current.push_back(candidates[ind]);
    func(ans, current, candidates, ind, sum + candidates[ind], target);
    current.pop_back();
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    vector<int> current;
    
    func(ans, current, candidates, 0, 0, target);

    return ans;
}