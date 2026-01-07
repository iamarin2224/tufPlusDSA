#include <iostream>
#include <unordered_set>
using namespace std;

int longestConsecutive(vector<int>& nums){
    int n = nums.size();
    if (n==0) return 0;

    unordered_set<int> st;

    for (int i=0; i<n; i++){
        st.insert(nums[i]);
    }

    int count = 0, longest = 1;
    for (auto it: st){
        if (st.find(it-1) == st.end()){
            count = 1;
            int x = it;
            while (st.find(x+1) != st.end()){
                x = x+1;
                count++;
            }
            longest = max(longest, count);
        }
    }

    return longest;
}

int main(){

    int n; cin>>n;
    vector<int> arr(n);
    for (int i=0; i<n; i++){
        cin>>arr[i];
    }

    int ans = longestConsecutive(arr);

    cout<<"The length of the longest subarray of consecutive elements is: "<<ans<<endl;

    return 0;
}