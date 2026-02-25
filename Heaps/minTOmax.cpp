#include <iostream>
using namespace std;

void heapifyDown(vector<int> &nums, int ind){
    int leftInd = 2*ind+1;
    int rightInd = 2*ind+2;
    int largest = ind;

    if (leftInd < nums.size() && nums[leftInd] > nums[largest]){
        largest = leftInd;
    }
    if (rightInd < nums.size() && nums[rightInd] > nums[largest]){
        largest = rightInd;
    }

    if (largest != ind){
        swap(nums[largest], nums[ind]);
        heapifyDown(nums, largest);
    }
}

vector<int> minToMaxHeap(vector<int>& nums) {
    int n = nums.size();
    for (int i = n/2-1; i>=0; i--){
        heapifyDown(nums, i);
    }

    return nums;
}