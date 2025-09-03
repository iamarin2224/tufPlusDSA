#include <bits/stdc++.h>
using namespace std;

//? My solution, logically correct just a bit redundant
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
*/

int lowerBound(vector<int>& nums, int x){
    int low = 0, high = nums.size()-1;
    int ans = nums.size();
    
    while (low<=high){

        int mid = low + (high-low)/2;

        if (nums[mid] >= x){
            ans = nums[mid]; //storing possible ans 
            high = mid-1;   //checking the left half
        } 
        else low = mid+1;
    }

    return ans;
}