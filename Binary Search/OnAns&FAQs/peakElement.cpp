#include <iostream>
using namespace std;

int findPeakElement(vector<int> &arr) {
    int n = arr.size();

    int low = 1, high = n-2;

    if (n==1 || arr[0] > arr[1]) return 0;
    else if (arr[n-1] > arr[n-2]) return n-1;

    while (low <= high){
        int mid = low + (high-low)/2;

        if (arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]) return mid;

        else if (arr[mid-1] > arr[mid]) high = mid-1;

        else low = mid+1;
    }

    return -1;
}