#include <bits/stdc++.h>
using namespace std;

bool isomorphicString(string s, string t) {
    unordered_map<char, char> st_mpp;
    unordered_map<char, char> ts_mpp;

    for (int i=0; i<s.size(); i++){
        if (st_mpp.find(s[i]) == st_mpp.end()){
            st_mpp[s[i]] = t[i];
        }
        else{
            if (st_mpp[s[i]] != t[i]){
                return false;
            }
        }
        if (ts_mpp.find(t[i]) == ts_mpp.end()){
            ts_mpp[t[i]] = s[i];
        }
        else{
            if (ts_mpp[t[i]] != s[i]){
                return false;
            }
        }
    }

    return true;
}

int main(){

    string str1, str2;
    cin>>str1; cin>>str2;

    bool ans = isomorphicString(str1, str2);

    if(ans){
        cout<<"Yes, the strings are isomorphic";
    }
    else{
        cout<<"No, the strings are not isomorphic";
    }

    return 0;
}