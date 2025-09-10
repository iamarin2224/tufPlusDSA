#include <bits/stdc++.h>
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