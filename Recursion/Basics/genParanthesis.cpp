#include <bits/stdc++.h>
using namespace std;

void func(int open, int close, string s, vector<string> &ans, int n){
    if (open > n) return;
    if (open == close && open + close == 2*n){
        ans.push_back(s);
        return;
    }

    func(open+1, close, s + "(", ans, n);
    if (open > close){
        func(open, close+1, s + ")", ans, n);
    }
}

vector<string> generateParenthesis(int n) {

    vector<string> ans;
    func(0, 0, "", ans, n);

    return ans;
     
}