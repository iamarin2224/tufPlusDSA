#include <bits/stdc++.h>
using namespace std;

void sortColors(vector<int>& nums) {
    int n = nums.size();
    int left = 0, mid = 0, right = n-1;
    while(mid<=right){
        if (nums[mid]==0){
            swap(nums[left], nums[mid]);
            left++;
            mid++;
        }
        else if (nums[mid]==1){
            mid++;
        }
        else{
            swap(nums[right], nums[mid]);
            right--;
        }
    }
}

int main(){

    int n; cin>>n;
    vector<int> arr(n);
    for (int i=0; i<n; i++){
        cin>>arr[i];
    }

    sortColors(arr);

    cout<<"The answer is: ";
    for (auto it: arr){
        cout<<it<<" ";
    }

    return 0;
}