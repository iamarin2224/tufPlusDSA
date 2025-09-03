#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s, int start, int end){
    while(start <= end){
        if (s[start] != s[end]) return false;
        start++, end--;
    }
    return true;
}

void func(string s, int ind, vector<string> &current, vector<vector<string>> &ans){
    if (ind == s.size()){
        ans.push_back(current);
        return;
    }

    for (int i = ind; i<s.size(); i++){
        if (isPalindrome(s, ind, i)){
            current.push_back(s.substr(ind, i-ind+1));
            func(s, i+1, current, ans);
            current.pop_back();
        }
    }
}

vector<vector<string>> partition(string s) {
    vector<vector<string>> ans;
    vector<string> current;

    func(s, 0, current, ans);

    return ans;
}