#include <iostream>
using namespace std;

//? DP approach by chatgpt
// int maxProduct(vector<int>& nums) {
//     int curMax = nums[0];
//     int curMin = nums[0];
//     int maxProd = nums[0];

//     for (int i=0; i<nums.size(); i++){

//         if (nums[i] < 0){
//             swap (curMax, curMin);
//         }

//         curMax = max(nums[i], curMax);
//         curMin = min(nums[i], curMin);

//         maxProd = max(maxProd, curMax);
//     }

//     return maxProd;
// }

//? Prefix and Suffix approach
int maxProduct(vector<int>& nums){
    int n = nums.size();

    int prefix = 1, suffix = 1;

    int maxProd = INT_MIN;

    for (int i=0; i<n; i++){
        if (prefix == 0) prefix = 1;
        if (suffix == 0) suffix = 1;

        prefix *= nums[i];
        suffix *= nums[n-i-1];

        maxProd = max(maxProd, max(prefix, suffix));
    }

    return maxProd;
}

int main(){
    int n; cin>>n;
    vector<int> nums(n);
    for (int i=0; i<n; i++){
        cin>>nums[i];
    }

    int maxProd = maxProduct(nums);     

    cout<<"The maximum product of given array is: "<<maxProd<<endl;

    return 0;
}