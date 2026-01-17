#include <iostream>
using namespace std;

void func(vector<int>& candidates, int target, vector<vector<int>> &ans, vector<int> &current, int ind, int sum){

    if (sum == target){
        if (!ans.empty() && ans.back() == current) return;
        ans.push_back(current);
        return;
    }

    if (sum > target || ind >= candidates.size()) return;

    int indCopy = ind;
    while (indCopy+1 < candidates.size() && candidates[indCopy] == candidates[indCopy+1]) indCopy++;
    indCopy++;
    func(candidates, target, ans, current, indCopy, sum);
    
    current.push_back(candidates[ind]);
    func(candidates, target, ans, current, ind+1, sum+candidates[ind]);
    current.pop_back();
}

vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    vector<int> current;

    sort(candidates.begin(), candidates.end());

    func(candidates, target, ans, current, 0, 0);

    sort(ans.begin(), ans.end());

    return ans;
}