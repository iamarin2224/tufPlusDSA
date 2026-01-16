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

/*
int findLengthOfLoop(ListNode *head) {
    ListNode* fastp = head;
    ListNode* slowp = head;
    
    ListNode* startPoint;
    
    while(fastp != nullptr && fastp->next != nullptr){
        fastp = fastp->next->next;
        slowp = slowp->next;
        
        if (fastp == slowp){
            slowp = head;
            
            while (slowp != fastp){
                slowp = slowp->next;
                fastp = fastp->next;
            }
            
            startPoint = slowp;
            
            break;
        }
    }
    
    if (fastp != nullptr && fastp->next != nullptr) return 0;
    
    ListNode* current = startPoint;
    int n = 1;
    
    while (current->next != startPoint){
        n++;
        current = current->next;
    }
    
    return n;
}
*/

//? Similar logic simplified
int length(ListNode* slowP, ListNode* fastP){
    fastP = fastP->next;
    int n = 1;
    
    while (fastP != slowP){
        n++;
        fastP = fastP->next;
    }

    return n;
}

int findLengthOfLoop(ListNode *head) {
    ListNode* fastp = head;
    ListNode* slowp = head;
    
    while(fastp != nullptr && fastp->next != nullptr){
        fastp = fastp->next->next;
        slowp = slowp->next;
        
        if (fastp == slowp){
            return length(slowp, fastp);
        }
    }
    
    return 0;
}