#include <iostream>
using namespace std;

bool isHeap(vector<int>& nums) {
    int n = nums.size();

    for (int i=0; i<=(n/2)-1; i++){
        int leftInd = 2*i+1;
        int rightInd = 2*i+2;

        if (leftInd < n && nums[leftInd] < nums[i]){
            return false;
        }
        if (rightInd < n && nums[rightInd] < nums[i]){
            return false;
        }
    }

    return true;
}