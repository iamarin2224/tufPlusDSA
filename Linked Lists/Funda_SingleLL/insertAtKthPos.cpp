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

ListNode* insertAtKthPosition(ListNode* &head, int X, int K) {
    ListNode* newNode = new ListNode(X);

    if (head == nullptr){
        head = newNode;

        return head;
    }

    if (K == 1){
        newNode->next = head;
        head = newNode;

        return head;
    }

    ListNode* current = head;

    for(int i=2; i<=K-1; i++){
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;

    return head;
}