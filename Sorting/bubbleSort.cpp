#include <iostream>
using namespace std;

int main(){

    int n; cin>>n;
    int arr[n];
    for (int i=0; i<n; i++){
        cin>>arr[i];
    }

    int flag;
    for (int i=n-1; i>=1; i--){ //i is the last index
        flag = 0;
        for (int j=0; j<=i-1; j++){
            if (arr[j]>arr[j+1]){
                swap(arr[j], arr[j+1]);
                flag = 1;
            }
        }
        if (!flag){
            break;
        }
    }

    cout<<"The sorted array is: "<<endl;
    for (int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}