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

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* dummy = new ListNode(-1);
    
    ListNode* current = dummy;
    ListNode* mover1 = list1;
    ListNode* mover2 = list2;

    while(mover1 != nullptr && mover2 != nullptr){
        if (mover1->val <= mover2->val){
            current->next = mover1;
            mover1 = mover1->next;
            current = current->next;
        }
        else{
            current->next = mover2;
            mover2 = mover2->next;
            current = current->next;
        }
    }

    if(mover1 != nullptr){
        current->next = mover1;
    }
    else{
        current->next = mover2;
    }

    return dummy->next;

}