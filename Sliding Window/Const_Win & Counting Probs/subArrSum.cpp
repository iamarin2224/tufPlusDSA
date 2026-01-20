#include <iostream>
using namespace std;

//? Brute
int numSubarraysWithSum(vector<int>& nums, int goal) {
    int n = nums.size();
    int cnt = 0;

    for (int i=0; i<n; i++){
        int sum = 0;
        for (int j=i; j<n; j++){
            sum += nums[j];
            if (sum == goal){
                cnt++;
            }
        }
    }

    return cnt;
}

//? Better || TC:O(N) SC:O(N)
int numSubarraysWithSum(vector<int>& nums, int goal) {
    int n = nums.size();

    unordered_map<int, int> mpp;
    int preSum = 0, cnt = 0;

    mpp[0] = 1;

    for (int i=0; i<n; i++){
        preSum += nums[i];

        int rem = preSum-goal;

        if (mpp.find(rem) != mpp.end()){
            cnt += mpp[rem];
        }

        mpp[preSum]++;
    }

    return cnt;
}

//? Optimal || TC:(2*2N) SC:O(1)
int helperFn(vector<int>& nums, int goal){
    if (goal < 0) return 0;

    int n = nums.size();

    int l=0, r=0;
    int cnt = 0, sum = 0;

    while (r < n){
        sum += nums[r];

        while (sum > goal){
            sum -= nums[l];
            l++;
        }

        cnt += (r-l+1);

        r++;
    }

    return cnt;
}

int numSubarraysWithSum(vector<int>& nums, int goal) {
    return ((helperFn(nums, goal)) - (helperFn(nums, goal-1)));
}