#include <iostream>
using namespace std;

int subarraySum(vector<int>& nums, int k) {
    int n = nums.size();

    unordered_map<int, int> mpp;
    int preSum = 0, cnt = 0;

    mpp[0] = 1;

    for (int i=0; i<n; i++){
        preSum += nums[i];

        int rem = preSum-k;

        if (mpp.find(rem) != mpp.end()){
            cnt += mpp[rem];
        }

        mpp[preSum]++;
    }

    return cnt;
}

int main(){

    int n; cin>>n;
    vector<int> arr(n);
    for (int i=0; i<n; i++){
        cin>>arr[i];
    }
    int k; cin>>k;

    int ans = subarraySum(arr, k);

    cout<<"Subarrays with sum "<<k<<" is: "<<ans<<endl;

    return 0;
}