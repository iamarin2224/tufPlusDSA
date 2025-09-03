#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int>& prices) {
    int minPrice = INT_MAX;
    int maxPro = 0;
    
    for (int i=0; i<prices.size(); i++){
        if (prices[i]<minPrice) minPrice = prices[i];
        maxPro = max(prices[i]-minPrice, maxPro);
    }

    return maxPro;
}

int main(){

    int n; cin>>n;
    vector<int> arr(n);
    for (int i=0; i<n; i++){
        cin>>arr[i];
    }

    int ans = maxProfit(arr);

    cout<<"The answer is: "<<ans<<endl;

    return 0;
}