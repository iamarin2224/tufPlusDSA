#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;

    //? Brute Force Approach 

    // int divArr[n];
    // int count=0;

    // for (int i=1; i<=n; i++){
    //     if (n%i==0){
    //         divArr[count++] = i;
    //     }
    // }

    // cout<<"The divisors of "<<n<<" are:"<<endl;
    // for (int i=0; i<count; i++){
    //     cout<<divArr[i]<<" ";
    // }

    //? Optimal Approach

    vector <int> divisors;
    int sqrtN = sqrt(n);

    for (int i=1; i<=sqrtN; i++){
        if (n%i==0){
            divisors.push_back(i);
            if (i != n/i){
                divisors.push_back(n/i);
            }
        }
    }
    sort(divisors.begin(), divisors.end());

    cout<<"The divisors of "<<n<<" are:"<<endl;
    for (int i: divisors){
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}
