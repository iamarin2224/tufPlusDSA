#include <iostream>
using namespace std;

int lcs(string& str1, string& str2) {
    int m = str1.size(); int n = str2.size();

    vector<int> prev(n+1, 0);

    for (int i=1; i<=m; i++){
        vector<int> curr(n+1, 0);
        curr[0] = 0;

        for (int j=1; j<=n; j++){
            if (str1[i-1] == str2[j-1]) curr[j] = 1 + prev[j-1];

            else curr[j] = max (curr[j-1], prev[j]);
        }

        prev.swap(curr);
    }

    return prev[n];
}

int minOperations(string str1, string str2) {
    int k = lcs(str1, str2);

    return (str1.size()-k)+(str2.size()-k);
}