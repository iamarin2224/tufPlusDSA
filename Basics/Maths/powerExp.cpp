#include <bits/stdc++.h>
using namespace std;

double powr(int x, int n){
    if (n==0) return 1;
    
    bool neg = (n<0);
    long long power = abs((long long)n);

    double ans = 1.0;
    double base = x;

    while (power>0){
        if (power%2==1){
            power = power-1;
            ans = ans * (long long)base;
        }
        else{
            power = power/2;
            base = base*base;
        }
    }

    if (neg) ans = 1.0/ans;

    return ans;
}

int main(){

    int x; cin>>x;
    int n; cin>>n;

    double ans = powr(x, n);

    cout<<ans;

    return 0;
}