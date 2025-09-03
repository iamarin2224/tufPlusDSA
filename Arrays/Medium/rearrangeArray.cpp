#include <iostream>
#include <vector>
using namespace std;

vector<int> rearrangeArray(vector<int>& nums) {
    int posP = 0, negP = 1;
    int ptr = 0;

    vector<int> answer(nums.size());

    while (ptr<nums.size()){
        if (nums[ptr]>0){
            answer[posP] = nums[ptr];
            ptr++;
            posP+=2;
        }
        else {
            answer[negP] = nums[ptr];
            ptr++;
            negP+=2;
        }
    }

    return answer;
}

int main(){

    int n; cin>>n;
    vector<int> arr(n);
    for (int i=0; i<n; i++){
        cin>>arr[i];
    }

    vector<int> ans = rearrangeArray(arr);

    cout<<"The answer is: "<<endl;
    for (auto it: ans){
        cout<<it<<" ";
    }

    return 0;
}