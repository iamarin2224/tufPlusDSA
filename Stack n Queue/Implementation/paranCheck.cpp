#include <bits/stdc++.h>
using namespace std;

bool isOpening(char c){
    return (c =='(' || c=='{' || c=='[');
}

bool isRequiredOpening(char close, char open){
    return ((close==')' && open=='(') || (close=='}' && open=='{') || (close==']' && open=='['));
}

bool isValid(string str) {
    stack<char> st;
    for (int i=0; i<str.size(); i++){
        if (isOpening(str[i])){
            st.push(str[i]);
        }
        else{
            if (st.empty()) return false;

            char popped = st.top();
            st.pop();

            if (!isRequiredOpening(str[i], popped)){
                return false;
            }
        }
    }

    if (!st.empty()) return false;

    return true;
}