// https://leetcode.com/problems/middle-of-the-linked-list/
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
class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        if (head == NULL)
        {
            return NULL;
        }
        else
        {
            ListNode *forward = head;
            ListNode *mid = head;
            while (forward != NULL && forward->next != NULL)
            {
                mid = mid->next;
                forward = forward->next->next;
            }
            return mid;
        }
    }
};