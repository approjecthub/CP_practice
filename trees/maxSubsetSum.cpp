// https://practice.geeksforgeeks.org/problems/maximum-sum-of-non-adjacent-nodes/1/#

// Node Structure
/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

//################################# TC: O(2^n) ################################################
class Solution
{
public:
    int solve(Node *root, bool consider)
    {
        if (!root)
            return 0;
        if (consider)
        {
            return max(root->data + solve(root->left, false) + solve(root->right, false),
                       solve(root->left, true) + solve(root->right, true));
        }
        else
        {
            return solve(root->left, true) + solve(root->right, true);
        }
    }
    // Function to return the maximum sum of non-adjacent nodes.
    int getMaxSum(Node *root)
    {
        // Add your code here
        return solve(root, true);
    }
};

// ############################ TC: O(n) #######################################
// used dp

pair<int, int> solve(Node *root)
{
    if (!root)
        return {0, 0};
    pair<int, int> lS = solve(root->left);
    pair<int, int> rS = solve(root->right);

    pair<int, int> ans;
    ans.first = root->data + lS.second + rS.second;
    ans.second = max(lS.first, lS.second) + max(rS.first, rS.second);
    return ans;
}
// Function to return the maximum sum of non-adjacent nodes.
int getMaxSum(Node *root)
{
    // Add your code here
    pair<int, int> ans = solve(root);
    return max(ans.first, ans.second);
}