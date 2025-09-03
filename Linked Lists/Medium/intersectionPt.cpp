#include <bits/stdc++.h>
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

//? Brute -> Two loops
/*
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode* moverA = headA;
    ListNode* moverB = headB;
    
    while (moverA != nullptr){;
    moverB = headB;
    while (moverB != nullptr){
        if (moverA == moverB){
            return moverA;
        }
        moverB = moverB->next;
    }
    moverA = moverA->next;
}

return nullptr;
}
*/

//? Hashing
/*
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    unordered_set<ListNode*> hashSet;
    
    ListNode* currentA = headA;
    ListNode* currentB = headB;
    
    while(currentA != nullptr){
        hashSet.insert(currentA);
        currentA = currentA->next;
    }
    
    while(currentB != nullptr){
        if (hashSet.find(currentB) != hashSet.end()){
            return currentB;
        }
        currentB = currentB->next;
    }
    
    return nullptr;
}
*/

//? Better (Two pointer from same node level)
/*
int getSize(ListNode* head){
    ListNode* current = head;
    int size = 0;
    
    while (current != nullptr){
        size++;
        current = current->next;
    }
    
    return size;
}

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    int nA = getSize(headA);
    int nB = getSize(headB);
    
    ListNode* currentA = headA;
    ListNode* currentB = headB;
    
    if (nA > nB){
        for (int i=0; i < (nA-nB); i++){
            currentA = currentA->next;
        }
    }
    else{
        for (int i=0; i < (nB-nA); i++){
            currentB = currentB->next;
        }
    }
    
    while (currentA != nullptr && currentB != nullptr){
        if (currentA == currentB){
            return currentA;
        }
        currentA = currentA->next;
        currentB = currentB->next;
    }
    
    return nullptr;
}
*/

//? Optimal
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode* currentA = headA;
    ListNode* currentB = headB;

    while (currentA != currentB){
        currentA = currentA->next;
        currentB = currentB->next;

        if (currentA == currentB) return currentA;
        //if no common, both pointer points to null

        if (currentA == nullptr) currentA = headB;
        if (currentB == nullptr) currentB = headA;
    }

    return currentA;
}