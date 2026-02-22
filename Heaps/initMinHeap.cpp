#include <iostream>
using namespace std;

class Solution{
    vector<int> heap;

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

    public:

        void initializeHeap(){
            heap.clear();
        }

        void insert(int key){
            heap.push_back(key);
            heapifyUp(heap, heap.size()-1);
        }

        void changeKey(int index, int new_val){
            if (index >= heap.size()) return;

            int temp = heap[index];
            heap[index] = new_val;

            if (new_val <= temp){
                heapifyUp(heap, index);
            }
            else{
                heapifyDown(heap, index);
            }
        }

        void extractMin(){
            int n = heap.size();

            if (n == 0) return;

            swap(heap[0], heap[n-1]);
            heap.pop_back();

            if (n == 1) return;

            heapifyDown(heap, 0);
        }

        bool isEmpty(){
            return heap.size() == 0;
        }

        int getMin(){
            if (heap.size() == 0) return -1;
            return heap.front();
        }

        int heapSize(){
            return heap.size();
        }   
};