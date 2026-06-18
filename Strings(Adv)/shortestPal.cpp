#include <iostream>
using namespace std;

vector<int> computeKMP(string& s){
    int n = s.size();

    vector<int> lps(n, 0);

    int j=0, i=1;

    while (i < n){
        if (s[i] == s[j]){
            lps[i] = j+1;
            j++, i++;
        }
        else{
            while (j>0 && s[j] != s[i]){
                j = lps[j-1];
            }
            if (s[j] == s[i]){
                lps[i] = j+1;
                j++;  
            }
            i++;
        }
    }

    return lps;
}

string shortestPalindrome(string s) {
    string rev = s;
    reverse(rev.begin(), rev.end());

    string combined = s + '$' + rev;

    vector<int> lps = computeKMP(combined);

    int ans = s.size() - lps.back();

    string toAdd = rev.substr(0, ans);

    return toAdd+s;
}