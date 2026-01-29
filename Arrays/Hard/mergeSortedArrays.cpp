#include <iostream>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int left = m-1; int right = 0;

    while (left>=0 && right<=n-1){
        if (nums1[left] > nums2[right]){
            swap(nums1[left], nums2[right]);
            right++; left--;
        }
        else{
            break;
        }
    }

    sort(nums1.begin(), nums1.begin()+m);
    sort(nums2.begin(), nums2.begin()+n);
}

int main(){

    int m; cin>>m; 
    int n; cin>>n;

    vector<int> nums1(m);
    vector<int> nums2(n);

    for (int i=0; i<m; i++){
        cin>>nums1[i];
    }

    for (int i=0; i<n; i++){
        cin>>nums2[i];
    }

    merge(nums1, m, nums2, n);

    cout<<"The merged array is: ";
    for (auto it: nums1){
        cout<<it<<" ";
    }    
    cout<<" &  ";
    for (auto it: nums2){
        cout<<it<<" ";
    }

    cout<<endl;

    return 0;
}