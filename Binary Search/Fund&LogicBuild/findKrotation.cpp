#include <iostream>
using namespace std;

int findKRotation(vector<int> &nums){
    int low = 0, high = nums.size()-1;

    while(low<=high){
        int mid = low + (high-low)/2;

        if (low == high) break;

        if (nums[mid] <= nums[high]){  //right is sorted
            high = mid;
        }
        
        else{ 
            low = mid+1;
        } 
    }

    return low;
}
