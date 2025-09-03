#include <bits/stdc++.h>
using namespace std;

int singleNumber(vector<int>& nums){
    int ans = nums[0];
    for (int i=1; i<nums.size(); i++){
        ans ^= nums[i];
    }
    return ans;
}