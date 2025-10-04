#include <bits/stdc++.h>
using namespace std;

class QueueStack {
    queue<int> q;
public:
    void push(int x) {
        q.push(x);
        int s = q.size();

        for (int i=1; i<s; i++){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int data = q.front();
        q.pop();

        return data;
    }
    
    int top() {
        return q.front();
    }
    
    bool isEmpty() {
        return q.empty();
    }
};