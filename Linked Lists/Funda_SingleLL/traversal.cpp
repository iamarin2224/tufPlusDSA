#include <iostream>
using namespace std;

//? LL Definition
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

vector<int> LLTraversal(ListNode *head) {
    vector<int> result;

    if (head == nullptr) return result;

    ListNode* current = head;

    while(current != nullptr){
        result.push_back(current->val);
        current = current->next;
    }

    return result;
}