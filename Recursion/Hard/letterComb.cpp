#include <bits/stdc++.h>
using namespace std;

void func(vector<string> &digitToLetter, string &digits, int digitInd, int letterInd, string &current, vector<string> &ans){

    if (current.size() == digits.size()){
        ans.push_back(current);
        return;
    }

    if (digitInd >= digits.size() || 
    letterInd >= digitToLetter[(int)digits[digitInd] - (int)'0'].size()) return;

    func(digitToLetter, digits, digitInd, letterInd+1, current, ans);

    string s = digitToLetter[(int)digits[digitInd] - (int)'0'];
    current += s[letterInd];
    func(digitToLetter, digits, digitInd+1, 0, current, ans);
    current.pop_back();
}

vector<string> letterCombinations(string digits) {
    vector<string> digitToLetter = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    vector<string> ans;
    string current = "";

    func(digitToLetter, digits, 0, 0, current, ans);

    return ans;
}

//? For loop and recursion approach

void funcForLoop(int ind, string digits, string s, vector<string> &ans, string combos[]) {
    if(ind == digits.size()) {
        ans.push_back(s);
        return;
    }
    
    int digit = digits[ind] - '0';

    // Loop through the corresponding characters
    for(int i = 0; i < combos[digit].size(); i++) {
        // Recursively call function with next index
        // Add current character to the string
        funcForLoop(ind + 1, digits, s + combos[digit][i], ans, combos);
    }

}

vector<string> letterCombinations2(string digits) {
    string combos[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    vector<string> ans; 
    string s = ""; 

    funcForLoop(0, digits, s, ans, combos);

    return ans; 
}