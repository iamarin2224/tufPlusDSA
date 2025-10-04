#include <bits/stdc++.h>
using namespace std;

string preToPost(string prefix){
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

            st.push(t1 + t2 + c);
        }
    }

    return st.top();
}

int main() {
    string prefix = "*-A/BC-/AKL";
    cout << "Postfix Expression: " << preToPost(prefix) << endl;
    return 0;
}

