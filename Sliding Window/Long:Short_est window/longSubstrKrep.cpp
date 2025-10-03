#include <bits/stdc++.h>
using namespace std;

int kDistinctChar(string& s, int k) {
    int n = s.size();

    int l=0, r=0;
    int maxlen = 0;

    unordered_map<char, int> mpp;

    while (r < n){
        mpp[s[r]]++;

        if (mpp.size() > k){
            mpp[s[l]]--;
            if (mpp[s[l]] == 0) mpp.erase(s[l]);
            l++;
        }

        if (mpp.size() <= k){
            maxlen = max(maxlen, r-l+1);
        }

        r++;
    }

    return maxlen;
}