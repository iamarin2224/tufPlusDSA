#include <bits/stdc++.h>
using namespace std;

static bool cmp(const vector<int> &a,const vector<int> &b){
    if (a[2] != b[2]){
        return (a[2] > b[2]);
    }
    return false;
}

vector<int> JobScheduling(vector<vector<int>>& Jobs) { 
    sort(Jobs.begin(), Jobs.end(), cmp);

    int maxDeadline = -1;
    for (int i=0; i<Jobs.size(); i++){
        maxDeadline = max(maxDeadline, Jobs[i][1]);
    }

    vector<int> hash(maxDeadline+1, -1);

    int cnt = 0;
    int profit = 0;

    for (int i=0; i<Jobs.size(); i++){
        for (int j = Jobs[i][1]; j>=0; j--){
            if (hash[j] == -1){
                cnt++;
                hash[j] = Jobs[i][0];
                profit += Jobs[i][2];

                break;
            }
        }
    }

    return {cnt, profit};
} 