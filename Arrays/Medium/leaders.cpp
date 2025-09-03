#include <iostream>
#include <vector>
using namespace std;

vector<int> leaders(vector<int>& nums){
    int n = nums.size();

    vector<int> ans;

    ans.push_back(nums[n-1]);
    int maxNum = nums[n-1];

    for (int i=n-2; i>=0; i--){
        if (nums[i]>maxNum){
            ans.push_back(nums[i]);
            maxNum = nums[i];
        }
    }

    return ans;
}

int main(){

    int n; cin>>n;
    vector<int> arr(n);
    for (int i=0; i<n; i++){
        cin>>arr[i];
    }

    vector<int> ans = leaders(arr);

    cout<<"The array of leaders is: \n";
    for (auto it: ans){
        cout<<it<<" ";
    }

    return 0;
}