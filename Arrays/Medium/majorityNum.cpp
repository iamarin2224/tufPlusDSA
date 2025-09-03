#include <iostream>
#include <vector>
using namespace std;

//? Moore's Voting Algorithm
int majorityElement(vector<int>& nums) {
    int cnt = 0;
    int ele;
    for (int i=0; i<nums.size(); i++){
        if (cnt == 0){
            ele = nums[i];
            cnt++;
        }
        else if (nums[i]==ele){
            cnt++;
        }
        else{
            cnt--;
        }
    }
    return ele;
}

int main(){

    int n; cin>>n;
    vector<int> arr(n);
    for (int i=0; i<n; i++){
        cin>>arr[i];
    }

    int ans = majorityElement(arr);

    cout<<"The answer is: "<<ans<<endl;

    return 0;
}