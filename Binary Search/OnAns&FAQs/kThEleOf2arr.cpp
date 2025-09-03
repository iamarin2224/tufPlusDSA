#include <bits/stdc++.h>
using namespace std;

int kthElement(vector<int> &a, vector<int>& b, int k) {
    int n1 = a.size(), n2 = b.size();

    if (n1 > n2) return kthElement(b, a, k);

    int low = 0, high = min(n1, k);

    while (low <= high){
        int mid1 = (low + high)/2;
        int mid2 = k - mid1;

        if (mid2 > n2) {
            low = mid1+1;
            continue;
        }

        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;

        if (mid1 > 0) l1 = a[mid1-1];
        if (mid2 > 0) l2 = b[mid2-1];
        if (mid1 < n1) r1 = a[mid1];
        if (mid2 < n2) r2 = b[mid2];

        if (l1 <= r2 && l2 <= r1){
            return max(l1, l2);
        }
        else if (l1 > r2) high = mid1-1;
        else low = mid1+1;
    }

    return -1;
   
}