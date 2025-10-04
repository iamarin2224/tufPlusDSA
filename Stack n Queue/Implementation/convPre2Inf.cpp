#include <bits/stdc++.h>
using namespace std;

string preToInf(string prefix){
    int n = prefix.size();
    stack<string> st;

    for (int i=n-1; i>=0; i--){
        char c = prefix[i];

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
    string prefix = "*-A/BC-/AKL";
    cout << "Infix Expression: " << preToInf(prefix) << endl;
    return 0;
}
