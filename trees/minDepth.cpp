// https://leetcode.com/problems/minimum-depth-of-binary-tree/

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
    int minDepth(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }
        int lHeight = minDepth(root->left);
        int rHeight = minDepth(root->right);

        if (lHeight == 0 && rHeight == 0)
        {
            return 1;
        }
        else if (lHeight == 0)
        {
            return rHeight + 1;
        }
        else if (rHeight == 0)
        {
            return lHeight + 1;
        }
        else
        {
            return min(lHeight, rHeight) + 1;
        }
    }
};