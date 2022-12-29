// https://leetcode.com/problems/binary-tree-level-order-traversal/

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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        if (!root)
            return {};

        queue<pair<int, TreeNode *>> que;
        que.push({0, root});
        vector<vector<int>> ans;
        while (que.size() > 0)
        {
            pair<int, TreeNode *> front = que.front();
            int level = front.first;
            TreeNode *node = front.second;
            if (level == ans.size())
            {
                ans.push_back({});
            }
            ans[level].push_back(node->val);
            que.pop();
            if (node->left)
            {
                que.push({level + 1, node->left});
            }
            if (node->right)
            {
                que.push({level + 1, node->right});
            }
        }

        return ans;
    }
};