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

ListNode* deleteKthElement(ListNode* head, int k) {
    if (k == 1){
        if (head->next == nullptr){
            delete head;

            return nullptr;
        }
        else{
            head = head->next;
            delete head->prev;

            head->prev = nullptr;
        }
    }

    ListNode* current = head;

    for(int i=2; i<=k; i++){
        current = current->next;
    }

    current->prev->next = current->next;
    if (current->next != nullptr ) current->next->prev = current->prev;

    delete current;

    return head;
}