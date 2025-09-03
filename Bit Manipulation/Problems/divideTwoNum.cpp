#include <bits/stdc++.h>
using namespace std;

//? Brute
int divide(int dividend, int divisor) {
    if (dividend == divisor) return 1;
    if (divisor == 1) return dividend;
    if (divisor == -1 && dividend == INT_MIN) return INT_MAX; 
    if (divisor == -1) return (-1)*dividend;

    bool isPos = true;

    if ((dividend<=0 && divisor>0) || (dividend>=0 && divisor<0)) isPos = false;

    long long num = (long long)abs((long long)dividend);
    long long den = (long long)abs((long long)divisor);

    long long ans = 0, sum = 0;

    while (sum+den <= num){
        ans++;
        sum += den;
    }

    if (ans > INT_MAX && isPos) return INT_MAX;
    else if (ans > INT_MAX && !isPos) return INT_MIN;

    if (isPos) return ans;
    return (-1)*ans;
}

//? Optimal
int divide(int dividend, int divisor) {
    if (dividend == divisor) return 1;
    if (divisor == 1) return dividend;
    if (divisor == -1 && dividend == INT_MIN) return INT_MAX; 
    if (divisor == -1) return (-1)*dividend;

    bool isPos = true;

    if ((dividend<=0 && divisor>0) || (dividend>=0 && divisor<0)) isPos = false;

    long num = abs((long)dividend);
    long den = abs((long)divisor);

    long ans = 0;
    int count = 0;

    while (num >= den){
        count = 0;
        while (num >= (den<<(count+1))){
            count++;
        }
        ans += 1<<count;
        num -= den<<(count);
    }

    if (ans > INT_MAX && isPos) return INT_MAX;
    else if (ans > INT_MAX && !isPos) return INT_MIN;

    if (isPos) return ans;
    return (-1)*ans;
}