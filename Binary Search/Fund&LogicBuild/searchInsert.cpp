#include <iostream>
using namespace std;

int searchInsert(vector<int> &nums, int target)  {
    int low = 0, high = nums.size()-1;

    if (target < nums[low]) return 0;
    else if (target > nums[high]) return high+1;

    while (low<=high){

        /*
        if (low==high){
            if (nums[low] < target) return low+1;
            else return low;
        }
        */

        int mid = (low+high)/2;

        if (nums[mid] == target) return mid;
        else if (nums[mid] < target) low = mid+1;
        else high = mid-1;
    }

    /*
    if (nums[high] < target) return high+1;
    else return high-1;
    */
    
    return low;
}