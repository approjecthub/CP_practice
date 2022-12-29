// https://leetcode.com/problems/balanced-binary-tree/

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
    int solve(TreeNode *root, int &maxDiff)
    {
        if (!root)
            return 0;
        int lH = solve(root->left, maxDiff);
        int rH = solve(root->right, maxDiff);
        maxDiff = max(maxDiff, abs(lH - rH));
        return 1 + max(lH, rH);
    }
    bool isBalanced(TreeNode *root)
    {
        int maxDiff = 1;
        solve(root, maxDiff);
        return maxDiff <= 1;
    }
};