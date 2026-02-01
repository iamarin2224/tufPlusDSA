#include <iostream>
using namespace std;

// Brute Approach using 2stack uses 2N space complexity (My Approach)
class MinStack {
    stack<int> st1;
    stack<int> st2;

public:
    MinStack() {
        
    }

    void push(int value) {
        if (st1.empty() || st2.top()>=value){
            //Store in both if a possible min value
            st1.push(value);
            st2.push(value);

            return;
        }

        //else only store in the main stack
        st1.push(value);
    }   

    void pop() {
        if (st1.empty()) return;

        if (st1.top() == st2.top()){
            //pop from both if it is a min element
            st1.pop();
            st2.pop();

            return;
        }

        //pop from only one
        st1.pop();
    }

    int top() {
        if (st1.empty()) return -1;

        return st1.top();   //main stack
    }

    int getMin() {
        if (st1.empty()) return -1;

        return st2.top();   //stores minimum
    }
};

// Optimal Approach of storing modified value
class MinStack {
    stack<int> st;
    int minEle;

public:
    MinStack() {
        
    }

    void push(int value) {
        //store and update min if empty
        if (st.empty()){
            st.push(value);
            minEle = value;

            return;
        }

        //if min value, update the min and store a modified value (which helps us to get back to prev min upon pop)
        if (value < minEle){
            st.push(2*value - minEle);
            minEle = value;
        }

        else {
            st.push(value);
        }
    }   

    void pop() {
        if (st.empty()) return;
        
        //pop operation
        int x = st.top();
        st.pop();

        //update min to previous, indicated if the popped is less then min
        if (x < minEle){
            minEle = 2*minEle - x;
        }
    }

    int top() {
        if (st.empty()) return -1;
        
        //if top is less, means modified value is pushed, thus minEle stores the original
        if (st.top() < minEle){
            return minEle;
        }

        return st.top();
    }

    int getMin() {
        if (st.empty()) return -1;

        return minEle;
    }
};