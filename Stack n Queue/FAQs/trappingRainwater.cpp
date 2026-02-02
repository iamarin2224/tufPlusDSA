#include <iostream>
using namespace std;

vector<int> NGE(vector<int>& height){
    int n = height.size();

    vector<int> ans(n);
    int max = -1;

    for (int i=n-1; i>=0; i--){
        ans[i] = max;
        if (height[i] > max){
            max = height[i];
        }
    }

    return ans;
}

vector<int> PGE(vector<int>& height){
    int n = height.size();

    vector<int> ans(n);
    int max = -1;

    for (int i=0; i<n; i++){
        ans[i] = max;
        if (height[i] > max){
            max = height[i];
        }
    }

    return ans;
}

int trap(vector<int> &height){
    int n = height.size();

    vector<int> rightMax = NGE(height);
    // vector<int> leftMax = PGE(height);

    int waterTrapped = 0;
    int leftMax = -1;

    for (int i=0; i<n; i++){
        waterTrapped += max(0, (min(rightMax[i], leftMax) - height[i]));
        if (height[i] > leftMax) leftMax = height[i];
    }

    return waterTrapped;
}

//Optimal, uses constant space
int trap(vector<int> &height){
    int n = height.size();

    int leftMax = 0, rightMax = 0;

    int left = 0, right = n-1;

    int waterTrapped = 0;

    //traverse from both end, taking into account the smaller one
    while (left <= right){
        //left is smaller, does leftMax will contain the max ele till now
        if (height[left] <= height[right]){
            //add if possible, else change max
            if (height[left] < leftMax){
                waterTrapped += leftMax - height[left];
            }
            else{
                leftMax = height[left];
            }
            left++;
        }
        //right is smaller, do similar operations
        else{
            if (height[right] < rightMax){
                waterTrapped += rightMax - height[right];
            }
            else{
                rightMax = height[right];
            }
            right--;
        }
    }

    return waterTrapped;
}
