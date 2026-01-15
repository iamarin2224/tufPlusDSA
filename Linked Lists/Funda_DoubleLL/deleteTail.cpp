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

ListNode* deleteTail(ListNode* head) {
    if (head->next == nullptr){
        delete head;

        return nullptr;
    }

    ListNode* current = head;

    while (current->next != nullptr){
        current = current->next;
    }

    current->prev->next = nullptr;

    delete current;

    return head;
}