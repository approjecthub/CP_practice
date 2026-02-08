// https://leetcode.com/problems/serialize-and-deserialize-binary-tree/

#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        if (!root)
            return "";
        string ans = "";
        queue<TreeNode *> que;
        que.push(root);

        while (que.size() > 0)
        {
            TreeNode *node = que.front();
            que.pop();
            if (node)
            {
                ans += to_string(node->val) + ",";
                que.push(node->left);
                que.push(node->right);
            }
            else
            {
                ans += "#,";
            }
        }

        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        stringstream ss(data);
        string token;
        getline(ss, token, ',');
        if (token == "")
            return NULL;
        TreeNode *root = new TreeNode(stoi(token));
        queue<TreeNode *> que;
        que.push(root);

        while (que.size() > 0)
        {
            TreeNode *node = que.front();
            que.pop();

            if (getline(ss, token, ','))
            {
                if (token != "#")
                {
                    node->left = new TreeNode(stoi(token));
                    que.push(node->left);
                }
            }
            if (getline(ss, token, ','))
            {
                if (token != "#")
                {
                    node->right = new TreeNode(stoi(token));
                    que.push(node->right);
                }
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));