#include <iostream>
using namespace std;

void func(vector<vector<int>> &ans, vector<int> &current, int number, int sum, int k, int n){
    if (sum == n && k == current.size()){
        ans.push_back(current);
        return;
    }

    if (number > 9 || sum > n || number > n || current.size() > k) return;

    func(ans, current, number+1, sum, k, n);

    current.push_back(number);
    func(ans, current, number+1, sum+number, k, n);
    current.pop_back();
}

vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> ans;
    vector<int> current;

    func(ans, current, 1, 0, k, n);

    return ans;
}