// https://leetcode.com/problems/subsets/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void solve(vector<vector<int>> &ans, vector<int> &nums, vector<int> &temp, int idx)
    {
        int n = nums.size();
        if (idx == n)
        {
            ans.push_back(temp);
            return;
        }

        // Include nums[idx]
        temp.push_back(nums[idx]);
        solve(ans, nums, temp, idx + 1);
        temp.pop_back();

        // Exclude nums[idx]
        solve(ans, nums, temp, idx + 1);
    }
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(ans, nums, temp, 0);
        return ans;
    }
};