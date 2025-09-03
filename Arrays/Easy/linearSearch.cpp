#include <iostream>
#include <vector>
using namespace std;

int linearSearch(vector<int>& nums, int k){
    for (int i=0; i<nums.size(); i++){
        if (nums[i]==k){
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
    int k; cin>>k;

    int index = linearSearch(arr, k);

    if (index!=-1){
        cout<<"The element "<<k<<" is at index "<<index<<endl;
    }
    else{
        cout<<"The element is not present in the array";
    }

    return 0;
}