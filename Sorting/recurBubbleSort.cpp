#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n){
    if (n==1) return;
    int didSwap = 0;
    for (int j=0; j<=n-2; j++){
        if (arr[j+1]<arr[j]){
            swap(arr[j], arr[j+1]);
            didSwap = 1;
        }
    }
    if(!didSwap) return;
    bubbleSort(arr, n-1);
}

int main(){

    int n; cin>>n;
    int arr[n];
    for (int i=0; i<n; i++){
        cin>>arr[i];
    }

    bubbleSort(arr, n);

    cout<<"The sorted array is: "<<endl;
    for (int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}