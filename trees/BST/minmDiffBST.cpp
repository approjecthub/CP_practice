// https://leetcode.com/problems/minimum-distance-between-bst-nodes/

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
    void inorder(TreeNode *root, TreeNode *&prev, int &minDiff)
    {
        if (!root)
            return;
        inorder(root->left, prev, minDiff);
        if (prev)
        {
            minDiff = min(minDiff, abs((root->val) - (prev->val)));
        }
        prev = root;
        inorder(root->right, prev, minDiff);
    }
    int minDiffInBST(TreeNode *root)
    {
        TreeNode *prev = NULL;
        int minDiff = INT_MAX;
        inorder(root, prev, minDiff);
        return minDiff;
    }
};