// https://leetcode.com/problems/populating-next-right-pointers-in-each-node/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

// TC: O(N), SC:O(1)
class Solution
{
public:
    Node *connect(Node *root)
    {
        Node *pre = root;
        while (pre)
        {
            Node *cur = pre;

            while (cur)
            {
                if (cur->left)
                {
                    cur->left->next = cur->right;
                }
                if (cur->right && cur->next)
                {
                    cur->right->next = cur->next->left;
                }
                cur = cur->next;
            }

            pre = pre->left;
        }

        return root;
    }
};

// dfs: pre order

Node *connect(Node *root)
{
    if (!root)
        return NULL;

    if (root->left)
    {
        root->left->next = root->right;
        connect(root->left);
    }
    if (root->right)
    {
        if (root->next)
            root->right->next = root->next->left;
        connect(root->right);
    }

    return root;
}

// using level order traversal, TC: O(N), SC:O(N)

Node *connect(Node *root)
{
    if (!root)
        return NULL;

    queue<pair<Node *, int>> que;
    Node *prev = NULL;
    que.push({root, 0});

    while (que.size() > 0)
    {
        pair<Node *, int> p = que.front();
        que.pop();

        Node *node = p.first;
        int level = p.second;

        if (que.size() > 0 && que.back().second < level + 1)
        {
            prev = NULL;
        }

        if (node->left)
        {
            que.push({node->left, level + 1});
            if (!prev)
            {
                prev = node->left;
            }
            else
            {
                prev->next = node->left;
                prev = prev->next;
            }
        }
        if (node->right)
        {
            que.push({node->right, level + 1});
            if (prev)
            {
                prev->next = node->right;
                prev = prev->next;
            }
        }
    }

    return root;
}