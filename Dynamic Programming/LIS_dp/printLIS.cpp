#include <iostream>
using namespace std;

//? Memoization
vector<int> lisHelper(vector<int>& nums, int i, int nextInd, vector<vector<vector<int>>> &dp){
    if (i == 0){
        if (nextInd == nums.size() || nums[0] < nums[nextInd]){
            return {nums[0]};
        }
        else{
            return {};
        }
    }

    if (dp[i][nextInd].size() != 0) return dp[i][nextInd];

    vector<int> notTake = lisHelper(nums, i-1, nextInd, dp);

    vector<int> take = {};
    if (nextInd == nums.size() || nums[i] < nums[nextInd]){
        take = lisHelper(nums, i-1, i, dp);
        take.push_back(nums[i]);
    }

    if (take.size() > notTake.size()) return dp[i][nextInd] = take;

    return dp[i][nextInd] = notTake;
}

vector<int> longestIncreasingSubsequence(vector<int>& arr) {
    int n = arr.size();

    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n+1));

    return lisHelper(arr, n-1, n, dp);
}

//?Tabulation
vector<int> longestIncreasingSubsequence(vector<int>& arr) {
    int n = arr.size();

    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n+1));

    dp[0][n] = {arr[0]};
    for (int nI=1; nI<n; nI++){
        if (arr[0] < arr[nI]) dp[0][nI] = {arr[0]};
    }

    for (int i=1; i<n; i++){
        for (int nI=1; nI<=n; nI++){
            vector<int> notTake = dp[i-1][nI];
            vector<int> take = {};
            if (nI == n || arr[i] < arr[nI]){
                take = dp[i-1][i];
                take.push_back(arr[i]);
            }

            dp[i][nI] = take.size() > notTake.size() ? take : notTake;
        }
    }

    return dp[n-1][n];
}

//? Optimised Tabulation
vector<int> longestIncreasingSubsequence(vector<int>& arr) {
    int n = arr.size();

    vector<vector<int>> prev(n+1);

    prev[n] = {arr[0]};
    for (int nI=1; nI<n; nI++){
        if (arr[0] < arr[nI]) prev[nI] = {arr[0]};
    }

    for (int i=1; i<n; i++){
        vector<vector<int>> curr(n+1);

        for (int nI=1; nI<=n; nI++){
            vector<int> notTake = prev[nI];
            vector<int> take = {};
            if (nI == n || arr[i] < arr[nI]){
                take = prev[i];
                take.push_back(arr[i]);
            }

            curr[nI] = take.size() > notTake.size() ? take : notTake;
        }

        prev.swap(curr);
    }

    return prev[n];
}

//? Best Solution (Tabular + Parent Arr)
vector<int> longestIncreasingSubsequence(vector<int>& arr) {
    int n = arr.size();

    vector<int> dp(n+1, 1); //stores maxlen of LIS ending at i
    vector<int> parent(n); //to reconstruct the LIS

    int maxLen = 0;
    int lastInd = 0;

    for (int i=0; i<n; i++){
        parent[i] = i;  //everyone there own parent

        //check for all previous index
        for (int prevInd=0; prevInd<i; prevInd++){

            //if prev index can be included in LIS ending at i
            if (arr[prevInd] < arr[i]){
                //if a longer LIS found
                if (dp[i] < dp[prevInd]+1){
                    dp[i] = dp[prevInd]+1;  //update the length
                    parent[i] = prevInd; //store the parent
                }

                //else if same length LIS found, we go for smaller index
                else if (dp[i] == dp[prevInd]+1 && prevInd < parent[i]){
                    parent[i] = prevInd;
                }
            }
        }

        if (dp[i] > maxLen){
            lastInd = i;
            maxLen = dp[i];
        }
    }

    //Formation of LIS using parent

    int i = lastInd;
    vector<int> ans;

    //add untill we reach an index which is its own parent
    while (parent[i] != i){
        ans.push_back(arr[i]);
        i = parent[i];
    }
    ans.push_back(arr[i]);  //add last element

    reverse(ans.begin(), ans.end());

    return ans;
}