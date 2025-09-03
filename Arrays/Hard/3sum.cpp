#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    int n = nums.size();
    set<vector<int>> st;

    for (int i=0; i<n; i++){
        unordered_set<int> hashset;

        for (int j=i+1; j<n; j++){
            int third = -(nums[i] + nums[j]);

            if (hashset.find(third) != hashset.end()){
                vector<int> temp = {nums[i], nums[j], third};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }

            hashset.insert(nums[j]);
        }
    }

    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

int main(){

    int n; cin>>n;
    vector<int> nums(n);
    for (int i=0; i<n; i++){
        cin>>nums[i];
    }

    vector<vector<int>> answer = threeSum(nums);

    cout<<"The triplets are: ";
    for (auto triplet: answer){
        for (int it: triplet){
            cout<<it<<" ";
        }
        cout<<endl;
    }

    return 0;
}