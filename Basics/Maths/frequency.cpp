#include <iostream>
#include <unordered_map>
#include <limits.h>
using namespace std;

int main(){

    int n; cin>>n;
    int arr[n];
    for (int i=0; i<n; i++){
        cin>>arr[i];
    }

    unordered_map <int, int> mpp;
    for (int i=0; i<n; i++){
        mpp[arr[i]]++;
    }

    //? Procedure to print a map
    // for (auto it : mpp){
    //     cout << "The frequency of "<<it.first<<" is: "<<it.second<<endl;
    // }

    int max, max_count=INT_MIN, min, min_count=INT_MAX;
    for (auto it: mpp){
        if (it.second > max_count){
            max = it.first;
            max_count = it.second;
        }
        if (it.second < min_count){
            min = it.first;
            min_count = it.second;
        }
    }

    cout<<max<<" has the highest frequency, whereas "<<min<<" has the lowest frequency";

    return 0;
}
