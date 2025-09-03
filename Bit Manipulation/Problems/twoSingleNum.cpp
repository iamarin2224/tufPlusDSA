#include <bits/stdc++.h>
using namespace std;

vector<int> singleNumber(vector<int>& nums){
    int req = 0;

    // XOR of the two required nums
    for (int i=0; i<nums.size(); i++){
        req ^= nums[i];
    }

    // Get the rightmost differentiating bit
    req = (req & (req-1)) ^ req;

    // bucket1 stores numbers which have diffrn bit as 1 else stored in bucket 2
    int bucket1 = 0, bucket2 = 0;

    for (int i=0; i<nums.size(); i++){
        if (nums[i] & req){
            bucket1 ^= nums[i];
        }
        else{
            bucket2 ^= nums[i];
        }
    }

    if (bucket1 > bucket2){
        return {bucket2, bucket1};
    }

    return {bucket1, bucket2};
}