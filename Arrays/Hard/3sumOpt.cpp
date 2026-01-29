#include <iostream>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    int n = nums.size();

    vector<vector<int>> answer;

    sort(nums.begin(), nums.end());

    for (int i=0; i<n; i++){
        if (i!=0 && nums[i] == nums[i-1]) continue;

        int j = i+1;
        int k = n-1;
        while(j<k && j<n){
            int sum = nums[i] + nums[j] + nums[k];
            if (sum== 0){
                answer.push_back({nums[i], nums[j], nums[k]});
                while (j<k && nums[j] == nums[j+1]) j++;
                j++;
                while (j<k && nums[k] == nums[k-1]) k--;
                k--;
            }
            else if (sum<0){
                while (j<k && nums[j] == nums[j+1]) j++;
                j++;
            }
            else if (sum>0){
                while (j<k && nums[k] == nums[k-1]) k--;
                k--;
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