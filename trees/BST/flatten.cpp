// https://practice.geeksforgeeks.org/problems/flatten-binary-tree-to-linked-list/1/#
// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

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
    pair<TreeNode *, TreeNode *> solve(TreeNode *root)
    {
        if (!root)
            return {NULL, NULL};
        pair<TreeNode *, TreeNode *> lp = solve(root->left);
        pair<TreeNode *, TreeNode *> rp = solve(root->right);

        root->left = NULL;
        if (lp.first && lp.second)
        {
            root->right = lp.first;
            lp.second->right = rp.first;
        }
        else
        {
            root->right = rp.first;
        }

        pair<TreeNode *, TreeNode *> ansp;
        ansp.first = root;
        if (rp.second)
        {
            ansp.second = rp.second;
        }
        else if (lp.second)
        {
            ansp.second = lp.second;
        }
        else
        {
            ansp.second = root;
        }
        return ansp;
    }
    void flatten(TreeNode *root)
    {
        solve(root);
    }
};