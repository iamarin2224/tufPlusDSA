#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode *random;
    ListNode()
    {
        val = 0;
        next = NULL;
        random = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
        random = NULL;
    }
    ListNode(int data1, ListNode *next1, ListNode* r)
    {
        val = data1;
        next = next1;
        random = r;
    }
};

//? Hashing to store copy nodes
/*
ListNode* copyRandomList(ListNode* head) {
    unordered_map<ListNode*, ListNode*> mpp;
    
    ListNode* current = head;
    
    while(current != nullptr){
        ListNode* curCopy = new ListNode(current->val);
        mpp[current] = curCopy;
        current = current->next;
    }
    
    current = head;
    
    while (current != nullptr){
        mpp[current]->next = mpp[current->next];
        mpp[current]->random = mpp[current->random];
        current = current->next;
    }
    
    return mpp[head];
}
*/

//? Optimal -> Storing copy nodes between original LL
ListNode* copyRandomList(ListNode* head) {
    ListNode* current = head;
    ListNode* curCopy;

    //Making the copy nodes and storing them in between
    while (current != nullptr){
        curCopy = new ListNode(current->val);
        curCopy->next = current->next;
        current->next = curCopy;

        current = current->next->next;
    }

    current = head;

    //Copying the random pointers
    while (current != nullptr){
        if (current->random){
            current->next->random = current->random->next;
        }
        else{
            current->next->random = nullptr;
        }
        current = current->next->next;
    }

    ListNode* copyHead = head->next;
    curCopy = copyHead;

    current = head;

    //Copying the next pointers
    while (curCopy->next != nullptr){
        current->next = curCopy->next;
        curCopy->next = curCopy->next->next;

        curCopy = curCopy->next;
        current = current->next;
    }

    current->next = nullptr;

    return copyHead;
}