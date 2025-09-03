#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &nums, int cows, int minDist){
    int cowsPlaced = 1;

    int lastCow = 0, right = 1;

    while (right < nums.size()){
        if ((nums[right] - nums[lastCow]) >= minDist ){
            cowsPlaced++;
            lastCow = right++;

            if (cowsPlaced >= cows) return true;
        }
        else{
            right++;
        }
    }

    return false;
}

int aggressiveCows(vector<int> &nums, int k) {
    sort(nums.begin(), nums.end());

    int low = 1, high = nums[nums.size()-1] - nums[0], mid;

    int ans = INT_MIN;

    while (low <= high){
        mid = low + (high-low)/2;

        bool possible = isPossible(nums, k, mid);

        if (possible){
            ans = max(ans, mid);
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }

    return ans;
}