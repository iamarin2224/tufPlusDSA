#include <iostream>
using namespace std;

//? My Approach: O(n²*l²)
int longestStringChain(vector<string>& words) {
    int n = words.size();

    sort(words.begin(), words.end(), [](const string &a, const string &b){
        if (a.size() != b.size()) return a.size() < b.size();

        return a < b;
    });

    vector<int> dp(n+1, 1);

    int maxLen = 0;

    for (int i=0; i<n; i++){
        for (int prevInd=0; prevInd<i; prevInd++){
            if (words[i].size() != words[prevInd].size()+1) continue;

            for (int j=0; j<words[i].length(); j++){
                string newWord = words[i].substr(0, j) + words[i].substr(j+1);

                if (words[prevInd] == newWord){
                    if (dp[i] < dp[prevInd]+1) dp[i] = dp[prevInd]+1;
                    break;
                }
            }
        }

        maxLen = max(maxLen, dp[i]);
    }

    return maxLen;
}

//?TUF Approach: O(n²*l)
bool checkPossible(string &s, string &t) {
    if(s.size() != t.size() + 1) return false;
    
    int i = 0, j = 0;
    
    //traverse until the first string is exhausted
    while(i < s.size()) {
        //move both pointers if characters matches
        if(j < t.size() && s[i] == t[j]) {
            i++, j++;
        }
        else {
            i++;
        }
    }
    
    //return true if both the string gets exhausted
    if(i == s.size() && j == t.size()) return true;
    return false; 
}

int longestStringChain(vector<string>& words) {
    int n = words.size();

    //sort according to length of words
    sort(words.begin(), words.end(), [](const string &a, const string &b){
        return a.size() < b.size();
    });

    vector<int> dp(n+1, 1);

    int maxLen = 0;

    // loop the arr and look for prevInd which can be predecessor
    for (int i=0; i<n; i++){
        for (int prevInd=0; prevInd<i; prevInd++){
            if (checkPossible(words[i], words[prevInd]) && dp[i] < dp[prevInd]+1){
                dp[i] = dp[prevInd]+1;
            }
        }

        maxLen = max(maxLen, dp[i]);
    }

    return maxLen;
}