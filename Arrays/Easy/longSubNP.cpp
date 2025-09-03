#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

//? Hashing approach
int longestSubarray(vector<int>& arr, int k) {
    unordered_map<int, int> preSum;
    int sum = 0, maxLen = 0;
    
    for (int i=0; i<arr.size(); i++){
        sum+=arr[i];

        if (sum==k){
            maxLen = max(maxLen, i+1);
        }

        int rem = sum-k;

        if (preSum.find(rem) != preSum.end()){
            int len = i-preSum[rem];
            maxLen = max(maxLen, len);
        }

        //as we require to find the longest, we only store the first occurence
        if (preSum.find(sum) == preSum.end()){
            preSum[sum] = i;
        }
    }

    return maxLen;
}

int main(){

    int n; cin>>n;
    vector<int> arr(n);
    for (int i=0; i<n; i++){
        cin>>arr[i];
    }
    int k; cin>>k;

    int answer = longestSubarray(arr, k);

    cout<<"The answer is: "<<answer<<endl;

    return 0;
}