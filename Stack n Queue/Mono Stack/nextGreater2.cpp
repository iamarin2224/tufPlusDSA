#include <iostream>
using namespace std;

//? My Solution
vector<int> nextGreaterElements(vector<int> &arr) {
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

    for (int i=n-1; i>=0; i--){
        while (!st.empty() && st.top() <= arr[i]){
            st.pop();
        }
        if (!st.empty() && st.top() > ans[i]){
            ans[i] = st.top();
        }
        st.push(arr[i]);
    }

    return ans;
}

//? TUF Solution
vector<int> nextGreaterElements(vector<int> &arr) {
    int n = arr.size();

    stack<int> st;

    vector<int> ans(n);

    for (int i=2*n-1; i>=0; i--){
        while (!st.empty() && st.top() <= arr[i%n]){
            st.pop();
        }
        if (i<n){
            if (st.empty()){
                ans[i] = -1;
            }
            else{
                ans[i] = st.top();
            }
        }
        st.push(arr[i%n]);
    }

    return ans;
}