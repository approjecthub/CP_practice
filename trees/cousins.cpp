// https://leetcode.com/problems/cousins-in-binary-tree/

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
    pair<TreeNode *, int> getParent(TreeNode *root, int x, int dep)
    {
        if (!root)
            return {NULL, -1};
        if (root->val == x)
        {
            return {root, dep};
        }
        pair<TreeNode *, int> l = getParent(root->left, x, dep + 1);
        pair<TreeNode *, int> r = getParent(root->right, x, dep + 1);

        if (l.second > -1)
        {
            if (l.first->val == x)
            {
                l.first = root;
            }
            return l;
        }
        else if (r.second > -1)
        {
            if (r.first->val == x)
            {
                r.first = root;
            }
            return r;
        }
        else
        {
            return {NULL, -1};
        }
    }

    bool isCousins(TreeNode *root, int x, int y)
    {
        pair<TreeNode *, int> pX = getParent(root, x, 0);
        pair<TreeNode *, int> pY = getParent(root, y, 0);

        if (pX.second > -1 && pY.second > -1)
        {
            // cout<<pX.first->val<<" , "<< pY.first->val<<endl;
            if (pX.second == pY.second && pX.first->val != pY.first->val)
            {
                return true;
            }
        }
        return false;
    }
};