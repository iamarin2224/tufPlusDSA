#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> insertNewInterval(vector<vector<int>>& Intervals, vector<int>& newInterval){
    int n = Intervals.size();

    vector<vector<int>> ans;

    int start = newInterval[0], end = newInterval[1];
    
    int current = 0;

    while (current<n && Intervals[current][1]<start){
        ans.push_back(Intervals[current]);
        current++;
    }

    if (current!= n && Intervals[current][0] < start){
        start = Intervals[current][0];
    }

    while (current<n && Intervals[current][1]<end){
        current++;
    }

    if (current!= n && Intervals[current][0]<=end){
        end = Intervals[current][1];
        current++;
    }

//? Instead of 2ifs and a while statement the work of determining the new interval can be done in this single loop

/*
while(i < n && intervals[i][0] <= newInterval[1]){
    /* Update the start time of newInterval to theminimum of its current start time and the start time of the current interval
    
    *newInterval[0] = min(newInterval[0], intervals[i][0]); 
    
    /* Update the end time of newInterval to the maximum of its current end time and the end time of the current interval 
    
    *newInterval[1] = max(newInterval[1], intervals[i][1]); 
    
    /* Move to the next interval
    
    *i = i + 1; 
}
*/

    ans.push_back({start, end});

    while (current<n){
        ans.push_back(Intervals[current]);
        current++;
    }

    return ans;

}