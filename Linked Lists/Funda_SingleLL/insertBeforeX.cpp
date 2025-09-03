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

ListNode* insertBeforeX(ListNode* &head, int X, int val) {
    if (head->val == X){
        ListNode* newNode = new ListNode(val, head);
        head = newNode;

        return head;
    } 

    ListNode* current = head;

    while(current->next != nullptr){
        if (current->next->val == X){
            ListNode* newNode = new ListNode(val, current->next);
            current->next = newNode;

            return head;
        }
        current = current->next;
    }

    return head;
}