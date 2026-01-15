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

ListNode* deleteHead(ListNode* head) {
    if (head->next == nullptr){
        delete head;

        return nullptr;
    }

    ListNode* temp = head;

    head = head->next;
    head->prev = nullptr;

    delete temp;

    return head;
}