#include <bits/stdc++.h>
using namespace std;

//? My solution
vector<int> asteroidCollision(vector<int> &asteroids){
    int n = asteroids.size();
    
    vector<int> st;

    for (int i=0; i<n; i++){
        int curEle = asteroids[i];

        while (!st.empty() && st.back()>0 && curEle<0 && abs(st.back())<abs(curEle)){
            st.pop_back();
        }

        if (!st.empty() && st.back()>0 && curEle<0 && abs(st.back())==abs(curEle)){
            st.pop_back();
            continue;
        }

        if (!st.empty() && st.back()>0 && curEle<0 && abs(st.back())>abs(curEle)) continue;

        st.push_back(curEle);
    }

    return st;
}

//? TUF Solution
vector<int> asteroidCollision(vector<int> &asteroids){
    int n = asteroids.size();
    
    vector<int> st;

    for (int i=0; i<n; i++){
        int curEle = asteroids[i];

        if (curEle > 0){
            st.push_back(curEle);
        }
        else{
            while (!st.empty() && st.back()>0 && st.back()<abs(curEle)){
                st.pop_back();
            }

            if (!st.empty() && st.back()==abs(curEle)){
                st.pop_back();
            }
            else if (st.empty() || st.back()<0){
                st.push_back(curEle);
            }
        }
    }

    return st;
}