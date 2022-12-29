// https://leetcode.com/problems/linked-list-cycle/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        if (head == NULL)
        {
            return false;
        }
        else
        {
            ListNode *forward = head;
            ListNode *mid = head;
            while (forward != NULL && forward->next != NULL)
            {
                mid = mid->next;
                forward = forward->next->next;
                if (mid == forward)
                    return true;
            }
            return false;
        }
    }
};