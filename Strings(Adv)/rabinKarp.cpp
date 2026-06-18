#include <iostream>
using namespace std;

vector<int> search(string pat, string txt) {
    int n = pat.length();
    int m = txt.length();

    int p = 7, mod = 101;

    int hashTxt = 0, hashPat = 0;

    int pLeft = 1, pRight = 1;

    for (int i = 0; i < n; i++) {
        hashPat = (hashPat + (((pat[i] - 'a' + 1) * pRight) % mod)) % mod;
        hashTxt = (hashTxt + (((txt[i] - 'a' + 1) * pRight) % mod)) % mod;

        pRight = (pRight * p) % mod;
    }

    vector<int> ans;

    for (int i = 0; i <= m - n; i++) {
        if (hashTxt == hashPat) {
            if (txt.substr(i, n) == pat) ans.push_back(i);
        }

        if (i == m - n) break;

        hashTxt = ((hashTxt - ((txt[i] - 'a' + 1) * pLeft) % mod) + mod) % mod;
        hashTxt = (hashTxt + ((txt[i + n] - 'a' + 1) * pRight) % mod) % mod;

        hashPat = (hashPat * p) % mod;

        pLeft = (pLeft * p) % mod;
        pRight = (pRight * p) % mod;
    }

    return ans;
}