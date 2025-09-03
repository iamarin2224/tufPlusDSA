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

ListNode * deleteAllOccurrences(ListNode* head, int target) {
    if (head == nullptr){
        return head;
    }

    ListNode* current = head;

    while(current != nullptr){
        if (current->val == target){
            ListNode* prevNode = current->prev;
            ListNode* nextNode = current->next;

            if (prevNode) prevNode->next = nextNode;
            else head = nextNode;

            if (nextNode) nextNode->prev = prevNode;

            delete current;
            current = nextNode;
        }
        else{
            current = current->next;
        }
    }

    return head;
}