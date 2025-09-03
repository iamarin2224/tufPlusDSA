#include <iostream>
using namespace std;

void insSort(int arr[], int i, int n){
    if (i==n) return;
    int j = i;
    while (j>0 && arr[j]<arr[j-1]){
        swap(arr[j-1], arr[j]);
        j--;
    }
    insSort(arr, i+1, n);
}

int main(){

    int n; cin>>n;
    int arr[n];
    for (int i=0; i<n; i++){
        cin>>arr[i];
    }

    insSort(arr, 0, n);

    cout<<"The sorted array is: "<<endl;
    for (int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}