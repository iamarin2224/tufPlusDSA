#include <iostream>
#include <vector>
using namespace std;

void moveZeroes(vector<int>& nums){
    int n = nums.size();
    int zp=0, nzp=1;
    while (zp<=n-1 && nzp<=n-1){
        if (nums[nzp]==0 || nzp<=zp){ 
            nzp++;
            if (nzp>n-1) return;
        }
        if (nums[zp]!=0){
            zp++;
            if (zp>n-1) return;
        } 
        else if (nums[zp]==0 && nums[nzp]!=0){
            swap(nums[zp], nums[nzp]);
            zp++;
        }
    }
}

int main(){

    int n; cin>>n;
    vector<int> arr(n);
    for (int i=0; i<n; i++){
        cin>>arr[i];
    }

    moveZeroes(arr);

    cout<<"The array after moving zeroes is: \n";
    for (int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}