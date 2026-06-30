#include <iostream>
using namespace std;

static bool cmp(vector<int> &a, vector<int> &b){
    if (a[1] != b[1]){
        return a[1]<b[1];
    }
    return a[0]<b[0];
}

int MaximumNonOverlappingIntervals(vector<vector<int>>& Intervals) {
    int n = Intervals.size();

    if (n == 1) return 0;

    sort(Intervals.begin(), Intervals.end(), cmp);

    int endP = 0;
    int startP = 1;

    int cnt = 0;

    while (startP < n && endP < n){
        if (Intervals[startP][0] < Intervals[endP][1]){
            cnt++;
        }
        else{
            endP = startP;
        }
        startP++;
    }

    return cnt;
}

//? Optimised
int MaximumNonOverlappingIntervals(vector<vector<int>>& Intervals) {
    int n = Intervals.size();
    if (n <= 1) return 0;

    // Sort primarily by end time. Secondary sort by start time is optional/ignored.
    sort(Intervals.begin(), Intervals.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1]; 
    });

    int cnt = 0;
    int last_end = Intervals[0][1]; // Track the actual coordinate value

    for (int i = 1; i < n; i++) {
        // If the current interval starts BEFORE the last one ends, it's an overlap
        if (Intervals[i][0] < last_end) {
            cnt++;
        } else {
            // No overlap, update our end boundary to the current interval's end
            last_end = Intervals[i][1];
        }
    }

    return cnt;
}