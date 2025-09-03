#include <bits/stdc++.h>
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

ListNode* insertBeforeHead(ListNode* head, int X) {
    if (head->next == nullptr){
        head->prev = new ListNode(X, head, nullptr);

        head = head->prev;

        return head;
    }

    ListNode* current = head;

    while (current->next != nullptr){
        current = current->next;
    }

    current->prev->next = new ListNode(X, current, current->prev);

    current->prev = current->prev->next;

    return head;
}