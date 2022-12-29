// https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/

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

// TC: O(N), SC: O(1)
Node *connect(Node *root)
{
    if (!root)
        return NULL;

    Node *dummy = new Node(-1);
    Node *p = dummy;
    Node *head = root;

    while (head != NULL)
    {
        Node *node = head;
        while (node != NULL)
        {
            if (node->left)
            {
                p->next = node->left;
                p = p->next;
            }
            if (node->right)
            {
                p->next = node->right;
                p = p->next;
            }
            node = node->next;
        }

        head = dummy->next;
        p = dummy;
        dummy->next = NULL;
    }

    return root;
}

// TC: O(N), SC: O(N)
class Solution
{
public:
    Node *connect(Node *root)
    {
        if (!root)
            return NULL;

        queue<pair<Node *, int>> que;
        Node *prev = NULL;
        int prevLevel = -1;
        que.push({root, 0});

        while (que.size() > 0)
        {
            pair<Node *, int> p = que.front();
            que.pop();

            Node *node = p.first;
            int level = p.second;

            // if (que.size() > 0 && que.back().second < level + 1)
            // {
            //     prev = NULL;
            // }
            if (prevLevel < level)
            {
                prevLevel = level;
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
                if (!prev)
                {
                    prev = node->right;
                }
                else
                {
                    prev->next = node->right;
                    prev = prev->next;
                }
            }
        }

        return root;
    }
};