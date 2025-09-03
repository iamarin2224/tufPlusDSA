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

ListNode* deleteMiddle(ListNode* head) {
    ListNode* fastp = head;
    ListNode* slowp = head;
    ListNode* prev = nullptr;

    if (head->next == nullptr){
        delete head;

        return nullptr;
    }

    while(fastp != nullptr && fastp->next != nullptr){
        fastp = fastp->next->next;
        prev = slowp;
        slowp = slowp->next;
    }

    prev->next = slowp->next;

    delete slowp;

    return head;
}