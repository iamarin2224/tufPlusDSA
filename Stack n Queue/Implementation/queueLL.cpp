#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

class LinkedListQueue {
    Node* front;
    Node* back;
    int size;
public:
    LinkedListQueue() {
        front = NULL;
        back = NULL;
        size = 0;
    }
    
    void push(int x) {
        Node* temp = new Node(x);
        if (size == 0){
            front = temp;
            back = temp;
        }
        else{
            back->next = temp;
            back = back->next;
        }
        size++;
    }
    
    int pop() {
        if (size == 0){
            cout<<"UNDERFLOW!";
            return -1;
        }
        Node* temp = front;
        int popped = temp->data;
        if (size == 1){
            front = NULL;
            back = NULL;
        }
        else{
            front = front->next;
        }
        size--;
        delete temp;

        return popped;
    }
    
    int peek() {
        if (size == 0){
            cout<<"EMPTY!";
            return -1;
        }
        return front->data;
    }
    
    bool isEmpty() {
        return (size == 0);
    }
};