#include <bits/stdc++.h>
using namespace std;

//? My approach
int longestNonRepeatingSubstring(string& s){
    int r = 0, l = 0;
    int maxlen = 0;

    int hashArr['z'] = {0};

    while (r < s.size()){
        char cur = s[r];

        while (hashArr[cur] != 0){
            hashArr[s[l]]--;
            l++;
        }
        maxlen = max(maxlen, r-l+1);
        hashArr[s[r]]++;
        r++;
    }

    return maxlen;
}

//? TUF apprach, storing the index of occurence
int longestNonRepeatingSubstring(string& s){
    int r = 0, l = 0;
    int maxlen = 0;

    int hashArr[256];
    for (int i=0; i<256; i++){
        hashArr[i] = -1;
    }

    while (r < s.size()){
        if (hashArr[s[r]] != -1){
            if (hashArr[s[r]] >= l){
                l = hashArr[s[r]]+1;
            }
            //above if can be simplified as l = max(hashArr[s[r]]+1, l);
        }
        maxlen = max(maxlen, r-l+1);
        hashArr[s[r]] = r;
        r++;
    }

    return maxlen;
}