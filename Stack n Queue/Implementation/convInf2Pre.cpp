#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

int priority(char c){
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return -1;
}

string infToPost(string &str){
    stack<char> st;
    string ans;

    ans = "";

    for (int i=0; i<str.size(); i++){
        if ((str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z') || (str[i]>='0' && str[i]<='9')){
            ans += str[i];
        }

        else if (str[i] == '('){
            st.push(str[i]);
        }

        else if (str[i] == ')'){
            while (st.top() != '('){
                ans += st.top();
                st.pop();
            }
            st.pop();
        }

        else{
            if (str[i] == '^'){
                while (!st.empty() && priority(str[i]) <= priority(st.top())){
                    ans += st.top();
                    st.pop();
                }
            }
            else{
                while (!st.empty() && priority(str[i]) < priority(st.top())){
                    ans += st.top();
                    st.pop();
                }
            }
            st.push(str[i]);
        }
    }

    while (!st.empty()){
        ans += st.top();
        st.pop();
    }

    return ans;
}

string infToPre(string str){
    reverse(str.begin(), str.end());

    for (int i=0; i<str.size(); i++){
        if (str[i] == ')'){
            str[i] = '(';
        }
        else if (str[i] == '('){
            str[i] = ')';
        }
    }

    string prefix = infToPost(str);

    reverse(prefix.begin(), prefix.end());

    return prefix;
}

int main() {
    string exp = "(p+q)*(m-n)";
    cout << "Infix expression: " << exp << endl;
    cout << "Prefix expression: " << infToPre(exp) << endl;
    return 0;
}