#include <iostream>
using namespace std;

//similar can be done using ~struct~ too, there everything is public by default
class Node {
    public:
        int data;
        Node* next;

        Node(int data1, Node* next1){
            data = data1;
            next = next1;
        }

        Node(int data1){
            data = data1;
            next = nullptr;
        }
};

Node* convertArr2LL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;

    if (arr.size() == 1) return head;

    for(int i=1; i<arr.size(); i++){
        mover->next = new Node(arr[i]);
        mover = mover->next;
    }

    return head;
}

void deleteLinkedList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        Node* nextNode = current->next; 
        delete current;                 
        current = nextNode;             
    }
}

int main(){
    vector<int> arr = {2, 4, 3, 6};

    //?Y becomes pointer to a class object
    //This is preferred as it stores in heap memory
    Node* y = new Node(arr[0]);
    cout<< y->data <<endl;

    //Or
    //?Z is the class object in itself
    Node z(arr[1]);
    cout<< z.data <<endl;

    Node* llHead = convertArr2LL(arr);
    cout<< llHead->data <<endl;
    
}