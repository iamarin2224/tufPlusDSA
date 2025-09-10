#include <bits/stdc++.h>
using namespace std;

//? Brute
int findPlatform(vector<int>& Arrival, vector<int>& Departure){
    int ans = 1;

    int n = Arrival.size();

    for (int i=0; i<n; i++){
        int count = 0;
        for (int j=0; j<n; j++){
            if (i!=j){
                //Note the condition used only accounts for situations when train arrives early of cur train and leaves after arrival of cur train
                //Though it may seem that we missout on some cases, but as we loop on all elements, the intersection will be counted for the opposite iteration (i,j) -> (j,i)
                if (Arrival[j] <= Arrival[i] && Departure[j] >= Arrival[i]){
                    count++;
                }
            }
        }
        ans = max(ans, count);
    }

    return ans;
}

int findPlatform(vector<int>& Arrival, vector<int>& Departure){
    sort(Arrival.begin(), Arrival.end());
    sort(Departure.begin(), Departure.end());

    int n = Arrival.size();

    int arv = 1, dep = 0;

    int ans = 1, count = 1;

    while (arv<n && dep<n){
        if (Arrival[arv] < Departure[dep]){
            count++;
            arv++;
        }
        else{
            count--;
            dep++;
        }
        ans = max(ans, count);
    }

    return ans;
}