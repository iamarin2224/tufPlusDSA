#include <iostream>
using namespace std;

vector<int> getFloorAndCeil(vector<int> nums, int x) {
    int low = 0, high = nums.size()-1;

    if (nums.empty()) return {-1, -1};

    if (x < nums[0]){
        return {-1, nums[0]};
    }

    if (x > nums[high]){
        return {nums[high], -1};
    }

    while (low<=high){
        int mid = low + (high-low)/2;

        if (nums[mid] == x) return {nums[mid], nums[mid]};
        else if (nums[mid] < x) low = mid+1;
        else high = mid-1;
    }

    return {nums[high], nums[low]};
}