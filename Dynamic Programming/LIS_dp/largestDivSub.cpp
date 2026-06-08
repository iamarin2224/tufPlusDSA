#include <iostream>
using namespace std;

vector<int> largestDivisibleSubset(vector<int>& nums) {
    int n = nums.size();

    sort(nums.begin(), nums.end());

    vector<int> dp(n+1, 1);
    vector<int> parent(n);

    int maxLen = 0;
    int lastInd = 0;

    for (int i=0; i<n; i++){
        parent[i] = i;

        for (int prevInd=0; prevInd<i; prevInd++){
            if (nums[i]%nums[prevInd] == 0){
                if (dp[i] < dp[prevInd]+1){
                    dp[i] = dp[prevInd]+1;
                    parent[i] = prevInd;
                }
                else if (dp[i] == dp[prevInd]+1 && prevInd < parent[i]){
                    parent[i] = prevInd;
                }
            }
        }

        if (dp[i] > maxLen){
            maxLen = dp[i];
            lastInd = i;
        }
    }

    vector<int> ans;
    int i = lastInd;

    while (parent[i] != i){
        ans.push_back(nums[i]);
        i = parent[i];
    }
    ans.push_back(nums[i]);


    for (int i : ans){
        cout << i;
    }

    return ans;
}