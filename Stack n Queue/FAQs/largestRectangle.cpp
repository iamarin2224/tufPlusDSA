#include <iostream>
using namespace std;

vector<int> NSE(vector<int> &heights){
    int n = heights.size();

    vector<int> ans(n);
    stack<int> st;

    for (int i=n-1; i>=0; i--){
        while (!st.empty() && heights[st.top()] >= heights[i]){
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

vector<int> PSE(vector<int> &heights){
    int n = heights.size();

    vector<int> ans(n);
    stack<int> st;

    for (int i=0; i<n; i++){
        while (!st.empty() && heights[st.top()] >= heights[i]){
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

int largestRectangleArea(vector<int> &heights) {
    int n = heights.size();

    vector<int> nse = NSE(heights);
    vector<int> pse = PSE(heights);

    int maxArea = INT_MIN;

    for (int i=0; i<n; i++){
        int area = heights[i]*(nse[i]-pse[i]-1);

        maxArea = max(maxArea, area);
    }

    return maxArea;
}

// Optimal Approach while solving 
int largestRectangleArea(vector<int> &heights) {
    int n = heights.size();

    stack<int> st;

    int maxArea = INT_MIN;

    int ind, nse, pse;

    for (int i=0; i<n; i++){
        while (!st.empty() && heights[st.top()] >= heights[i]){
            ind = st.top(); st.pop();
            nse = i, pse = st.empty() ? -1 : st.top();

            maxArea = max(heights[ind]*(nse-pse-1), maxArea);
        }

        st.push(i);
    }

    while (!st.empty()){
        ind = st.top(); st.pop();

        nse = n;
        pse = st.empty() ? -1 : st.top();

        maxArea = max(heights[ind]*(nse-pse-1), maxArea);
    }

    return maxArea;
}