#include <bits/stdc++.h>
using namespace std;

long long int merge(vector<int> nums, int low, int mid, int high){
    vector<int> temp;

    int left = low, right = mid+1;

    long long int cnt = 0;

    while (left<=mid && right<=high){
        if (nums[left] <= nums[right]){
            temp.push_back(nums[left]);
            left++;
        }
        else {
            cnt += (long long int)(mid-left+1);
            temp.push_back(nums[right]);
            right++;
        }
    }
    while (left<=mid){
        temp.push_back(nums[left]);
        left++;
    }
    while (right<=high){
        temp.push_back(nums[right]);
        right++;
    }

    for (int i=low; i<=high; i++){
        nums[i] = temp[i-low];
    }

    return cnt;
}

long long int mergeSort(vector<int>& nums, int low, int high){
    long long int cnt = 0;
    int mid = (low+high)/2;
    if (low>=high) return cnt;
    cnt += mergeSort(nums, low, mid);
    cnt += mergeSort(nums, mid+1, high);
    cnt += merge(nums, low, mid, high);
    return cnt;
}   

long long int numberOfInversions(vector<int> nums) {
    long long int cnt = mergeSort(nums, 0, nums.size()-1);
    return cnt;
}

int main(){
    int n; cin>>n;
    vector<int> nums(n);
    for (int i=0; i<n; i++){
        cin>>nums[i];
    }

    long long int inversions = numberOfInversions(nums);     

    cout<<"The number of inversions are: "<<inversions<<endl;

    return 0;
}