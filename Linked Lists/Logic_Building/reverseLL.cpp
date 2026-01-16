#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
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

//? My way (correct)
/*
ListNode* reverseList(ListNode* head) {
    if (head == nullptr || head->next == nullptr){
        return head;
    }
    
    ListNode* current = head;
    
    ListNode* revHead = new ListNode(-1);
    
    while (current != nullptr){
        ListNode* temp = current->next;
        
        current->next = revHead->next;
        
        revHead->next = current;
        
        current = temp;
    }
    
    head = revHead->next;
    
    delete revHead;
    
    return head;
}
*/

//? Standard way (reversing the pointing direction)
ListNode* reverseList(ListNode* head) {
    ListNode* current = head;
    ListNode* prev = nullptr;

    while (current != nullptr){
        ListNode* front = current->next; //storing ref of next

        current->next = prev; //changing the direcn of arrow
        prev = current; //incrementing prev

        current = front; //moving to next node
    }

    return prev;
}

//? Recursive way
ListNode* reverseList(ListNode* head) {
    if (head == nullptr || head->next == nullptr){
        return head;
    }

    ListNode* newHead = reverseList(head->next);

    ListNode* front = head->next;

    front->next = head;

    head->next = nullptr;

    return newHead;
}