#include <iostream>
using namespace std;

int maxArr(vector<int>& nums){
    int maxN = INT_MIN;

    for(int i=0; i<nums.size(); i++){
        maxN = max(maxN, nums[i]);
    }

    return maxN;
}

int timeTaken(vector<int>& nums, int d){
    long long time = 0;

    for (int i=0; i<nums.size(); i++){
        if (nums[i]%d != 0){
            time += (long long)(nums[i]/d) + 1LL;
        }
        else {
            time += (long long)(nums[i]/d);
        }
    }

    return time;
}

int minimumRateToEatBananas(vector<int>& nums, int h) {
    int maxN = maxArr(nums);

    int low = 1, high = maxN, mid;

    int ans = INT_MAX;

    while(low<=high){
        mid = low + (high-low)/2;

        long long time = timeTaken(nums, mid);

        if (time <= h) {
            ans = min(ans, mid);
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }

    return ans;
}