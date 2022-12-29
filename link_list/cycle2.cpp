// https://leetcode.com/problems/linked-list-cycle-ii/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// SC: O(n)
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        if (head == NULL)
        {
            return NULL;
        }
        else
        {
            unordered_set<ListNode *> mp;
            ListNode *mid = head;
            while (mid != NULL)
            {
                auto it = mp.find(mid->next);
                if (it == mp.end())
                {
                    mp.insert(mid);
                }
                else
                {
                    return mid->next;
                }
                mid = mid->next;
            }
            return NULL;
        }
    }
};

// ############################### sol2 #######################################
// SC: O(1)
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
    ListNode *detectCycle(ListNode *head)
    {
        if (head == NULL)
        {
            return NULL;
        }
        else
        {
            ListNode *forward = head;
            ListNode *mid = head;
            bool hasCycle = false;
            while (forward != NULL && forward->next != NULL)
            {
                mid = mid->next;
                forward = forward->next->next;
                if (mid == forward)
                {
                    hasCycle = true;
                    break;
                }
            }

            if (!hasCycle)
                return NULL;

            ListNode *temp = head;
            while (temp != mid)
            {
                temp = temp->next;
                mid = mid->next;
            }

            return mid;
        }
    }
};