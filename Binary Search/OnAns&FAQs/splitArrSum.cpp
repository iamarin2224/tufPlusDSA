#include <iostream>
#include <numeric>
using namespace std;

int subArrCount(vector<int> &a, int maxSum){
    int cnt = 1;
    int sum = 0;

    for (int i=0; i<a.size(); i++){
        if (sum + a[i] <= maxSum){
            sum += a[i];
        }
        else{
            cnt++;
            sum = a[i];
        }
    }

    return cnt;
}

int largestSubarraySumMinimized(vector<int> &a, int k) {
    int low = *max_element(a.begin(), a.end()),
    high = accumulate(a.begin(), a.end(), 0),
    mid;

    while (low <= high){
        mid = low + (high-low)/2;

        int cnt = subArrCount(a, mid);

        if (cnt > k){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }

    return low;
}