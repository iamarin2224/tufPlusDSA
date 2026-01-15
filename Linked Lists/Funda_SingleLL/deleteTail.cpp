#include <iostream>
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

ListNode* deleteTail(ListNode* &head) {
    ListNode* current = head;

    while (current->next->next != nullptr){
        current = current->next;
    }

    delete current->next;

    current->next = nullptr;

    return head;
}