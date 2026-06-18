#include <iostream>
using namespace std;

//? Brute
vector<int> computeKMP(string& s){
    int n = s.size();

    vector<int> LPS(n, 0);

    for (int i=1; i<n; i++){
        for (int len=1; len<i; len++){
            if (s.substr(0, len) == s.substr(i-len+1)) LPS[i] = len;
        }
    }

    return LPS;
}

vector<int> search(string pat, string txt) {
    string s = pat + '$' + txt;

    vector<int> lps = computeKMP(s);

    int n = txt.size(), m = pat.size();

    vector<int> ans;

    for (int i=m+1; i<s.size(); i++){
        if (lps[i] == m) ans.push_back(i - 2*m); //as now i is the last index of the matched
    }

    return ans;
}

//? Optimal
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

vector<int> search(string pat, string txt) {
    string s = pat + '$' + txt;

    vector<int> lps = computeKMP(s);

    int n = txt.size(), m = pat.size();

    vector<int> ans;

    for (int i=m+1; i<s.size(); i++){
        if (lps[i] == m) ans.push_back(i - 2*m); //as now i is the last index of the matched
    }

    return ans;
}