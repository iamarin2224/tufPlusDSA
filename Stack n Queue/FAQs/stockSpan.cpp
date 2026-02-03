#include <iostream>
using namespace std;

vector<int> PGE(vector<int> &arr){
    int n = arr.size();

    vector<int> ans(n);
    stack<int> st;

    for (int i=0; i<n; i++){
        while (!st.empty() && arr[st.top()] <= arr[i]){
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

vector<int> stockSpan(vector<int> arr, int n) {
    vector<int> pge = PGE(arr);

    vector<int> ans(n);

    for (int i=0; i<n; i++){
        ans[i] = i-pge[i];
    }

    return ans;
}