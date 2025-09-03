#include <bits/stdc++.h>
using namespace std;

//? My code, slightly redundant
/*
long long floorSqrt(long long n)  {
    if (n==0) return 0;
    
    long long low = 1, high = n;     
    
    long long ans;
    
    while (low <= high){
        ans = low + (high-low)/2;
        
        if (ans * ans == n) return ans;
        else if (ans * ans > n) high = ans-1;
        else low = ans+1;
    }
    
    if (ans * ans > n) return (ans - (long long)1);
    else return ans;
}
*/


//? Optimised as uses high variable which is the max value (at loop break) less than equal to required

long long floorSqrt(long long n)  {
    if (n==0) return 0;

    long long low = 1, high = n;     
    
    long long mid;

    while (low <= high){
        mid = low + (high-low)/2;

        if (mid*mid <= n) low = mid+1;
        else high = mid-1;
    }

    return high;
}
