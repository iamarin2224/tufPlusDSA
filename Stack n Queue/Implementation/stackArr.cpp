#include <bits/stdc++.h>
using namespace std;

class ArrayStack {
    int *arr;
    int capacity;
    int topInd;

public:
    ArrayStack(int size = 1000) {
        capacity = size;
        arr = new int[capacity];
        topInd = -1;
    }
    
    void push(int x) {
        if (topInd >= capacity-1){
            cout<<"OVERFLOW!";
            return;
        }
        arr[++topInd] = x;
    }
    
    int pop() {
        if (topInd == -1){
            cout<<"UNERFLOW!";
            return -1;
        }
        return arr[topInd--];
    }
    
    int top() {
        if (topInd == -1){
            cout<<"No Element!";
            return -1;
        }
        return arr[topInd];
    }
    
    bool isEmpty() {
        if (topInd == -1) return true;
        return false;
    }
};