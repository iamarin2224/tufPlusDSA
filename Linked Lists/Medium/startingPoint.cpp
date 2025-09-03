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

//? Brute Force -> Hashing
/*
ListNode *findStartingPoint(ListNode *head) {
    unordered_set<ListNode*> hashSet;
    
    ListNode* current = head;
    
    while(current != nullptr){
        if (hashSet.find(current) != hashSet.end()){
            return current;
        }
        hashSet.insert(current);
        current = current->next;
    }
    
    return nullptr;
}
*/

ListNode *findStartingPoint(ListNode *head) {
    ListNode* fastp = head;
    ListNode* slowp = head;

    while(fastp != nullptr && fastp->next != nullptr){
        fastp = fastp->next->next;
        slowp = slowp->next;

        if (fastp == slowp){
            slowp = head;

            while (slowp != fastp){
                slowp = slowp->next;
                fastp = fastp->next;
            }

            return slowp;
        }
    }

    return nullptr;
}