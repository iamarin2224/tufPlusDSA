#include <iostream>
using namespace std;

//? My solution
int totalFruits(vector<int>& fruits){
    int n = fruits.size();

    if (n<=2) return n;

    int l=0, r=0;
    int maxLen = 0;
    int b1=-1, b2=-1;

    int hash[n+1];
    for(int i=0; i<=n; i++){
        hash[i] = 0;
    }

    while (r < n){
        if (fruits[r] == b1){
            hash[b1]++;
        }
        else if (fruits[r] == b2){
            hash[b2]++;
        }
        else {
            if (b1 == -1){
                b1 = fruits[r];
                hash[b1]++;
            }
            else if (b2 == -1){
                b2 = fruits[r];
                hash[b2]++;
            }

            else {
                while (hash[b1]!=0 && hash[b2]!=0){
                    hash[fruits[l]]--;
                    l++;
                }
                if (hash[b1] == 0){
                    b1 = fruits[r];
                    hash[b1]++;
                }
                if (hash[b2] == 0){
                    b2 = fruits[r];
                    hash[b2]++;
                }
            }
        }

        r++;
        maxLen = max(maxLen, r-l+1);
    }

    return maxLen;
}

//? Same TC, but better code solution
int totalFruits(vector<int>& fruits){
    int n = fruits.size();

    if (n<=2) return n;

    int l=0, r=0;
    int maxLen = 0;
    unordered_map<int, int> mpp;

    while (r<n){
        mpp[fruits[r]]++;

        if (mpp.size() > 2){
            while (mpp.size() > 2){
                mpp[fruits[l]]--;
                if (mpp[fruits[l]] == 0){
                    mpp.erase(fruits[l]);
                }
                l++;
            }
        }

        if (mpp.size() <= 2){
            maxLen = max(maxLen, r-l+1);
        }

        r++;
    }

    return maxLen;
}

//? Optimal
int totalFruits(vector<int>& fruits){
    int n = fruits.size();

    if (n<=2) return n;

    int l=0, r=0;
    int maxLen = 0;
    unordered_map<int, int> mpp;

    while (r<n){
        mpp[fruits[r]]++;

        if (mpp.size() > 2){
            mpp[fruits[l]]--;           //Just removing the outer while loop here
            if (mpp[fruits[l]] == 0){
                mpp.erase(fruits[l]);
            }
            l++;
        }

        if (mpp.size() <= 2){
            maxLen = max(maxLen, r-l+1);
        }

        r++;
    }

    return maxLen;
}