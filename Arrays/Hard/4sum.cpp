#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int n = nums.size();
    
    vector<vector<int>> answer;

    sort(nums.begin(), nums.end());

    for (int i=0; i<=n-4; i++){

        if ((long long)nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > (long long)target) break;

        if (i!=0 && nums[i] == nums[i-1]) continue;
        long long newTarget = (long long) target - nums[i];

        for (int j=i+1; j<=n-3; j++){
            if (j!=i+1 && nums[j] == nums[j-1]) continue;

            int k = j+1, l = n-1;

            while(k<l){
                long long sum = (long long)nums[j] + nums[k] + nums[l];

                if (sum == newTarget){
                    answer.push_back({nums[i], nums[j], nums[k], nums[l]});
                    while (k<l && nums[k] == nums[k+1]) k++;
                    while (k<l && nums[l] == nums[l-1]) l--;
                    k++;
                    l--;
                }
                else if (sum < newTarget){
                    while (k<l && nums[k] == nums[k+1]) k++;
                    k++;
                }
                else if (sum > newTarget){
                    while (k<l && nums[l] == nums[l-1]) l--;
                    l--;
                }
            }
        }
    }

    return answer;
}

int main(){

    int n; cin>>n;
    vector<int> nums(n);
    for (int i=0; i<n; i++){
        cin>>nums[i];
    }
    int target; cin>>target;

    vector<vector<int>> answer = fourSum(nums, target);

    cout<<"The quadruplets are: "<<endl;
    for (auto triplet: answer){
        for (int it: triplet){
            cout<<it<<" ";
        }
        cout<<endl;
    }

    return 0;
}