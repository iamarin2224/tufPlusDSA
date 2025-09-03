#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode()
    {
        val = 0;
        next = NULL;
    }
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

ListNode* getKthNode(ListNode* temp, int k){
    for (int i=1; i<k; i++){
        if (temp == nullptr) return temp;
        temp = temp->next;
    }
    return temp;
}

ListNode* reverseLL(ListNode* head){
    if (head == nullptr || head->next == nullptr){
        return head;
    }

    ListNode* revHead = reverseLL(head->next);
    
    ListNode* nextNode = head->next;
    nextNode->next = head;
    head->next = nullptr;

    return revHead;
}

ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* temp = head;
    ListNode* prevNode = nullptr;

    while (temp != nullptr){
        ListNode* kThNode = getKthNode(temp, k);

        if (kThNode == nullptr){
            prevNode->next = temp;
            break;
        }

        ListNode* nextNode = kThNode->next;

        kThNode->next = nullptr;

        reverseLL(temp);

        if (temp == head){
            head = kThNode;
        }
        else{
            prevNode->next = kThNode;
        }

        prevNode = temp;

        temp = nextNode;
    }

    return head;
}