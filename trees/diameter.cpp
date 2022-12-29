//https://leetcode.com/problems/diameter-of-binary-tree/

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
    int solve(TreeNode *root, int &maxD)
    {
        if (!root)
        {
            return 0;
        }
        else
        {
            int l = solve(root->left, maxD);
            int r = solve(root->right, maxD);

            maxD = max(maxD, 1 + l + r);
            // cout<<(root->val)<<" : "<<l<<" , "<<r<<" , "<<maxD<<endl;
            return 1 + max(l, r);
        }
    }
    int diameterOfBinaryTree(TreeNode *root)
    {
        int maxD = INT_MIN;
        solve(root, maxD);
        return maxD - 1;
    }
};