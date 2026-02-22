#include <iostream>
using namespace std;

//Min-Heap

void heapifyUp(vector<int> &nums, int ind){
    int parentInd = (ind-1)/2;
    
    if (parentInd >= 0 && nums[parentInd] > nums[ind]){
        swap(nums[parentInd], nums[ind]);
        heapifyUp(nums, parentInd);
    }
}

void heapifyDown(vector<int> &nums, int ind){
    int leftInd = 2*ind+1;
    int rightInd = 2*ind+2;
    int smallest = ind;

    if (leftInd < nums.size() && nums[leftInd] < nums[smallest]){
        smallest = leftInd;
    }
    if (rightInd < nums.size() && nums[rightInd] < nums[smallest]){
        smallest = rightInd;
    }

    if (smallest != ind){
        swap(nums[smallest], nums[ind]);
        heapifyDown(nums, smallest);
    }
}

void heapify(vector<int> &nums, int ind, int val) {
    int temp = nums[ind];
    nums[ind] = val;

    if (val <= temp){
        heapifyUp(nums, ind);
    }
    else{
        heapifyDown(nums, ind);
    }
}