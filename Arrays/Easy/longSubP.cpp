#include <iostream>
#include <vector>
using namespace std;

//? Sliding Window approach
int longestSubarray(vector<int>& arr, int k) {
    int low = 0, high = 0;
    int sum = arr[0], curLen = 0, maxLen = 0;
    while (low<=high){
        if (sum<k) {
            high++;
            if (high>=arr.size()) break;
            sum += arr[high];
        }
        else if (sum>k) {
            sum -= arr[low];
            low++;
        }
        else if (sum==k) {
            curLen = high - low + 1;
            if (curLen > maxLen) maxLen = curLen;
            high++;
            if (high>=arr.size()) break;
            sum += arr[high];
        }
    }
    return maxLen;
}

int main(){

    int n; cin>>n;
    vector<int> arr(n);
    for (int i=0; i<n; i++){
        cin>>arr[i];
    }
    int k; cin>>k;

    int answer = longestSubarray(arr, k);

    cout<<"The answer is: "<<answer<<endl;

    return 0;
}