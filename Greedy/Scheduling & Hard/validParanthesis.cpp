#include <iostream>
using namespace std;

//? Recursively viewing all 
/*
bool checkValid(string &s, int count, int ind){
    if (count < 0){
        return false;
    }
    if (ind == s.size()){
        return (count == 0);
    }
    
    bool ans = false;
    
    if (s[ind] == '('){
        ans = checkValid(s, count+1, ind+1);
    }
    
    else if (s[ind] == ')'){
        ans = checkValid(s,count-1, ind+1);
    }
    
    else{
        for (int i=-1; i<=1; i++){
            ans = ans || checkValid(s, count+i, ind+1);
        }
    }
    
    return ans;
}

bool isValid(string s) {
    return checkValid(s, 0, 0);
}
*/

bool isValid(string s) {
    int min = 0, max = 0;
    for (char c: s){
        if (c == '('){
            min++;
            max++;
        }

        else if (c == ')'){
            min--;
            max--;
        }

        else{
            min--;
            max++;
        } 

        if (max < 0) return false; //More opening brackets
        if (min < 0) min = 0; //Keep min to zero
    }

    return (min == 0);
}