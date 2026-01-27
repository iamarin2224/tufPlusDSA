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

class LinkedListStack {
    Node* head;
    int size;
public:
    LinkedListStack() {
        head = NULL;
        size = 0;
    }
    
    void push(int x) {
        Node* temp = new Node(x);
        temp->next = head;
        head = temp;
        size++;
    }
    
    int pop() {
        if (size == 0){
            cout<<"UNDERFLOW!";
            return -1;
        }
        Node* temp = head;
        int popped = temp->data;

        head = head->next;
        size--;

        delete temp;
        return popped;
    }
    
    int top() {
        if (size == 0){
            cout<<"Empty!";
            return -1;
        }
        return head->data;
    }
    
    bool isEmpty() {
        return (size == 0);
    }
};