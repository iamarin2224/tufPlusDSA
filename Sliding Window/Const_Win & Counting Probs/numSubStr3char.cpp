#include <iostream>
using namespace std;

int numberOfSubstrings(string s) {
    int n = s.size();

    int cnt = 0;

    for (int i=0; i<n; i++){
        int hash[3] = {0};
        for (int j=i; j<n; j++){
            hash[s[j]-'a'] = 1;
            if ((hash[0]+hash[1]+hash[2]) == 3){
                //cnt++; 
                cnt += n-j;
                break;
                //this adds all the next possible substrings directly when one is found and moves to the next starting point
            }
        }
    }

    return cnt;
}

int numberOfSubstrings(string s) {
    int n = s.size();   

    int lastSeen[3] = {-1, -1, -1};
    int cnt = 0;

    for (int i=0; i<n; i++){
        lastSeen[s[i]-'a'] = i;
        if (lastSeen[0]!=-1 && lastSeen[1]!=-1 && lastSeen[2]!=-1){
            cnt = cnt + (1 + min({lastSeen[0], lastSeen[1], lastSeen[2]}));
        }
    }

    return cnt;
}