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

/*
ListNode* oddEvenList(ListNode* head) {
    if (head == nullptr || head->next == nullptr){
        return head;
    }
    
    ListNode* oddPtr = head;
    ListNode* evenPtr = head->next;
    
    ListNode* dummy = new ListNode(0);
    
    ListNode* temp = dummy;
    
    while(oddPtr != nullptr){
        temp->next = new ListNode(oddPtr->val);
        
        temp = temp->next;
        
        if (oddPtr->next->next == nullptr) oddPtr = oddPtr->next->next;
        else break;
    }
    
    while(evenPtr != nullptr){
        temp->next = new ListNode(evenPtr->val);
        
        temp = temp->next;
        
        if (evenPtr->next != nullptr) evenPtr = evenPtr->next->next;
        else break;
    } 
    
    return dummy->next;
}
*/


//? Optimal: By changing the linkage of even and odd elements then linking last odd with first even
ListNode* oddEvenList(ListNode* head) {
    if (head == nullptr || head->next == nullptr){
        return head;
    }

    ListNode* oddPtr = head;
    ListNode* evenPtr = head->next;
    ListNode* firstEven = head->next;
    
    while(evenPtr && evenPtr->next){
        oddPtr->next = oddPtr->next->next;
        evenPtr->next = evenPtr->next->next;

        oddPtr = oddPtr->next;
        evenPtr = evenPtr->next;
    }

    oddPtr->next = firstEven;

    return head;
}