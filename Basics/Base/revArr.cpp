#include <iostream>
#include <utility>
using namespace std;

void revArr(int arr[],  int start, int end){
    if (start>=end) return;
    swap(arr[start], arr[end]);
    revArr(arr, start+1, end-1);
}

int main(){
    int n; cin>>n;
    int arr[n];
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }
    revArr(arr, 0, n-1);
    cout<<"The reversed array is: \n";
    for (int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}