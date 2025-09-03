#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &arr, int low, int mid, int high){

    vector<int> temp;
    int left = low;
    int right = mid+1;

    while (left<=mid && right<=high){
        if (arr[left] <= arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }

    while (left<=mid){
        temp.push_back(arr[left]);
        left++;
    }

    while (right<=high){
        temp.push_back(arr[right]);
        right++;
    }

    for (int i=low; i<=high; i++){
        arr[i] = temp[i-low];
    }

}

void mergerSort(vector<int>& nums, int low, int high){
    if (low>=high) return;
    int mid = (low+high)/2;
    mergerSort(nums, low, mid);
    mergerSort(nums, mid+1, high);
    merge(nums, low, mid, high);
}

int missingNum(vector<int>& nums){
    mergerSort(nums, 0, nums.size()-1);
    for (int i=0; i<nums.size(); i++){
        if (nums[i]!=i){
            return i;
        }
    }
    return -1;
}

int main(){

    int n; cin>>n;
    vector<int> arr(n);
    for (int i=0; i<n; i++){
        cin>>arr[i];
    }

    int answer = missingNum(arr);

    cout<<"The missing number is: "<<answer<<endl;

    return 0;
}