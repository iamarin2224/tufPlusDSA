#include <iostream>
using namespace std;

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

void buildMinHeap(vector<int> &nums) {
    int n = nums.size();
    for (int i = n/2-1; i>=0; i--){
        heapifyDown(nums, i);
    }
}