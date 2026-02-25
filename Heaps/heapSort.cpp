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

void extractMax(vector<int> &nums, int n){
    if (n <= 1) return;

    swap(nums[0], nums[n-1]);

    heapifyDown(nums, 0, n-1);
}

void heapSort(vector<int>&nums) {
    int n = nums.size();
    vector<int> ans(n);

    for (int i = n/2-1; i>=0; i--){
        heapifyDown(nums, i, n);
    }

    for (int i=0; i<n; i++){
        extractMax(nums, n-i);
    }
}