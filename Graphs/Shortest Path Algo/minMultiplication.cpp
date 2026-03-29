#include <iostream>
#include <unordered_set>
using namespace std;

int minimumMultiplications(vector<int> &arr, int start, int end) {
    int n = arr.size();

    if (start == end) return 0;

    queue<pair<int, int>> q;

    unordered_set<int> st;

    q.push({start, 0});
    st.insert(start);

    while (!q.empty()){
        int curVal = q.front().first;
        int curSteps = q.front().second;
        q.pop();

        for (int i=0; i<n; i++){
            int newVal = (curVal*arr[i])%100000;

            if (newVal == end) return curSteps+1;

            if (st.find(newVal) == st.end()){
                st.insert(newVal);
                q.push({newVal, curSteps+1});
            }
        }
    }

    return -1;
}