#include <iostream>
using namespace std;

void swapIfGreater(vector<int>& nums1, vector<int>& nums2, int ind1, int ind2){
    if (nums1[ind1] > nums2[ind2]){
        swap(nums1[ind1], nums2[ind2]);
    }
}

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int len = m + n;

    int gap = (len/2) + (len%2);

    while (gap > 0){
        int left = 0;
        int right = left + gap;

        while (right < len){
            //when left in nums1 and right in nums2
            if (left<m && right>=m){
                swapIfGreater(nums1, nums2, left, right-m);
            }
            //when both in nums2
            else if (left>=m){
                swapIfGreater(nums2, nums2, left-m, right-m);
            }
            //when both in nums1
            else{
                swapIfGreater(nums1, nums1, left, right);
            }
            
            left++, right++;
        }

        if (gap == 1) break; 
        gap = (gap/2) + gap%2;
        //for the first time when gap becomes 1 the loop will run, as modification is done at last so will run for gap = 1 for the first time
    }

    for (int i=m; i<m+n; i++){
        nums1[i] = nums2[i-m];
    }

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