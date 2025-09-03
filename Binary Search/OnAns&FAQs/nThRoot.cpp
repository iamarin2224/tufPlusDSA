#include <bits/stdc++.h>
using namespace std;

//? Accepted approach but, nthpower function can be optimised
/*
long long NthPower(int num, int n, int m){
    long long ans = (long long)1;
    for (int i=1; i<=n; i++){
        ans = ans * (long long)num;
        if (ans > m) return ans;
    }
    return ans;
}

int NthRoot(int N, int M) {
    int low = 1, high = M;
    
    int mid;
    
    while (low<=high){
        mid = low + (high-low)/2;
        
        long long val = NthPower(mid, N, M);
        
        if (val == M) return mid;
        else if (val > M) high = mid-1;
        else low = mid+1;
    }
    
    return -1;
}
*/


//? Solution with optimised way to find nth power 

int helperFn(int mid, int n, int m){
    long long ans = 1, base = mid;

    while(n>0){
        if (n%2 == 1){
            ans = ans * base;
            if (ans > m) return 2;
            n--;
        }
        else{
            n/=2;
            base *= base;
            if (base > m) return 2;
        }
    }

    if (ans == m) return 1;
    return 0;
}

int NthRoot(int N, int M) {
    int low = 1, high = M;
    
    int mid;
    
    while (low<=high){
        mid = low + (high-low)/2;
        
        int midN = helperFn(mid, N, M);
        
        if (midN == 1) return mid;
        else if (midN == 0) low = mid+1;
        else high = mid-1;
    }
    
    return -1;
}
