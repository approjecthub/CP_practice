// https://leetcode.com/problems/create-binary-tree-from-descriptions/
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
    TreeNode *createBinaryTree(vector<vector<int>> &descriptions)
    {
        unordered_map<int, pair<TreeNode *, bool>> umap;
        TreeNode *root = NULL;
        int n = descriptions.size();

        for (int i = 0; i < n; i++)
        {
            int parent = descriptions[i][0];
            int child = descriptions[i][1];
            int isLeft = descriptions[i][2];

            // find child
            if (umap.find(child) == umap.end())
            {
                umap[child] = {new TreeNode(child), 0};
            }

            // find parent
            if (umap.find(parent) == umap.end())
            {
                umap[parent] = {new TreeNode(parent), 1};
            }

            if (isLeft)
            {
                umap[parent].first->left = umap[child].first;
            }
            else
            {
                umap[parent].first->right = umap[child].first;
            }
            umap[child].second = 0;
        }

        for (auto it : umap)
        {
            if (it.second.second)
            {
                root = it.second.first;
                break;
            }
        }

        return root;
    }
};