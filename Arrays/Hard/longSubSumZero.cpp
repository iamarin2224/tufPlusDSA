#include <iostream>
using namespace std;

int maxLength(vector<int>& arr) {
    int n = arr.size();
    
    unordered_map<int, int> mpp;

    int sum = 0;
    int maxLen = 0;
    for (int i=0; i<n; i++){
        sum += arr[i];

        if (sum == 0){
            maxLen = max(maxLen, i+1);
        }

        if (mpp.find(sum) != mpp.end()){
            int len = i - mpp[sum];
            maxLen = max(maxLen, len);
        }

        if  (mpp.find(sum) == mpp.end()){
            mpp[sum] = i;
        }
    }

    return maxLen;
}

int main(){

    int n; cin>>n;
    vector<int> nums(n);
    for (int i=0; i<n; i++){
        cin>>nums[i];
    }

    int answer = maxLength(nums);

    cout<<"The maximum length is: "<< answer<<endl;

    return 0;
}