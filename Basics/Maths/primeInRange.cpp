#include <bits/stdc++.h>
using namespace std;

vector<int> primesInRange(vector<vector<int>>& queries){
    //PreComputation
    int maxN = 100000;
    int prime[maxN+1];

    prime[0] = 0;
    prime[1] = 0;

    for (int i=0; i<=maxN; i++) prime[i] = 1;

    for (int i=2; i*i<=maxN; i++){
        if (prime[i]==1){
            for (int j=i*i; j<=maxN; j+=i){
                prime[j] = 0;
            }
        }
    }
    
    int cnt = 0;

    for (int i=0; i<=maxN; i++){
        cnt+=prime[i];
        prime[i] = cnt;
    }

    vector<int> ans;

    for (vector<int> query : queries){
        int start = query[0], end = query[1];
        int count = prime[end] - prime[start-1];
        ans.push_back(count);
    }

    return ans;
}

int main(){

    int q; cin>>q;
    vector<vector<int>> queries(q, vector<int>(2));
    for (int i=0; i<q; i++){
        cin>>queries[i][0];
        cin>>queries[i][1];
    }

    vector<int> ans = primesInRange(queries);

    for (int it: ans){
        cout<<it<<" ";
    }

    return 0;
}