#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > powerSet(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> ans;

    int subsets = (1<<n);

    for (int num=0; num<subsets; num++){
        vector<int> current;
        for (int i=0; i<n; i++){
            if (num & (1<<i)){
                current.push_back(nums[i]);
            }
        }
        ans.push_back(current);
    }

    return ans;
}