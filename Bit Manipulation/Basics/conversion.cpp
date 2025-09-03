#include <bits/stdc++.h>
using namespace std;

string decimalToBinary(int n){
    string res = "";
    while (n!=0){
        if (n%2 == 1) res += '1';
        else res += '0';
        n/=2;
    }
    reverse(res.begin(), res.end());

    return res;
}
// TC:log(n)    SC:log(n)   

int binaryToDecimal(string num){
    int len = num.size();
    int power2 = 1;
    int res = 0;
    for (int i=len-1; i>=0; i++){
        if (num[i] == 1){
            res += power2;
        }
        power2 *= 2;
    }
    return res;
}
// TC:n     SC:1

