// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/
// Topics: Tree, BFS, DFS, Parent Pointer

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    void printAtLevelK(TreeNode *root, vector<int> &ans, int k)
    {
        if (!root)
            return;
        if (k == 0)
        {
            ans.push_back(root->val);
            return;
        }
        printAtLevelK(root->left, ans, k - 1);
        printAtLevelK(root->right, ans, k - 1);
    }
    int solve(TreeNode *root, TreeNode *target, vector<int> &ans, int k)
    {
        if (!root)
        {
            return -1;
        }

        if (root == target)
        {
            printAtLevelK(root, ans, k);
            return 0;
        }

        int lD = solve(root->left, target, ans, k);
        if (lD != -1)
        {
            if (lD + 1 == k)
            {
                ans.push_back(root->val);
                return -1;
            }
            else
            {
                printAtLevelK(root->right, ans, k - (lD + 1) - 1);
                return lD + 1;
            }
        }
        int rD = solve(root->right, target, ans, k);
        if (rD != -1)
        {
            if (rD + 1 == k)
            {
                ans.push_back(root->val);
                return -1;
            }
            else
            {
                printAtLevelK(root->left, ans, k - (rD + 1) - 1);
                return rD + 1;
            }
        }

        return -1;
    }

    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        vector<int> ans;
        solve(root, target, ans, k);
        return ans;
    }
};

// BFS approach
vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
{
    queue<TreeNode *> que1;
    queue<pair<TreeNode *, int>> que2;
    unordered_map<TreeNode *, TreeNode *> umap;
    unordered_map<TreeNode *, bool> isVisited;
    vector<int> ans;

    que1.push(root);
    while (que1.size() > 0)
    {
        TreeNode *node = que1.front();
        isVisited[node] = false;
        que1.pop();

        if (node->left)
        {
            que1.push(node->left);
            umap[node->left] = node;
        }

        if (node->right)
        {
            que1.push(node->right);
            umap[node->right] = node;
        }
    }

    que2.push({target, 0});
    isVisited[target] = true;

    while (que2.size() > 0)
    {
        pair<TreeNode *, int> top = que2.front();
        que2.pop();
        TreeNode *node = top.first;
        int level = top.second;

        if (level == k)
        {
            ans.push_back(node->val);
        }

        if (level < k)
        {
            if (node->left && !isVisited[node->left])
            {
                que2.push({node->left, level + 1});
                isVisited[node->left] = true;
            }

            if (node->right && !isVisited[node->right])
            {
                que2.push({node->right, level + 1});
                isVisited[node->right] = true;
            }

            if (umap.find(node) != umap.end() && !isVisited[umap[node]])
            {
                que2.push({umap[node], level + 1});
                isVisited[umap[node]] = true;
            }
        }
    }

    return ans;
}