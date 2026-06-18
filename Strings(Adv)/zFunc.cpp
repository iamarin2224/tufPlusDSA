#include <iostream>
using namespace std;

//? Brute
vector<int> computeZ(string& s){
    vector<int> z(s.size(), 0);

    for (int i=1; i<s.size(); i++){
        while (i+z[i]<s.size() && s[i+z[i]] == s[z[i]]) z[i]++;
    }

    return z;
}

vector<int> search(string text, string pattern) {
    string combined = pattern + '$' + text;

    int n = text.size(), m = pattern.size();

    vector<int> z = computeZ(combined);

    vector<int> ans;

    for (int i=m+1; i<combined.size(); i++){
        if (z[i] == m) ans.push_back(i-(m+1));
    }

    return ans;
}

//? Optimal
vector<int> computeZOpt(string& s){
    int n = s.size();

    vector<int> z(n, 0);

    int left = 0, right = 0;

    for (int i=1; i<n; i++){
        //normal loop if outside window
        if (i > right){
            while (i+z[i]<n && s[i+z[i]] == s[z[i]]) z[i]++;
        }

        //if inside window
        else{   
            //copy from the first, only if z value is in bounds
            if(i+z[i-left] <= right) z[i] = z[i-left];

            //else we have to compare again
            else{
                //take answer till boundary
                z[i] = right-i+1;
                
                //brute force search to find if z value is more
                while (i+z[i]<n && s[i+z[i]] == s[z[i]]) z[i]++;
            }
        }

        //update the window only if extends beyond current boundary
        if (i+z[i]-1 > right) {
            left = i;
            right = i+z[i]-1;
        }
    }

    return z;
}

vector<int> search(string text, string pattern) {
    string combined = pattern + '$' + text;

    int n = text.size(), m = pattern.size();

    vector<int> z = computeZOpt(combined);

    vector<int> ans;

    for (int i=m+1; i<combined.size(); i++){
        if (z[i] == m) ans.push_back(i-(m+1));
    }

    return ans;
}