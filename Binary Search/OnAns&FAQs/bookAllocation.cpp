#include <iostream>
#include <numeric>
using namespace std;

int studentCount(vector<int> &nums, int maxPages){
    int studentCount = 1; //start with one student, as we alloting him pages
    int pageCount = 0;

    for (int i=0; i<nums.size(); i++){
        if ((pageCount + nums[i]) <= maxPages){
            pageCount += nums[i];
        }
        else{
            studentCount++;
            pageCount = nums[i]; //as we have to allocate the current nums[i]
        }
    }

    return studentCount;
}

int findPages(vector<int> &nums, int m)  {
    if (m > nums.size()) return -1;
    
    int low = *max_element(nums.begin(), nums.end()), 
    high = accumulate(nums.begin(), nums.end(), 0), 
    mid;

    while (low <= high){
        mid = low + (high-low)/2;

        int students = studentCount(nums, mid);

        if (students > m){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }

    return low;
}