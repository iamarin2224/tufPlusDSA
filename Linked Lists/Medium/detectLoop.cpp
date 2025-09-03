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

//? Hashing (Brute)
/*
bool hasCycle(ListNode *head) {
    unordered_set<ListNode*> hashSet;
    
    ListNode* current = head;
    
    while(current != nullptr){
        if (hashSet.find(current) != hashSet.end()){
            return true;
        }
        hashSet.insert(current);
        current = current->next;
    }
    
    return false;
}
*/

//? Optimal -> Tortoise-Hare method
bool hasCycle(ListNode *head) {
    ListNode* fastp = head;
    ListNode* slowp = head;

    while(fastp != nullptr && fastp->next != nullptr){
        fastp = fastp->next->next;
        slowp = slowp->next;

        if (fastp == slowp){
            return true;
        }
    }

    return false;
}