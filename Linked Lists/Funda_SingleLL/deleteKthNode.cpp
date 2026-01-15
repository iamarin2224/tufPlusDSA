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

ListNode* deleteKthNode(ListNode* &head, int k) {
    ListNode* current = head;

    if (k==1) {
        head = head->next;
        delete current;

        return head;
    }

    //going to the (n-1)th node
    for(int i=2; i<k; i++){
        current = current->next;
    }

    ListNode* temp = current->next;
    current->next = current->next->next;

    delete temp;

    return head;
}