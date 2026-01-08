#include <iostream>
using namespace std;

vector<int> primeTillN(int n){
    //PreComputation
    int prime[n+1];

    for (int i=2; i<=n; i++) prime[i]=1;

    for (int i=2; i*i<=n; i++){
        if (prime[i]==1){
            for (int j=i*i; j<=n; j+=i){
                prime[j]=0;
            }
        }
    }

    //Finding prime
    vector<int> ans;

    for (int i=2; i<=n; i++){
        if (prime[i]){
            ans.push_back(i);
        }
    }

    return ans;
}

int main(){

    int n;
    cin>>n;

    vector<int> ans = primeTillN(n);

    for (int it: ans){
        cout<<it<<" ";
    }

    return 0;
}