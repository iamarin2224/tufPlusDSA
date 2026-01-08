#include <iostream>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {

    sort(intervals.begin(), intervals.end());

    vector<vector<int>> merged;

    merged.push_back(intervals[0]);

    for (int i=1; i<intervals.size(); i++){

        vector<int>& first = merged.back();
        vector<int> second = intervals[i];

        if (first[1] >= second[0]){
            first[1] = max(first[1], second[1]);
        }
        else{
            merged.push_back(second);
        }

    }

    return merged;
}

int main(){

    int n; cin>>n;
    vector<vector<int>> nums(n, vector<int>(2));
    for (int i=0; i<n; i++){
        cin>>nums[i][0];
        cin>>nums[i][1];
    }

    vector<vector<int>> answer = merge(nums);

    cout<<"The interval is: "<<endl;
    for (auto it: answer){
        cout<<it[0]<<" "<<it[1]<<" "<<endl;
    }    

    return 0;
}