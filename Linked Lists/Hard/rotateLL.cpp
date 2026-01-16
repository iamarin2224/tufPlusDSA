#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode()
    {
        val = 0;
        next = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
    }
    ListNode(int data1, ListNode *next1)
    {
        val = data1;
        next = next1;
    }
};

//? My approach -> Reversal algorithm for LL (Too complex)
/*
int getSize(ListNode* head){
    ListNode* current = head;
    int n = 0;
    while (current != nullptr){
        n++;
        current = current->next;
    }
    return n;
}

ListNode* getKthNode(ListNode* temp, int k){
    for (int i=1; i<k; i++){
        if (temp == nullptr) return temp;
        temp = temp->next;
    }
    return temp;
}

ListNode* reverseLL(ListNode* head){
    if (head == nullptr || head->next == nullptr){
        return head;
    }

    ListNode* revHead = reverseLL(head->next);
    
    ListNode* nextNode = head->next;
    nextNode->next = head;
    head->next = nullptr;

    return revHead;
}

ListNode* rotateRight(ListNode* head, int k) {
    if (head == nullptr || head->next == nullptr || k == 0){
        return head;
    }
    
    int n = getSize(head);
    k = k%n;
    if (k==0) return head;
    
    head = reverseLL(head);
    ListNode* temp = head;

    ListNode* kThNode = getKthNode(head, k);
    ListNode* nextNode = kThNode->next;
    kThNode->next = nullptr;

    head = reverseLL(head);
    nextNode = reverseLL(nextNode);

    temp->next = nextNode;

    return head;
}
*/

//? Optimal
ListNode* rotateRight(ListNode* head, int k) {
    if (head == nullptr || head->next == nullptr || k == 0){
        return head;
    }

    //Get the size and tail in one go
    ListNode* temp = head;
    int len = 1;
    while(temp->next != nullptr){
        len++;
        temp = temp->next;
    }

    //link the last node to head
    temp->next = head;

    k = k%len;

    //get to the supposed end of the LL
    int newEnd = len - k;
    while (newEnd > 0){
        temp = temp->next;
        newEnd--;
    }

    head = temp->next;
    temp->next = nullptr;

    return head;
}