#include <iostream>
using namespace std;

string countAndSay(int n) {
    if (n == 1) return "1";

    string prev = countAndSay(n-1);

    int cnt = 1, i = 1;

    string ans = "";

    for (; i<prev.size(); i++){
        if (prev[i] == prev[i-1]) 
            cnt++;
        else{
            ans += ('0' + cnt);
            ans += prev[i-1];
            cnt = 1;
        }
    }

    ans += ('0' + cnt);
    ans += prev[i-1];

    return ans;
}