#include <iostream>
using namespace std;

int search(vector<int> &nums, int k){
    int low = 0, high = nums.size()-1;

    while(low<=high){
        int mid = low + (high-low)/2;

        if (nums[mid] == k) return mid;
        else if (nums[low] <= nums[mid]){    //left half sorted
            if (k >= nums[low] && k<nums[mid]){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        else {    //right half sorted
            if (k <= nums[high] && k>nums[mid]){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        } 
    }

    return -1;
}