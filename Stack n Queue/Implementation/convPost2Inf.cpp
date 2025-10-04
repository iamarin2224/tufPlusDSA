#include <bits/stdc++.h>
using namespace std;

string postToInf(string postfix){
    int n = postfix.size();
    stack<string> st;

    for (int i=0; i<n; i++){
        char c = postfix[i];

        if (isalnum(c)){
            st.push(string(1,c)); //way to conv char to string
        }
        else{
            string t1 = st.top(); st.pop();
            string t2 = st.top(); st.pop();

            string t = "(" + t1 + c + t2 + ")";

            st.push(t);
        }
    }

    return st.top();
}

int main() {
    string postfix = "AB*C+";
    cout << "Infix Expression: " << postToInf(postfix) << endl;
    return 0;
}
