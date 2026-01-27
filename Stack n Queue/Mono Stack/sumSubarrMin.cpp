#include <iostream>
using namespace std;

vector<int> findNSE(vector<int> &arr){
    int n = arr.size();

    stack<int> st;

    vector<int> ans(n);

    for (int i=n-1; i>=0; i--){
        while (!st.empty() && arr[st.top()] >= arr[i]){
            st.pop();
        }
        if (st.empty()){
            ans[i] = n;
        }
        else{
            ans[i] = st.top();
        }
        st.push(i);
    }

    return ans;
}

vector<int> findPSEE(vector<int> &arr){
    int n = arr.size();

    stack<int> st;

    vector<int> ans(n);

    for (int i=0; i<=n-1; i++){
        while (!st.empty() && arr[st.top()] > arr[i]){
            st.pop();
        }
        if (st.empty()){
            ans[i] = -1;
        }
        else{
            ans[i] = st.top();
        }
        st.push(i);
    }

    return ans;
}

int sumSubarrayMins(vector<int> &arr) {
    vector<int> nse = findNSE(arr);
    vector<int> psee = findPSEE(arr);

    int n = arr.size();
    int mod = 1e9+7;
    int sum = 0;

    for (int i=0; i<n; i++){
        int left = i - psee[i];
        int right = nse[i] - i;

        long long freq = left*right*1LL;

        int val = (freq*arr[i]*1LL)%mod;

        sum = (sum+val)%mod;
    }   

    return sum;
}