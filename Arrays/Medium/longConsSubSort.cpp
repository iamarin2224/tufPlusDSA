#include <bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int>& nums){
    int n = nums.size();
    if (n==0) return 0;

    sort(nums.begin(), nums.end());

    int longest = 1, count = 0, lastSmaller = INT_MIN;

    for (int i=0; i<n; i++){
        if (nums[i] == lastSmaller+1){
            count++;
            lastSmaller = nums[i];
        }
        else if (nums[i] != lastSmaller){
            count = 1;
            lastSmaller = nums[i];
        }  
        longest = max(longest, count);
    }

    return longest;
}

int main(){

    int n; cin>>n;
    vector<int> arr(n);
    for (int i=0; i<n; i++){
        cin>>arr[i];
    }

    int ans = longestConsecutive(arr);

    cout<<"The length of the longest subarray of consecutive elements is: "<<ans<<endl;

    return 0;
}