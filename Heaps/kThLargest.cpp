#include <iostream>
using namespace std;

void heapifyDown(vector<int> &nums, int ind, int n){
    int leftInd = 2*ind+1;
    int rightInd = 2*ind+2;
    int largest = ind;

    if (leftInd < n && nums[leftInd] > nums[largest]){
        largest = leftInd;
    }
    if (rightInd < n && nums[rightInd] > nums[largest]){
        largest = rightInd;
    }

    if (largest != ind){
        swap(nums[largest], nums[ind]);
        heapifyDown(nums, largest, n);
    }
}

void buildMaxHeap(vector<int> &nums) {
    int n = nums.size();
    for (int i = n/2-1; i>=0; i--){
        heapifyDown(nums, i, n);
    }
}

int kthLargestElement(vector<int>& nums, int k) {
    buildMaxHeap(nums);

    int n = nums.size();

    for (int i=0; i<k-1; i++){
        swap(nums[0], nums[n-i-1]);
        heapifyDown(nums, 0, n-i-1);
    }

    return nums[0];
}