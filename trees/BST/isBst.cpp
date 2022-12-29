// https://practice.geeksforgeeks.org/problems/check-for-bst/1/#

pair<int, int> solve(Node *root, bool &ans)
{
    if (!root)
        return {INT_MIN, INT_MIN};

    pair<int, int> lp = solve(root->left, ans);
    pair<int, int> rp = solve(root->right, ans);

    pair<int, int> ansp;
    if (lp.first == INT_MIN)
    {
        ansp.first = root->data;
    }
    else
    {
        ans = ans && (root->data > lp.second);
        ansp.first = lp.first;
    }

    if (rp.second == INT_MIN)
    {
        ansp.second = root->data;
    }
    else
    {
        ans = ans && (root->data < rp.first);
        ansp.second = rp.second;
    }
    return ansp;
}
bool isBST(Node *root)
{
    // Your code here
    bool ans = true;
    solve(root, ans);
    return ans;
}