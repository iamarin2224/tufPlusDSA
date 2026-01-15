#include <iostream>
using namespace std;

int upperBound(vector<int> &nums, int element, int m){\
    //default ans is m, as it will find number of elements less than equal to element
    int ans = m;

    int low = 0, high = nums.size()-1;

    while (low <= high){
        int mid = low + (high-low)/2;

        if (nums[mid] > element){
            ans = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }

    return ans;
}

//counts number of element smaller than equal to element
int smallCount(vector<vector<int>> &matrix, int element){
    int cnt = 0;
    for (int i=0; i<matrix.size(); i++){
        cnt += upperBound(matrix[i], element, matrix[0].size());
    }
    return cnt;
}

int findMedian(vector<vector<int>> &matrix) {
    int n = matrix.size(), m = matrix[0].size();

    int low = INT_MAX,  high = INT_MIN;

    //Search space btw min and max of matrix
    for (int i=0; i<n; i++){
        low = min(low, matrix[i][0]);
        high = max(high, matrix[i][m-1]);
    }

    //Number of elements greater than mid must be >req for it to be valid median then we will search for even lower value
    int req = (n * m)/2;

    while (low <= high){
        int mid = low + (high-low)/2;

        //count number of elements less than equal to mid
        int cnt = smallCount(matrix, mid);

        if (cnt <= req) low = mid+1;    //search for greater elements
        else high = mid-1;
    }   

    return low; 
    //as previously possible was high, after loop termination polarity will change so low will be the answer
}