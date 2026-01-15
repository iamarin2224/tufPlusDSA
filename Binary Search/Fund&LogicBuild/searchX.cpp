#include <iostream>
using namespace std;

//? Iterative Approach
int search(vector<int> &nums, int target){
    int low = 0, high = nums.size()-1;

    while (low<=high){
        int mid = (low+high)/2;

        if (nums[mid] == target) return mid;
        else if (nums[mid] < target) low = mid+1;
        else high = mid-1;
    }

    return -1;
}

//? Recursive Approach
int recursiveSearch(vector<int> &nums, int low, int high, int target){
    if (low > high) return -1;

    int mid = (low+high)/2;

    if (nums[mid] == target) return mid;
    else if (nums[mid] < target) return recursiveSearch(nums, mid+1, high, target);
    else return recursiveSearch(nums, low, mid-1, target);
}
