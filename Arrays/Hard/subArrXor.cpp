#include <bits/stdc++.h>
using namespace std;

long subarrayXor(vector<int>& arr, int k) {
    int n = arr.size();

    unordered_map<int, int> mpp;
    mpp[0] = 1;

    int preXOR = 0; long count = 0;
    for (int i=0; i<n; i++){
        preXOR = preXOR ^ arr[i];

        int req = preXOR ^ k;

        if (mpp.find(req) != mpp.end()){
            count += (long) mpp[req];
        } 

        mpp[preXOR]++;
    }

    return count;
}

int main(){

    int n; cin>>n;
    vector<int> nums(n);
    for (int i=0; i<n; i++){
        cin>>nums[i];
    }
    int k; cin>>k;

    long answer = subarrayXor(nums, k);

    cout<<"The maximum length is: "<< answer<<endl;

    return 0;
}