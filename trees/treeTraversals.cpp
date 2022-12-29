// https://leetcode.com/problems/binary-tree-inorder-traversal/submissions/

#include <bits/stdc++.h>
using namespace std;

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

vector<int> inorderTraversal(TreeNode *root)
{
    stack<TreeNode *> stk;
    vector<int> ans;
    while (root)
    {
        stk.push(root);
        root = root->left;

        while (!root && stk.size() > 0)
        {
            TreeNode *node = stk.top();
            ans.push_back(node->val);
            stk.pop();
            root = node->right;
        }
    }
    return ans;
}

// https://leetcode.com/problems/binary-tree-postorder-traversal/submissions/
vector<int> postorderTraversal(TreeNode *root)
{
    stack<TreeNode *> s1, s2;
    vector<int> ans;
    if (!root)
        return {};
    s1.push(root);
    while (s1.size() > 0)
    {
        TreeNode *node = s1.top();
        s1.pop();
        s2.push(node);
        if (node->left)
            s1.push(node->left);
        if (node->right)
            s1.push(node->right);
    }

    while (s2.size() > 0)
    {
        TreeNode *node = s2.top();
        s2.pop();
        ans.push_back(node->val);
    }
    return ans;
}

// https://leetcode.com/problems/binary-tree-preorder-traversal/submissions/
vector<int> preorderTraversal(TreeNode *root)
{
    stack<TreeNode *> stk;
    if (!root)
        return {};
    vector<int> ans;
    stk.push(root);
    ans.push_back(root->val);

    while (stk.size() > 0)
    {
        root = root->left;
        if (root)
        {
            ans.push_back(root->val);
            stk.push(root);
        }
        while (!root && stk.size() > 0)
        {
            TreeNode *node = stk.top();
            stk.pop();
            root = node->right;
            if (root)
            {
                ans.push_back(root->val);
                stk.push(root);
            }
        }
    }
    return ans;
}

// https://leetcode.com/problems/n-ary-tree-postorder-traversal/
void solve(Node *root, vector<int> &ans)
{
    if (!root)
        return;
    else
    {
        for (int i = 0; i < root->children.size(); i++)
        {
            solve(root->children[i], ans);
        }
        ans.push_back(root->val);
    }
}
vector<int> postorder(Node *root)
{
    vector<int> ans;
    solve(root, ans);
    return ans;
}