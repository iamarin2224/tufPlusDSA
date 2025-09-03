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

ListNode* reverseLL(ListNode* head){
    if (head == nullptr || head->next == nullptr){
        return head;
    }

    ListNode* newHead = reverseLL(head->next);

    ListNode* front = head->next;

    front->next = head;
    head->next = nullptr;

    return newHead;
}

ListNode *addOne(ListNode *head) {
    if (head == nullptr){
        head = new ListNode(1);
        return head;
    }

    ListNode* current = head;

    while(current->next != nullptr){
        current = current->next;
    }

    if (current->val != 9){
        current->val += 1;
        return head;
    }

    head = reverseLL(head);
    current = head;

    int sum = 0;
    int carry = 1;

    while(current->next != nullptr && carry){
        sum = current->val + carry;
        carry = sum/10;
        current->val = sum%10;
        current= current->next;
    }

    if (current->next == nullptr && carry){
        if (current->val == 9){
            ListNode* newNode = new ListNode(1);
            current->next = newNode;
            current->val = 0;
        }
        else{
            current->val += 1;
        }
    }

    head = reverseLL(head);

    return head;
    
}

//? Recursive soln
int addHelper(ListNode* temp){
    if (temp == nullptr) return 1;

    int carry = addHelper(temp->next);

    temp->val += carry;

    if (temp->val < 10) return 0;

    temp->val = 0;
    return 1;
}

ListNode *addOne(ListNode *head) {
    int carry = addHelper(head);

    if (carry == 1){
        ListNode* newNode = new ListNode(1);
        newNode->next = head;
        head = newNode;
    }

    return head;
}

