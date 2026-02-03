#include <iostream>
using namespace std;

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

int maximalAreaOfSubMatrixOfAll1(vector<vector<int>> &matrix){
    int n = matrix.size();
    int m = matrix[0].size();
    
    vector<int> heights(m, 0);
    int maxArea = 0;

    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (matrix[i][j] == 0) heights[j]=0;
            else heights[j]++;
        }

        maxArea = max(maxArea, largestRectangleArea(heights));
    }

    return maxArea;
}