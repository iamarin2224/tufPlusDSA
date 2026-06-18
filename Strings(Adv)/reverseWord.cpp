#include <iostream>
using namespace std;

//? Brute
string reverseWords(string s) {
    int i = 0;

    vector<string> temp;

    string current;
    
    while (i < s.size()){
        while (s[i] != ' ' && i<s.size()){
            current += s[i];
            i++;
        }

        if (current.size() != 0) {
            temp.push_back(current);
            current.clear();
        }

        i++;
    }

    reverse(temp.begin(), temp.end());

    string ans = "";

    for (string word: temp){
        ans += word;
        ans += ' ';
    }

    ans.pop_back();

    return ans;
}

//? Optimal
void reverseStr(string& s, int start, int end){
    while (start < end){
        swap(s[start++], s[end--]);
    }
}

string reverseWords(string s) {
    int n = s.size();

    reverseStr(s, 0, n-1);

    int i=0, j=0, start=0, end=0;

    while (j<n){
        while (j<n && s[j] == ' ') j++;

        if (j==n) break;

        start = i;

        while (j<n && s[j] != ' '){
            s[i++] = s[j++];
        }

        end = i-1;

        reverseStr(s, start, end);

        if (j<n){
            s[i++] = ' ';
        }
    }

    if (i>0 && s[i-1] == ' ') i--;

    return s.substr(0, i);
}