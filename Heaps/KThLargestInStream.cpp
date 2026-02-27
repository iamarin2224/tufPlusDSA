#include <iostream>
using namespace std;

class KthLargest {

    priority_queue<int, vector<int>, greater<int>> pq;
    int k;
    
    public:
        KthLargest(int k, vector<int>& nums) {
            this->k = k;
            if (k > nums.size()){
                for (int num : nums){
                    pq.push(num);
                }

                return;
            }

            for (int i=0; i<k; i++){
                pq.push(nums[i]);
            }

            for (int i=k; i<nums.size(); i++){
                if (nums[i] > pq.top()){
                    pq.pop();
                    pq.push(nums[i]);
                }
            }
        }

        int add(int val) {
            if (k > pq.size()){
                pq.push(val);
            }
            else if (val > pq.top()){
                pq.pop();
                pq.push(val);
            }

            return pq.top();
        }
};