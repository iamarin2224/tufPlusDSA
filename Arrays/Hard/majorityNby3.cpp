#include <bits/stdc++.h>
using namespace std;

vector<int> majorityElement(vector<int>& nums) {
    int n = nums.size();

    vector<int> answer;
    unordered_map<int, int> mpp;

    //? Two loops
    // for (int i=0; i<n; i++){
    //     mpp[nums[i]]++;
    // }

    // for (auto it: mpp){
    //     if (it.second > n/3){
    //         answer.push_back(it.first);
    //     }
    // }

    //? Single loop approach
    int mini = int(n/3) + 1;

    for (int i=0; i<n; i++){
        mpp[nums[i]]++;

        if (mpp[nums[i]] == mini){      
            //not greater than, as then same value will be pushed multiple times
            answer.push_back(nums[i]);
        }

        if (answer.size() == 2) break;  //only 2 majority element >n/3 possible (just like only 1 majority element >n/2 possible)
    }

    return answer;
        
}

int main(){

    int n; cin>>n;
    vector<int> nums(n);
    for (int i=0; i<n; i++){
        cin>>nums[i];
    }

    vector<int> answer = majorityElement(nums);

    cout<<"The majority elements are: ";
    for (int it: answer){
        cout<<it<<" ";
    }

    return 0;
}