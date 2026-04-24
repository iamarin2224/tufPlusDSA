#include <iostream>
using namespace std;

int stockBuySell(vector<int> &arr, int n){
    int minStock = arr[0];

    int maxProfit = INT_MIN;

    for (int i=0; i<n; i++){
        maxProfit = max(maxProfit, arr[i]-minStock);
        minStock = min(minStock, arr[i]);
    }

    return maxProfit;
}