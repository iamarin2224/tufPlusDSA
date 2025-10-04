#include <bits/stdc++.h>
using namespace std;

string minWindow(string s, string t) {
    int n = s.size();

    int minlen = INT_MAX;
    int cnt = 0, sInd = -1;

    for (int i=0; i<n; i++){
        int hash[256] = {0};
        for (char c: t){
            hash[c]++;
        }

        for (int j=i; j<n; j++){
            if (hash[s[j]] > 0) cnt++;

            hash[s[j]]--;

            if (cnt == t.size()){
                if ((j-i+1) < minlen){
                    minlen = j-i+1;
                    sInd = i;
                }
                break;
            }
        }
    }

    return (sInd == -1) ? "" : s.substr(sInd, minlen);
}

string minWindow(string s, string t) {
    int n = s.size();

    int l=0, r=0;
    int minlen = INT_MAX;
    int cnt = 0, sInd = -1;

    int hash[256] = {0};
    for (char c: t){
        hash[c]++;
    }

    while (r < n) {
        if (hash[s[r]] > 0) cnt++;

        hash[s[r]]--;

        while (cnt == t.size()){
            if ((r-l+1) < minlen){
                minlen = r-l+1;
                sInd = l;
            }
            
            hash[s[l]]++;

            if (hash[s[l]] > 0) cnt--;

            l++;
        }
        r++;
    }

    return (sInd == -1) ? "" : s.substr(sInd, minlen);
}