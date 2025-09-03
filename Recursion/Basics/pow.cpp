#include <bits/stdc++.h>
using namespace std;

double powr(double x, int n) {
    if (n == 0) return 1.0;
    if (n == 1) return x;

    if (n%2 == 0){
        return powr(x * x, n/2);
    }
    return (x * powr(x, n-1));  
}

double myPow(double x, int n) {
    if (n < 0){
        return (1.0 / powr(x, -1*n));
    } 

    return powr(x ,n);
}