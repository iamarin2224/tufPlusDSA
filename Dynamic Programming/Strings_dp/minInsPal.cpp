#include <iostream>
using namespace std;

int longestPalinSubseq(string s) {
    int n = s.size();

    vector<int> next(n+1, 0);

    for (int i=n; i>=1; i--){
        vector<int> curr(n+1, 0);
        curr[i] = 1;

        for (int j=i+1; j<=n; j++){
            if (s[i-1] == s[j-1]) curr[j] = next[j-1] + 2;
            else curr[j] = max(next[j], curr[j-1]);
        }

        next.swap(curr);
    }

    return next[n];
}

int minInsertion(string s) {
    return s.size()-longestPalinSubseq(s);
}