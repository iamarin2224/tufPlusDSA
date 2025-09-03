#include <bits/stdc++.h>
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

//? Brute Force
/*
int getSize(ListNode* head){
    ListNode* current = head;
    int n = 1;
    
    while(current->next != nullptr){
        current = current->next;
        n++;
    }
    
    return n;
}

ListNode* removeNthFromEnd(ListNode* head, int n) {
    int size = getSize(head);
    
    int req = size - n;
    
    if (req == 0){
        ListNode* temp = head;
        head = head->next;
        
        delete temp;
        
        return head;
    }
    
    ListNode* current = head;
    ListNode* prev = nullptr;
    
    for (int i=0; i<req; i++){
        prev = current;
        current = current->next;
    }
    
    prev->next = current->next;
    
    delete current;
    
    return head;
}
*/

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* fastP = head;
    ListNode* slowP = head;

    for (int i=0; i<n; i++){
        fastP = fastP->next;
    }

    if (fastP == nullptr){
        ListNode* temp = head;
        head = head->next;
        
        delete temp;
        
        return head; 
    }

    while (fastP->next != nullptr){
        fastP = fastP->next;
        slowP = slowP->next;
    }

    ListNode* temp = slowP->next;

    slowP->next = slowP->next->next;

    delete temp;

    return head;

}