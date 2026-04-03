// https://leetcode.com/problems/permutations/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void swap(vector<int> &nums, int a, int b)
    {
        int temp = nums[a];
        nums[a] = nums[b];
        nums[b] = temp;
    }

    void solve(vector<vector<int>> &ans, vector<int> &nums, int idx)
    {
        int n = nums.size();
        if (idx == n)
        {
            ans.push_back(nums);
            return;
        }

        for (int i = idx; i < n; i++)
        {
            swap(nums, idx, i);
            solve(ans, nums, idx + 1);
            swap(nums, idx, i); // backtrack
        }
    }

    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;
        solve(ans, nums, 0);
        return ans;
    }
};