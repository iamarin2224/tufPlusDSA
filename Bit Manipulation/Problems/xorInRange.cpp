#include <bits/stdc++.h>
using namespace std;

//? Brute
int findRangeXOR(int l,int r){
    int reqXor = 0;
    for (int i=l; i<=r; i++){
        reqXor ^= i;
    }
    return reqXor;
}   

//? Optimal
int findXOR(int n){
    if (n%4 == 1) return 1;
    else if (n%4 == 2) return n+1;
    else if (n%4 == 3) return 0;
    return n;
}

int findRangeXOR(int l,int r){
    return (findXOR(l-1) ^ findXOR(r));
}