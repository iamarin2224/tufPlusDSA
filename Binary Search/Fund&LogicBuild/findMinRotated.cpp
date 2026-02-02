#include <iostream>
using namespace std;

int findMin(vector<int> &arr){
    int low = 0, high = arr.size()-1;

    while(low<=high){
        int mid = low + (high-low)/2;

        if (low == high) break;

        if (arr[mid] <= arr[high]){  //right is sorted
            high = mid;
        }
        
        else{ 
            low = mid+1;
        } 
    }

    return arr[low];
}
