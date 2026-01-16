#include <iostream>
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

bool isPalindrome(ListNode* head) {
    ListNode* fastp = head;
    ListNode* slowp = head;

    while(fastp != nullptr && fastp->next != nullptr){
        fastp = fastp->next->next;
        slowp = slowp->next;
    }

    ListNode* secondHalf;
    if (fastp == nullptr){
        secondHalf = reverseLL(slowp);
    }
    else{
        secondHalf = reverseLL(slowp->next);
    }

    ListNode* firstHalf = head;
    while (secondHalf != nullptr){
        if (firstHalf->val != secondHalf->val){
            return false;
        }
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }    

    return true;
}