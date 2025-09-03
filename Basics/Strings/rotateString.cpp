#include <bits/stdc++.h>
using namespace std;

//? Brute Force
// bool rotateString(string& s,string& goal){
//     if (s.size() != goal.size()) return false;

//     if (s == goal) return true;

//     int k = 1;
//     while(k<s.size()){
//         s = s.substr(1) + s[0];
//         if (s==goal) return true;
//         k++;
//     }

//     return false;
// }

//? Optimal Solution
bool rotateString(string& s,string& goal){
    if (s.size() != goal.size()) return false;

    return ((s+s).find(goal) != string::npos);
}

int main(){

    string str1, str2;
    cin>>str1; cin>>str2;

    bool ans = rotateString(str1, str2);

    if(ans){
        cout<<"Yes, the strings are rotatable";
    }
    else{
        cout<<"No, the strings are not rotatable";
    }

    return 0;
}