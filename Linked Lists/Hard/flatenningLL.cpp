#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode *child;
    ListNode()
    {
        val = 0;
        next = NULL;
        child = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
        child = NULL;
    }
    ListNode(int data1, ListNode *next1, ListNode* next2)
    {
        val = data1;
        next = next1;
        child = next2;
    }
};

//? Creating a flatten LL, then sorting it 
/*
ListNode* getMiddle(ListNode* head) {
    ListNode* fastp = head->child;
    ListNode* slowp = head;

    while(fastp != nullptr && fastp->child != nullptr){
        fastp = fastp->child->child;
        slowp = slowp->child;
    }

    return slowp;
}

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* dummy = new ListNode(-1);
    
    ListNode* current = dummy;
    ListNode* mover1 = list1;
    ListNode* mover2 = list2;

    while(mover1 != nullptr && mover2 != nullptr){
        if (mover1->val <= mover2->val){
            current->child = mover1;
            mover1 = mover1->child;
            current = current->child;
        }
        else{
            current->child = mover2;
            mover2 = mover2->child;
            current = current->child;
        }
    }

    while(mover1 != nullptr){
        current->child = mover1;
        mover1 = mover1->child;
        current = current->child;
    }

    while(mover2 != nullptr){
        current->child = mover2;
        mover2 = mover2->child;
        current = current->child;
    }

    return dummy->child;

}

ListNode* mergeSortLL(ListNode* head){
    if (head == nullptr || head->child == nullptr){
        return head;
    }

    ListNode* midNode = getMiddle(head);

    ListNode* leftHead = head;
    ListNode* rightHead = midNode->child;

    midNode->child = nullptr;

    leftHead = mergeSortLL(leftHead);
    rightHead = mergeSortLL(rightHead);

    return mergeTwoLists(leftHead, rightHead);
}

ListNode* flattenLinkedList(ListNode* &head) {
    ListNode* current = head;

    while (current != nullptr){
        ListNode* curChild = current->child;

        if (!curChild){
            current->child = current->next;
            current->next = nullptr;
            current = current->child;
            continue;
        }

        while (curChild->child != nullptr){
            curChild = curChild->child;
        }

        curChild->child = current->next;
        current->next = nullptr;
        current = curChild->child;
    }

    head = mergeSortLL(head);

    return head;
}
*/

//? Utilising the fact that each child list is sorted

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* dummy = new ListNode(-1);

    if (list1) list1->next = nullptr;
    if (list2) list2->next = nullptr;
    
    ListNode* current = dummy;
    ListNode* mover1 = list1;
    ListNode* mover2 = list2;

    while(mover1 != nullptr && mover2 != nullptr){
        if (mover1->val <= mover2->val){
            current->child = mover1;
            mover1 = mover1->child;
            current = current->child;
        }
        else{
            current->child = mover2;
            mover2 = mover2->child;
            current = current->child;
        }
    }

    if(mover1 != nullptr){
        current->child = mover1;
    }
    else{
        current->child = mover2;
    }

    return dummy->child;

}

ListNode* flattenLinkedList(ListNode* &head) {
    if (head == nullptr || head->next == nullptr){
        return head;
    }
    ListNode* mergedHead = flattenLinkedList(head->next);
    return mergeTwoLists(head, mergedHead);
}