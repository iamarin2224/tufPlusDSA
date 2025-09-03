#include <iostream>
#include <vector>
using namespace std;

int maxSubArray(vector<int>& nums) {
    int currentSum = 0;
    int maxSum = nums[0];

    int start = 0;
    int ansStart = -1, ansEnd = -1;

    for (int i=0; i<nums.size(); i++){

        if (currentSum==0) start = i;

        currentSum+=nums[i];

        if (currentSum >= maxSum){
            maxSum = currentSum;
            ansStart = start;
            ansEnd = i;
        }

        if (currentSum<0){
            currentSum = 0;
        }
    }

    cout<<"The array: ";
    for (int j=ansStart; j<=ansEnd; j++) {
        cout<<nums[j]<<" ";
    }
    cout<<" has the maximum sum";

    return maxSum;
}

int main(){

    int n; cin>>n;
    vector<int> arr(n);
    for (int i=0; i<n; i++){
        cin>>arr[i];
    }

    int ans = maxSubArray(arr);

    cout<<" with maximum sum = "<<ans<<endl;

    return 0;
}