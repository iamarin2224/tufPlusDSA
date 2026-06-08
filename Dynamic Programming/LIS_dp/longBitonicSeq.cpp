#include <iostream>
using namespace std;

//? My approach using BS approach to find length of LIS ending at i
//? -> the flaw is in my approach, I account for max ending at i which may or may not include i, so for indexes which do not include ith element the bitonic length comes out to be wrong
//? -> but as for almost every cases as the max bitonic will peak at that element which is included in both LIS and LDS thus it passes all test cases
int LongestBitonicSequence(vector<int>& nums) {
    int n = nums.size();

    vector<int> dpInc(n, 1);
    vector<int> dpDec(n, 1);

    vector<int> temp;
    temp.push_back(nums[0]);

    for (int i=1; i<n; i++){
        if (nums[i] > temp.back()){
            temp.push_back(nums[i]);
        }
        else{
            int ind = lower_bound(temp.begin(), temp.end(), nums[i])-temp.begin();

            temp[ind] = nums[i];
        }
        dpInc[i] = temp.size();
    }

    temp.clear();
    temp.push_back(nums[n-1]);

    for (int i=n-1; i>=0; i--){
        if (nums[i] > temp.back()){
            temp.push_back(nums[i]);
        }
        else{
            int ind = lower_bound(temp.begin(), temp.end(), nums[i])-temp.begin();

            temp[ind] = nums[i];
        }
        dpDec[i] = temp.size();
    }

    int maxLen = 0;
    
    for (int i=0; i<n; i++){
        maxLen = max(maxLen, dpInc[i]+dpDec[i]-1);
    }

    return maxLen;
}

//? Standard Approach
int LongestBitonicSequence(vector<int>& nums) {
    int n = nums.size();

    vector<int> dpInc(n, 1);
    vector<int> dpDec(n, 1);

    int maxLen = 0;

    for (int i=0; i<n; i++){
        for (int j=0; j<i; j++){
            if (nums[j] < nums[i] && dpInc[i] < dpInc[j]+1){
                dpInc[i] = dpInc[j]+1;
            }
        }
    }

    for (int i=n-1; i>=0; i--){
        for (int j=n-1; j>i; j--){
            if (nums[j] < nums[i] && dpDec[i] < dpDec[j]+1){
                dpDec[i] = dpDec[j]+1;
            }
        }

        maxLen = max(maxLen, dpInc[i] + dpDec[i] - 1);
    }

    return maxLen;
}