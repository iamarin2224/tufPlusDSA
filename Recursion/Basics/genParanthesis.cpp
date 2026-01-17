#include <iostream>
using namespace std;

void func(int open, int close, string &s, vector<string> &ans, int n){
    if (open > n) return;
    if (open == close && open + close == 2*n){
        ans.push_back(s);
        return;
    }

    s.push_back('(');
    func(open+1, close, s, ans, n);
    s.pop_back();

    if (open > close){
        s.push_back(')');
        func(open, close+1, s, ans, n);
        s.pop_back();
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> ans;
    string s = "";
    func(0, 0, s, ans, n);
    return ans;
}