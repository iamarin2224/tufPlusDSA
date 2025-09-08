#include <bits/stdc++.h>
using namespace std;

static bool cmp(vector<int> &m1, vector<int> &m2){
    if (m1[1] != m2[1]){
        return m1[1] < m2[1];
    }
    return m1[0] > m2[0];
}

int maxMeetings(vector<int>& start, vector<int>& end){
    vector<vector<int>> meetings;
    for (int i=0; i<start.size(); i++){
        meetings.push_back({start[i], end[i]});
    }

    sort(meetings.begin(), meetings.end(), cmp);

    int cnt = 1;

    vector<int> curMeeting = meetings[0];

    for (int i=1; i<meetings.size(); i++){
        if (meetings[i][0] > curMeeting[1]){
            cnt++;
            curMeeting = meetings[i];
        }
    }

    return cnt;
}