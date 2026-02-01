#include <iostream>
using namespace std;

vector<int> maxSlidingWindow(vector<int> &arr, int k) {
    vector<int> ans;
    
    //dq to store the index, and allow operation from both end
    deque<int> dq;

    for (int i=0; i<arr.size(); i++){
        //remove from front if out of range of current required window
        if (!dq.empty() && dq.front() <= i-k) dq.pop_front();

        //maintain monotonic stack 
        while (!dq.empty() && arr[dq.back()] <= arr[i]){
            dq.pop_back();
        }
        dq.push_back(i);

        //push to answer if of proper index
        if (i >= k-1) {
            ans.push_back(arr[dq.front()]);
        }
    }

    return ans;
}