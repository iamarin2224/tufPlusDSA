#include <iostream>
#include <vector>
using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums) {
    int curCount = 0, maxCount = 0;
    for (int i=0; i<nums.size(); i++){
        if (nums[i]==1){
            curCount++;
            if (curCount>maxCount){
                maxCount = curCount;
            }
        }
        else{
            curCount = 0;
        }
    }
    return maxCount;
}

int main(){

    int n; cin>>n;
    vector<int> arr(n);
    for (int i=0; i<n; i++){
        cin>>arr[i];
    }

    int answer = findMaxConsecutiveOnes(arr);

    cout<<"The answer is: "<<answer<<endl;

    return 0;
}