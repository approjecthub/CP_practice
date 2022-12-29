// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
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
    TreeNode *solve(vector<int> &nums, int l, int h)
    {
        if (h < l)
            return NULL;
        int mid = l + (h - l) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = solve(nums, l, mid - 1);
        root->right = solve(nums, mid + 1, h);
        return root;
    };
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return solve(nums, 0, nums.size() - 1);
    }
};

// https://practice.geeksforgeeks.org/problems/array-to-bst4443/1/
void solve(vector<int> &nums, int l, int h, vector<int> &ans)
{
    if (h < l)
        return;
    int mid = l + (h - l) / 2;
    ans.push_back(nums[mid]);
    solve(nums, l, mid - 1, ans);
    solve(nums, mid + 1, h, ans);
};

vector<int> sortedArrayToBST(vector<int> &nums)
{
    // Code here
    vector<int> ans;
    solve(nums, 0, nums.size() - 1, ans);
    return ans;
}