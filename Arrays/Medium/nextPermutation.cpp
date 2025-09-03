#include <iostream>
#include <vector>
using namespace std;

void reverseMy(vector<int>& nums, int start, int end){
    int i = start, j = end;
    while (i<j){
        swap(nums[i], nums[j]);
        i++; j--;
    }
}

void nextPermutation(vector<int>& nums){
    int n = nums.size();
    
    int brkPt = -1;
    for (int i=n-2; i>=0; i--){
        if (nums[i] < nums[i+1]){
            brkPt = i;
            break;
        }
    }

    if (brkPt==-1){
        reverseMy(nums, 0, n-1);
        return;
    }

    for (int i=n-1; i>brkPt; i--){
        if (nums[i] > nums[brkPt]){
            swap(nums[i], nums[brkPt]);
            break;
        }
    }

    reverseMy(nums, brkPt+1, n-1);
}

int main(){

    int n; cin>>n;
    vector<int> arr(n);
    for (int i=0; i<n; i++){
        cin>>arr[i];
    }

    nextPermutation(arr);

    cout<<"The next permutation of the array is: \n";
    for (int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}