#include <iostream>
using namespace std;

int main(){

    int n; cin>>n;
    int arr[n];
    for (int i=0; i<n; i++){
        cin>>arr[i];
    }

    int mini;
    for (int i=0; i<=n-2; i++){ //we consider i as the starting index
        mini = i;
        for (int j=i+1; j<=n-1; j++){
            if (arr[j]<arr[mini]){
                mini = j;
            }
        }
        swap(arr[mini], arr[i]);
    }

    cout<<"The sorted array is: "<<endl;
    for (int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}