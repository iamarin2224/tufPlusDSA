#include <iostream>
using namespace std;

int removeDuplicates(int arr[], int n){
    int left = 0; int right = 1;
    while (right <= n-1){
        if (arr[left]==arr[right]) right++;
        else {
            swap(arr[left+1], arr[right]);
            left++; right++;
        }
    }
    return left+1;
}

int main(){

    int n; cin>>n;
    int arr[n];
    for (int i=0; i<n; i++){
        cin>>arr[i];
    }

    int k = removeDuplicates(arr, n);

    cout<<"The array after removing duplicates is: \n";
    for (int i=0; i<k; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}