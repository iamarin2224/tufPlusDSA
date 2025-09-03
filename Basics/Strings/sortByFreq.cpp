#include <bits/stdc++.h>
using namespace std;

//? Valid approach
// vector<char> frequencySort(string& s){
// 	map<char, int> freqMap;
// 	map<int , vector<char>, greater<int>> mpp;

//     for (int i=0; i<s.size(); i++){
//         freqMap[s[i]]++;
//     }

//     for (auto it: freqMap){
//         mpp[it.second].push_back(it.first);
//     }

//     vector<char> ans;

//     for (auto it: mpp){
//         ans.insert(ans.end(), it.second.begin(), it.second.end());
//     }

//     return ans;

// }

//? Use of custom comparator

//Custom comparator, which is supposed to return true if the first parameter is to be sorted first (which will come first)
bool comparator(pair<int, char> p1, pair<int ,char> p2){
    if (p1.first > p2.first) return true;
    if (p1.first < p2.first) return false;
    return p1.second < p2.second;
}

vector<char> frequencySort(string& s){
	pair<int ,char> freq[26];   //Array to store frequency against each char

    //Initialising the array
    for (int i=0; i<s.size(); i++){
        freq[i] = {0, i-'a'};
    }

    for (char ch : s){
        freq[ch-'a'].first++;
    }

    sort(freq, freq+26, comparator);

    vector<char> ans;

    for (int i=0; i<26; i++){
        if (freq[i].first>0) ans.push_back(freq[i].second);
    }

    return ans;
}



int main(){

    string str;
    cin>>str;

    vector<char> ans = frequencySort(str);

    cout<<"The characters sorted by their frequency is: "<<endl;
    for (auto it: ans){
        cout<<it<<" ";
    }

    return 0;
}