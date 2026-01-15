#include <iostream>
using namespace std;

//? Better || TC: O(log(r)*log(c));
/*
bool binarySearch(vector<int> row, int target){
    int low = 0, high = row.size()-1;
    
    while (low <= high){
        int mid = (low + high)/2;
        
        if (row[mid] == target) return true;
        else if (row[mid] < target) low = mid+1;
        else high = mid-1;
    }
    
    return false;
}

bool searchMatrix(vector<vector<int>> &mat, int target){
    int r = mat.size(); 
    int c = mat[0].size();
    
    int low = 0, high = r-1;
    
    while (low <= high){
        int mid = (low + high)/2;
        
        if (mat[mid][0] <= target && mat[mid][c-1] >= target){
            if (binarySearch(mat[mid], target)) return true;
        }
        else if (mat[mid][0] > target) high = mid-1;
        else low = mid+1;
    }
    
    return false;
}
*/

bool searchMatrix(vector<vector<int>> &mat, int target){
    int r = mat.size(); 
    int c = mat[0].size();
    
    int row = 0, col = c-1;

    while (row < r && col >= 0){
        if (mat[row][col] == target) return true;
        else if (mat[row][col] < target) row++;
        else col--;
    }

    return false;
}