#include <iostream>
#include <vector>
using namespace std;

int maxSubArray(vector<int>& nums) {
    int currentSum = 0;
    int maxSum = nums[0];
    for (int i=0; i<nums.size(); i++){
        currentSum = max(currentSum+nums[i], nums[i]);
        maxSum = max(maxSum, currentSum);
    }
    return maxSum;
}

int main(){

    int n; cin>>n;
    vector<int> arr(n);
    for (int i=0; i<n; i++){
        cin>>arr[i];
    }

    int ans = maxSubArray(arr);

    cout<<"The answer is: "<<ans<<endl;

    return 0;
}