#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> mpp;
    int required;
    for (int i=0; i<nums.size(); i++){
        required = target-nums[i];
        if (mpp.find(required) != mpp.end() && mpp[required] != i){
            return {i, mpp[required]};
        }
        mpp[nums[i]] = i;
    }
    return {-1, -1};
}

int main(){

    int n; cin>>n;
    vector<int> arr(n);
    for (int i=0; i<n; i++){
        cin>>arr[i];
    }
    int k; cin>>k;

    vector<int> answer = twoSum(arr, k);

    cout<<"The answer is: ";
    for (auto it: answer){
        cout<<it<<" ";
    }

    return 0;
}