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


int getSize(ListNode* head){
    ListNode* current = head;
    int n = 1;

    while(current->next != nullptr){
        n++;
        current = current->next;
    }

    return n;
}

//? My approach using no extra space (a bit complex while resolving carry and involves too many if cases)
/*
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int n1 = getSize(l1), n2 = getSize(l2);

    ListNode* current1 = l1;
    ListNode* current2 = l2;

    if (n1 == n2){
       while(current2->next != nullptr){
            int sum = current1->val + current2->val;
            if (sum <= 9){
                current1->val = sum;
            }
            else{
                current1->val = sum%10;
                current1->next->val += sum/10;
            }
            current1 = current1->next;
            current2 = current2->next;
        }

        int sum = current1->val + current2->val;
        if (sum <= 9){
            current1->val = sum;
        }
        else{
            current1->val = sum%10;
            current1->next = new ListNode(sum/10);
        }

        return l1; 
    }

    if (n2 > n1){
        ListNode* temp = l1;
        l1 = l2;
        l2 = temp;

        current1 = l1;
        current2 = l2;
    }
    
    while(current2 != nullptr){
        int sum = current1->val + current2->val;
        if (sum <= 9){
            current1->val = sum;
        }
        else{
            current1->val = sum%10;
            current1->next->val += sum/10;
        }
        current1 = current1->next;
        current2 = current2->next;
    }

    while (current1->next != nullptr){
        if (current1->val > 9){
            int value = current1->val;
            current1->val = value%10;
            current1->next->val += value/10;
        }
        else{
            return l1;
        }
    }

    if (current1->val > 9){
        int value = current1->val;
        current1->val = value%10;
        current1->next = new ListNode(value/10);
    }

    return l1;
    
}
*/

//? ChatGPT optimised code with my logic

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int n1 = getSize(l1), n2 = getSize(l2);

    if (n2 > n1) swap(l1, l2);

    ListNode* current1 = l1;
    ListNode* current2 = l2;
    ListNode* prev = nullptr;
    int carry = 0;

    while (current1 || current2 || carry){
        int sum = carry + (current1 ? current1->val : 0) + (current2 ? current2->val : 0);

        if(current1){
            current1->val = sum%10;
            carry = sum/10;
            prev = current1;
            current1 = current1->next;
        }
        //else l1 is exhausted only carry is left
        else{
            prev->next = new ListNode(sum%10);
            carry = sum/10;
        }

        if (current2) current2 = current2->next;
    }

    return l1;
}

//? TUF Code (using an extra linked list)
/*
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* dummy = new ListNode(0); //starting point of result

    ListNode* temp = dummy; 

    int carry = 0;

    while(l1 || l2 || carry){
        int sum = 0;

        if (l1){
            sum += l1->val;
            l1 = l1->next;
        }

        if (l2){
            sum += l2->val;
            l2 = l2->next;
        }

        sum += carry;

        carry = sum/10;

        temp->next = new ListNode(sum%10);

        temp = temp->next;
    }

    return dummy->next;
}
*/