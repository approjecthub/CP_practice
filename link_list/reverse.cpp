// https://leetcode.com/problems/reverse-linked-list/
#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

//####################### recursive ###############################
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if (head == NULL)
            return head;

        ListNode *newHead = reverseList(head->next);

        if (newHead == NULL)
            return head;

        head->next->next = head;
        head->next = NULL;

        return newHead;
    }
};

//######################### iterative ###################################
ListNode *reverseList(ListNode *head)
{
    if (head == NULL)
        return head;

    ListNode *prev = NULL;
    ListNode *curr = head;

    while (curr != NULL)
    {
        ListNode *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}