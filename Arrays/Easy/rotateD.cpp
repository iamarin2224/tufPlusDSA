#include <iostream>
#include <vector>
using namespace std;

//? My solutionn
// void rotate(vector<int>& nums, int k) {
//     int n = nums.size();
//     k = k%n;
//     int temp[n];
//     int newIndex;
//     for (int i=0; i<n; i++){
//         newIndex = i+k;
//         if (newIndex>=n) newIndex = newIndex%n;
//         temp[newIndex] = nums[i];
//     }
//     for (int i=0; i<n; i++){
//         nums[i] = temp[i];
//     }
// }

//? Brute Solution
// void rotate(vector<int>& nums, int k) {
//     int n = nums.size();
//     k = k%n;
//     int temp[k];
    
//     for (int i=n-k; i<=n-1; i++){
//         temp[i-(n-k)] = nums[i];
//     }
//     for (int i=0; i<k; i++){
//         nums[i+k] = nums[i];
//     }
//     for (int i=0; i<k; i++){
//         nums[i] = temp[i];
//     }
// }

//? Optimal (in terms of space)
void reverse(vector<int>& nums, int low, int high){
    while(low<=high){
        swap(nums[low], nums[high]);
        low++; high--;
    }
}

void rotate(vector<int>& nums, int k) {

    int n = nums.size();
    k = k%n;
    
    reverse(nums, 0, n-k-1);
    reverse(nums, n-k, n-1);

    reverse(nums, 0, n-1);
}

int main(){

    int n; cin>>n;
    vector<int> arr(n);
    for (int i=0; i<n; i++){
        cin>>arr[i];
    }
    int k; cin>>k;

    rotate(arr, k);

    cout<<"The rotated array is: ";
    for (int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}