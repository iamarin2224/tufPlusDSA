#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode *prev;
    ListNode()
    {
        val = 0;
        next = NULL;
        prev = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
        prev = NULL;
    }
    ListNode(int data1, ListNode *next1, ListNode *prev1)
    {
        val = data1;
        next = next1;
        prev = prev1;
    }
};

ListNode* arrayToLinkedList(vector<int> &nums) {
    if (nums.size()==0) return NULL;

    ListNode* head = new ListNode(nums[0]);

    if (nums.size() == 1) return head;

    ListNode* current = head;

    for (int i=1; i<nums.size(); i++){
        current->next = new ListNode(nums[i], nullptr, current);
        current = current->next;
    }

    return head;
}