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

string lps(string s) {
    int n = s.size();

    vector<int> kmp = computeKMP(s);

    int j = kmp[n-1];

    string ans = "";

    for (int i=0; i<j; i++){
        ans += s[i];
    }

    return ans;
}