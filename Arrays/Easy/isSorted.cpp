#include <iostream>
using namespace std;

bool isSorted(int arr[], int n){
    for (int i=0; i<=n-2; i++){
        if (arr[i]>arr[i+1]) return false;
    }
    return true;
}

int main(){

    int n; cin>>n;
    int arr[n];
    for (int i=0; i<n; i++){
        cin>>arr[i];
    }

    if (isSorted(arr, n)){
        cout<<"Yes, the given array is sorted.";
    }
    else{
        cout<<"No, the given array is not sorted.";
    }

    return 0;
}