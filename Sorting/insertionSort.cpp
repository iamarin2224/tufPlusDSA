#include <iostream>
using namespace std;

int main(){

    int n; cin>>n;
    int arr[n];
    for (int i=0; i<n; i++){
        cin>>arr[i];
    }

    int j, temp;
    for (int i=1; i<=n-1; i++){
        temp = arr[i];
        j = i;
        while (j>0 && arr[j-1]>temp){
            arr[j] = arr[j-1];
            j--;
        }
        arr[j] = temp;    
    }

    cout<<"The sorted array is: "<<endl;
    for (int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}