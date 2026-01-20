#include <iostream>
using namespace std;

long long solve(vector<int>& bt) {
    if (bt.size() == 1) return 0L;
    
    sort(bt.begin(), bt.end());

    int totalWait = 0;
    int sum = bt[0];

    for(int i = 1; i<bt.size(); i++){
        totalWait += sum;
        sum += bt[i];
    }

    return (long long)(totalWait/bt.size());
}