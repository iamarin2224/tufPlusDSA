#include <iostream>
using namespace std;

bool searchMatrix(vector<vector<int>> &mat, int target){
    int r = mat.size(), c = mat[0].size();
    int n = r * c;

    int low = 0, high = n-1;

    while (low <= high){
        int mid = (low + high)/2;

        int element = mat[mid/c][mid%c];

        if (element == target) return true;
        else if (element < target) low = mid+1;
        else high = mid-1;
    }

    return false;
}