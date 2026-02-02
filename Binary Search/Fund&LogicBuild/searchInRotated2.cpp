#include <iostream>
using namespace std;

bool searchInARotatedSortedArrayII(vector<int> &nums, int k){
    int low = 0, high = nums.size()-1;

    while(low<=high){
        int mid = low + (high-low)/2;

        if (nums[mid] == k) return true;

        if (nums[mid] == nums[low] == nums[high]) low++, high--;

        else if (nums[low] <= nums[mid]){    //left half sorted
            if (k >= nums[low] && k<nums[mid]){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }

        //!else if (nums[mid]<=nums[high])
        //? instead of else if just use else
        
        else{    //right half sorted
            if (k <= nums[high] && k>nums[mid]){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        } 
    }

    return false;
}