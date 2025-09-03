#include <iostream>
#include <vector>
using namespace std;

int singleNumber(vector<int>& nums) {
    int answer = 0;
    for (int i=0; i<nums.size(); i++){
        answer = answer ^ nums[i];  //XOR
    }
    return answer;
}

int main(){

    int n; cin>>n;
    vector<int> arr(n);
    for (int i=0; i<n; i++){
        cin>>arr[i];
    }

    int answer = singleNumber(arr);

    cout<<"The answer is: "<<answer<<endl;

    return 0;
}