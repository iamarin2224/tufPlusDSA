#include <iostream>
using namespace std;

class ArrayQueue {
    int *arr;
    int capacity;
    int front;
    int back;

public:
    ArrayQueue(int size = 1000) {
        capacity = size;
        arr = new int[capacity];
        front = -1;
        back = -1;
    }
    
    void push(int x) {
        if (back >= capacity-1){
            cout<<"OVERFLOW!";
            return;
        }
        if (front == -1 && back == -1){
            front = 0;
        }
        arr[++back] = x;
    }
    
    int pop() {
        if (front == -1 || front > back){
            cout<<"UNDERFLOW!";
            return -1;
        }
        return arr[front++];
    }
    
    int peek() {
        if (front == -1 || front > back){
            cout<<"Empty!";
            return -1;
        }
        return arr[front];
    }
    
    bool isEmpty() {
        if (front == -1 || front > back){
            return true;
        }
        return false;
    }
};

//? Circular queue implementation
class ArrayQueue {
    int *arr;
    int maxSize, curSize;
    int front, back;
    
public:
    ArrayQueue() {
        maxSize = 100;
        arr = new int[maxSize];
        front = -1;
        back = -1;
        curSize = 0;
    }
    
    void push(int x) {
        if (curSize == maxSize){
            cout<<"OVERFLOW!";
            return;
        }
        if (back == -1){
            front = 0;
            back = 0;
        }
        else{
            back = (back+1)%maxSize;
        }
        arr[back] = x;
        curSize++;
    }
    
    int pop() {
        if (curSize == 0){
            cout<<"UNDERFLOW!";
            return -1;
        }
        int popped = arr[front];

        if (curSize == 1){
            front = -1, back = -1;
        }
        else{
            front = (front+1)%maxSize;
        }
        curSize--;
        return popped;
    }
    
    int peek() {
        if (curSize == 0){
            cout<<"Empty!";
            return -1;
        }
        return arr[front];
    }
    
    bool isEmpty() {
        return (curSize == 0);
    }
};