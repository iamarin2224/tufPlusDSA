#include <bits/stdc++.h>
using namespace std;

vector<int> nge(vector<int>& arr) {
    int n = arr.size();

    stack<int> st;

    vector<int> ans(n);

    for (int i=n-1; i>=0; i--){
        while (!st.empty() && st.top() <= arr[i]){
            st.pop();
        }
        if (st.empty()){
            ans[i] = -1;
        }
        else{
            ans[i] = st.top();
        }
        st.push(arr[i]);
    }

    return ans;
}

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> hashmp;

    for (int i=0; i<nums2.size(); i++){
        hashmp[nums2[i]] = i;
    }     
    
    vector<int> nge2 = nge(nums2);

    vector<int> ans;
    for (int i=0; i<nums1.size(); i++){
        ans[i] = nge2[hashmp[nums1[i]]];
    }

    return ans;
}