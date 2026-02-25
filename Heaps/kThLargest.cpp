#include <iostream>
using namespace std;

//Better Approach

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

// Optimal Approach

int randomIndex(int left, int right){
    srand(time(NULL));
    return (rand()%(right-left+1))+left;
}

int partition(vector<int>& nums, int pivotInd, int left, int right){
    swap(nums[pivotInd], nums[left]);

    int ind = left+1;

    for(int i=left+1; i<=right; i++){
        if (nums[i] > nums[left]){
            swap(nums[i], nums[ind]);
            ind++;
        }
    }

    swap(nums[left], nums[ind-1]);

    return ind-1;
}

int kthLargestElement(vector<int>& nums, int k) {
    if (k > nums.size()) return -1;

    int left = 0, right = nums.size()-1;

    while (true){
        int pivotInd = randomIndex(left, right);

        pivotInd = partition(nums, pivotInd, left, right);

        if (pivotInd == k-1) return nums[pivotInd];

        else if (pivotInd > k-1) right = pivotInd-1;

        else left = pivotInd+1;
    }
    
    return -1;
}