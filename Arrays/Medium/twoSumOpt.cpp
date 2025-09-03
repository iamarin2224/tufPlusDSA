#include <bits/stdc++.h>
using namespace std;

bool twoSum(vector<int>& nums, int target) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int low = 0, high = n-1; int sum;
    while(low<high && high<=n-1){
        sum = nums[low] + nums[high];
        if (sum>target){
            high--;
        }
        else if (sum<target){
            low++;
        }
        else if (sum==target){
            return true;
        }
    }
    return false;
}

int main(){

    int n; cin>>n;
    vector<int> arr(n);
    for (int i=0; i<n; i++){
        cin>>arr[i];
    }
    int k; cin>>k;

    bool answer = twoSum(arr, k);

    if (answer) cout<<"Yes, the sum exists"<<endl;
    else cout<<"No, the sum do not exist"<<endl;

    return 0;
}