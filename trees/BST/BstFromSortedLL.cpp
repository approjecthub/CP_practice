// https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/

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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        if (!head)
        {
            return NULL;
        }
        else
        {

            ListNode *prev = head;
            ListNode *forward = head;
            ListNode *mid = head;
            while (forward != NULL && forward->next != NULL)
            {
                prev = mid;
                mid = mid->next;
                forward = forward->next->next;
            }
            prev->next = NULL;
            // cout<<mid->val<<endl;
            return mid;
        }
    }

    TreeNode *sortedListToBST(ListNode *head)
    {
        if (!head)
            return NULL;
        else if (!head->next)
        {
            TreeNode *root = new TreeNode(head->val);
            return root;
        }
        ListNode *mid = middleNode(head);
        TreeNode *root = new TreeNode(mid->val);
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(mid->next);
        return root;

        return NULL;
    }
};