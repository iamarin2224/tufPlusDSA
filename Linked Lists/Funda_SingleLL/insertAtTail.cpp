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

ListNode* insertAtTail(ListNode* &head, int X) {
    if (head == nullptr){
        ListNode* newNode = new ListNode(X);
        head = newNode;
        return head;
    }

    ListNode* current = head;

    while (current->next != nullptr){
        current = current->next;
    }

    ListNode* newNode = new ListNode(X);
    current->next = newNode;

    return head;
}