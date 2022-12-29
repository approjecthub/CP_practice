// https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1/
// https://www.udemy.com/course/cpp-data-structures-algorithms-levelup-prateek-narang/learn/quiz/5232132#questions

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int key;
    Node *left;
    Node *right;

    Node(int key)
    {
        this->key = key;
        left = right = NULL;
    }
};
void solve(Node *root, vector<int> &ans, int level)
{
    if (!root)
        return;
    if (ans.size() == level)
    {
        ans.push_back(root->key);
    }
    solve(root->left, ans, level + 1);
    solve(root->right, ans, level + 1);
}
vector<int> leftView(Node *root)
{
    // Complete the function
    vector<int> ans;
    solve(root, ans, 0);
    return ans;
}

// https://leetcode.com/problems/binary-tree-right-side-view/

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
class Solution {
public:
    void solve(TreeNode *root, vector<int> &ans, int level)
    {
        if (!root)
            return;
        if (ans.size() == level)
        {
            ans.push_back(root->val);
        }
        solve(root->right, ans, level + 1);
        solve(root->left, ans, level + 1);
        
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        solve(root, ans, 0);
        return ans;
    }
};