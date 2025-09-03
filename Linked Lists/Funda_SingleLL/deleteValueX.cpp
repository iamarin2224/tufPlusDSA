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

ListNode* deleteNodeWithValueX(ListNode* &head, int X) {
    if (head->val == X){
        ListNode* temp = head;
        head = head->next;

        delete temp;

        return head;
    }
    
    ListNode* current = head;
    ListNode* prev = nullptr;

    while(1){
        if (current == nullptr) return head;

        if (current->val == X){
            break;
        }

        prev = current;
        current = current->next;
    }

    prev->next = current->next;

    delete current;

    return head;
}