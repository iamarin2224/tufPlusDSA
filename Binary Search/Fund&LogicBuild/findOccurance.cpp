#include <bits/stdc++.h>
using namespace std;

//? My approach, finding mid then linear search 
/*
vector<int> searchRange(vector<int> &nums, int target) {
    
if (nums.empty()) return {-1, -1};

int n = nums.size();

int low = 0, high = n-1;

int mid;
while (low<=high){
    mid = low + (high-low)/2;
    
    if (nums[mid] == target) break;
    else if (nums[mid] < target) low = mid+1;
    else high = mid-1;
}

if (low<=high){
    int first = mid, last = mid;
    
    while (first>0 && nums[first-1]==target) first--;
    while (last<n-1 && nums[last+1]==target) last++;    
    ?the two loops at worst case(all equal to target) can take up to O(n) so, better approach needed.
    
    return {first, last};
}

return {-1, -1};

}
*/

/*
int lowerBound(vector<int>& nums, int x){
    int low = 0, high = nums.size()-1;
    
    while (low<=high){
        if (low == high && nums[low]>=x) return low;
        
        int mid = low + (high-low)/2;
        
        if (nums[mid] < x) low = mid+1;
        else high = mid;
    }
    
    return nums.size();
}

int upperBound(vector<int>& nums, int x){
    int low = 0, high = nums.size()-1;
    
    while (low<=high){
        if (low == high && nums[low]>x) return low;
        
        int mid = low + (high-low)/2;
        
        if (nums[mid] <= x) low = mid+1;
        else high = mid;
    }
    
    return nums.size();
}

vector<int> searchRange(vector<int> &nums, int target) {
    int firstOcc = lowerBound(nums, target);
    
    if (firstOcc == nums.size() || nums[firstOcc] != target) return {-1, -1};
    
    int lastOcc = upperBound(nums, target) - 1;
    ?as upper bound points to index just greater than given num
    
    return {firstOcc, lastOcc};
    
}
*/

//? Two BS approach
int firstOcc(vector<int>& nums, int x){
    int low = 0, high = nums.size()-1;
    int first = -1;
    
    while (low<=high){
        int mid = low + (high-low)/2;
        
        if (nums[mid] == x){
            first = mid;
            high = mid-1;
        } 
        else if (nums[mid] < x) low = mid+1;
        else high = mid-1;
    }
    
    return first;
}

int lastOcc(vector<int>& nums, int x){
    int low = 0, high = nums.size()-1;
    int last = -1;
    
    while (low<=high){
        int mid = low + (high-low)/2;
        
        if (nums[mid] == x){
            last = mid;
            low = mid+1;
        } 
        else if (nums[mid] < x) low = mid+1;
        else high = mid-1;
    }
    
    return last;
}

vector<int> searchRange(vector<int> &nums, int target) {
    int first = firstOcc(nums, target);
    
    if (first == -1) return {-1, -1};
    
    int last = lastOcc(nums, target) ;
    
    return {first, last};
    
}