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

//! Problem with using first pointers as pointers in the existing LL :
/*
?When we use this inside our loop:
    if (mover->val == 0){
        zeroPtr->next = mover;
        zeroPtr = zeroPtr->next;
    }
    else if (mover->val == 1){
        onePtr->next = mover;
        onePtr = onePtr->next;
    }
    else{
        twoPtr->next = mover;
        twoPtr = twoPtr->next;
    }
    
    mover = mover->next;
?the problem is that we assign the the same node to the mover, and mover remains in the first occurance of the value infinitely, solution: is to make a seperate LL using new dummy heads
*/
/*
ListNode *sortList(ListNode *head) {
    if (head == nullptr || head->next == nullptr){
        return head;
    }
    
    ListNode* zeroPtr = head;
    ListNode* onePtr = head;
    ListNode* twoPtr = head;
    
    ListNode* firstZeroPtr = head;
    ListNode* firstOnePtr = head;
    ListNode* firstTwoPtr = head;
    
    while (zeroPtr != nullptr){
        if (zeroPtr->val == 0){
            firstZeroPtr = zeroPtr;
            break;
        }
        zeroPtr = zeroPtr->next;
    }
    
    while (onePtr != nullptr){
        if (onePtr->val == 1){
            firstOnePtr = onePtr;
            break;
        }
        onePtr = onePtr->next;
    }
    
    while (twoPtr != nullptr){
        if (twoPtr->val == 2){
            firstTwoPtr = twoPtr;
            break;
        }
        twoPtr = twoPtr->next;
    }
    
    ListNode* mover = zeroPtr;
    while (mover != nullptr){
        if (mover->val == 0){
            zeroPtr->next = mover;
            zeroPtr = zeroPtr->next;
        }
        else if (mover->val == 1){
            onePtr->next = mover;
            onePtr = onePtr->next;
        }
        else{
            twoPtr->next = mover;
            twoPtr = twoPtr->next;
        }
        
        mover = mover->next;
        
    }
    
    zeroPtr->next = (firstOnePtr) ? firstOnePtr : firstTwoPtr;
    onePtr->next = firstTwoPtr;
    twoPtr->next = nullptr;
    
    return firstZeroPtr;
}
*/

ListNode *sortList(ListNode *head) {
    if (head == nullptr || head->next == nullptr){
        return head;
    }
    
    ListNode* firstZeroPtr = new ListNode(-1);
    ListNode* firstOnePtr = new ListNode(-1);
    ListNode* firstTwoPtr = new ListNode(-1);
    
    ListNode* zeroPtr = firstZeroPtr;
    ListNode* onePtr = firstOnePtr;
    ListNode* twoPtr = firstTwoPtr;
    
    ListNode* mover = head;

    while (mover != nullptr){
        if (mover->val == 0){
            zeroPtr->next = mover;
            zeroPtr = zeroPtr->next;
        }
        else if (mover->val == 1){
            onePtr->next = mover;
            onePtr = onePtr->next;
        }
        else{
            twoPtr->next = mover;
            twoPtr = twoPtr->next;
        }
        
        mover = mover->next;
        
    }
    
    zeroPtr->next = (firstOnePtr->next) ? firstOnePtr->next : firstTwoPtr->next;
    onePtr->next = firstTwoPtr->next;
    twoPtr->next = nullptr;
    
    return firstZeroPtr->next;
}