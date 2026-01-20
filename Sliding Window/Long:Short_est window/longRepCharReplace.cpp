#include <iostream>
using namespace std;

int characterReplacement(string s, int k) {
    int n = s.size();

    int l=0, r=0;
    int maxFr=0;
    int maxlen=0;
    unordered_map<char, int> mpp;

    while (r < n){
        mpp[s[r]]++;
        maxFr = max(maxFr, mpp[s[r]]);

        int flips = (r-l+1)-maxFr;

        if (flips > k){
            mpp[s[l]]--;
            l++;
        }

        if (flips <= k){
            maxlen = max(maxlen, r-l+1);
        }

        r++;
    }

    return maxlen;
}