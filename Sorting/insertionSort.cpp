#include <iostream>
using namespace std;

int main(){

    int n; cin>>n;
    int arr[n];
    for (int i=0; i<n; i++){
        cin>>arr[i];
    }

    int j;
    for (int i=0; i<=n-1; i++){
        j = i;
        while (j>0 && arr[j]<arr[j-1]){
            swap(arr[j-1], arr[j]);
            j--;
        }
    }

    cout<<"The sorted array is: "<<endl;
    for (int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}