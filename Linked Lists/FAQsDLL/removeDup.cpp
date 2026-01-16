#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode *prev;
    ListNode()
    {
        val = 0;
        next = NULL;
        prev = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
        prev = NULL;
    }
    ListNode(int data1, ListNode *next1, ListNode *prev1)
    {
        val = data1;
        next = next1;
        prev = prev1;
    }
};

ListNode * removeDuplicates(ListNode *head) {
    if (head == nullptr || head->next == nullptr){
        return head;
    }

    ListNode* dummy = new ListNode(-1);
    dummy->next = head;
    ListNode* dCurrent = head;

    ListNode* current = head->next;

    while (current != nullptr){
        while (current != nullptr && current->val == dCurrent->val){
            current = current->next;
        } 
        if (!current) break;

        dCurrent->next = current;
        current->prev = dCurrent;
        dCurrent = dCurrent->next;
    }

    dCurrent->next = nullptr;

    return dummy->next;
}