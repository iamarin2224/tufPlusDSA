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

//? Brute Force -> Bubble Sort
//? TC: O(N²)   SC: O(1)
/*
int getSize(ListNode* head){
    ListNode* current = head;
    int n = 0;
    
    while (current != nullptr){
        n++;
        current = current->next;
    }
    
    return n;
}

ListNode* sortList(ListNode* head) {
    int n = getSize(head);
    ListNode* current = head;
    
    int flag = 0;
    
    for (int i=0; i<n-1; i++){
        current = head;
        flag = 0;
        for (int j=0; j<n-i-1; j++){
            if (current->val > current->next->val){
                int temp = current->val;
                current->val = current->next->val;
                current->next->val = temp;
                
                flag = 1;
            }
            current = current->next;
            
            if (!flag) break;
        }
    }
    
    return head;
}
*/

//? Brute Force 2 -> Converting LL into Arr, then MS/QS
//? TC: O(N*logN)   SC: O(N)

//? Optimal -> MS on LL directly
ListNode* getMiddle(ListNode* head) {
    ListNode* fastp = head->next;
    ListNode* slowp = head;

    while(fastp != nullptr && fastp->next != nullptr){
        fastp = fastp->next->next;
        slowp = slowp->next;
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
            current->next = mover1;
            mover1 = mover1->next;
            current = current->next;
        }
        else{
            current->next = mover2;
            mover2 = mover2->next;
            current = current->next;
        }
    }

    while(mover1 != nullptr){
        current->next = mover1;
        mover1 = mover1->next;
        current = current->next;
    }

    while(mover2 != nullptr){
        current->next = mover2;
        mover2 = mover2->next;
        current = current->next;
    }

    return dummy->next;

}

ListNode* mergeSortLL(ListNode* head){
    if (head == nullptr || head->next == nullptr){
        return head;
    }

    ListNode* midNode = getMiddle(head);

    ListNode* leftHead = head;
    ListNode* rightHead = midNode->next;

    midNode->next = nullptr;

    leftHead = mergeSortLL(leftHead);
    rightHead = mergeSortLL(rightHead);

    return mergeTwoLists(leftHead, rightHead);
}

ListNode* sortList(ListNode* head) {
    return mergeSortLL(head);
}