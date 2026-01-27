#include <iostream>
using namespace std;

//? Push Op heavier
class StackQueue {
    stack<int> st1;
    stack<int> st2;
public:
    StackQueue() {
    }
    
    void push(int x) {
        while (st1.size()){
            st2.push(st1.top());
            st1.pop();
        }
        st1.push(x);
        while (st2.size()){
            st1.push(st2.top());
            st2.pop();
        }
    }
    
    int pop() {
        int data = st1.top();
        st1.pop();
        return data;
    }
    
    int peek() {
        return st1.top();
    }
    
    bool isEmpty() {
        return st1.empty();
    }
};

//? Pop/Top op heavier
class StackQueue {
    stack<int> st1;
    stack<int> st2;
public:
    StackQueue() {
    }
    
    void push(int x) {
        st1.push(x);
    }
    
    int pop() {
        if (!st2.empty()){
            int data = st2.top();
            st2.pop();
            return data;
        }
        while (st1.size()){
            st2.push(st1.top());
            st1.pop();
        }
        int data = st2.top();
        st2.pop();
        return data;
    }
    
    int peek() {
        if (!st2.empty()){
            return st2.top();
        }
        while (st1.size()){
            st2.push(st1.top());
            st1.pop();
        }
        return st2.top();
    }
    
    bool isEmpty() {
        if (st1.empty() && st2.empty()) return true;
        return false;
    }
};