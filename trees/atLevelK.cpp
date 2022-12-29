// https://practice.geeksforgeeks.org/problems/k-distance-from-root/1/#

/* A binary tree node has data, pointer to left child
   and a pointer to right child /
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

    // function should print the nodes at k distance from root
    vector<int> Kdistance(struct Node *root, int k)
{
    // Your code here
    queue<pair<Node *, int>> que;
    que.push({root, 0});
    vector<int> ans;
    while (que.size() > 0)
    {
        pair<Node *, int> top = que.front();
        que.pop();
        if (k == top.second)
        {
            ans.push_back(top.first->data);
        }
        if (top.first->left)
        {
            que.push({top.first->left, top.second + 1});
        }
        if (top.first->right)
        {
            que.push({top.first->right, top.second + 1});
        }
    }
    return ans;
}