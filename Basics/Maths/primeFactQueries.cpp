#include <iostream>
using namespace std;

//! This is the method to find "prime factors" not "prime factorization"
// vector<vector<int>> primeFactors(vector<int>& queries){

//     int n = queries[queries.size()-1];

//     ?PreComputation
//     int prime[n+1] = {1};

//     for (int i=2; i<=n; i++) prime[i]=1;

//     for (int i=2; i*i<=n; i++){
//         if (prime[i]==1){
//             for (int j=i*i; j<=n; j+=i){
//                 prime[j]=0;
//             }
//         }
//     }

//      ?Finding prime
/*
        vector<vector<int>> ans;

        for(int query: queries){
                vector <int> pFactors;
        
                for (int i=2; i*i<=query; i++){
                    if (prime[i]) pFactors.push_back(i);
                    if (n%i != i){
                        if (prime[n/i]) pFactors.push_back(n/i);
                    }
                }
        
                ans.push_back(pFactors);
            }
        
            return ans;
        }
*/
    
//? Brute Force
// vector<int> primeFactorization(int n){
//     vector<int> ans;

//     for (int i=2; i*i<=n; i++){
//         if (n%i==0){
//             while (n%i==0) {
//                 ans.push_back(i);
//                 n = n/i;
//             }
//         }
//     }
//     if (n!=1) ans.push_back(n);

//     return ans;
// }

// vector<vector<int>> primeFactors(vector<int>& queries){
//     vector<vector<int>> result;

//     for (int query : queries){
//         result.push_back(primeFactorization(query));
//     }

//     return result;
// }

//? Optimal Solution

vector<vector<int>> primeFactors(vector<int>& queries){

    // PreComputation
    int maxN = 100000;
    int spf[maxN+1];

    for (int i=0; i<=maxN; i++) spf[i]=i;

    for (int i=2; i*i<=maxN; i++){
        if (spf[i] == i){
            for (int j=i*i; j<=maxN; j+=i){
                if (spf[j] == j){
                    spf[j] = i;
                }
            }
        }
    }

    // Prime factorization

    vector<vector<int>> ans;

    for (int query : queries){
        vector<int> pFactor;

        while(query != 1){
            pFactor.push_back(spf[query]);
            query /= spf[query];
        }

        ans.push_back(pFactor);
    }

    return ans;
}

int main(){

    int n;
    cin>>n;

    vector<int> queries(n);

    for (int i=0; i<n; i++){
        cin>>queries[i];
    }

    vector<vector<int>> ans = primeFactors(queries);

    for (auto it: ans){
        for (int factor : it){
            cout<<factor<<" ";
        }
        cout<<endl;
    }

    return 0;
}