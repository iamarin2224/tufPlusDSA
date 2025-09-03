#include <bits/stdc++.h>
using namespace std;

vector<int> primeFactors(int n){
    vector<int> ans;

    for (int i=2; i*i<=n; i++){
        if (n%i==0){
            ans.push_back(i);
            while (n%i==0) n = n/i;
        }
    }
    if (n!=1) ans.push_back(n);

    return ans;
}

int main(){

    int n; cin>>n;

    vector<int> ans = primeFactors(n);

    for (int it: ans){
        cout<<it<<" ";
    }

    return 0;
}