// https://www.codingninjas.com/codestudio/problems/subset-sum-equal-to-k_1550954?leftPanelTab=0
// https://leetcode.com/problems/partition-equal-subset-sum/
#include <bits/stdc++.h>

bool canPartition(vector<int> &nums)
{
    int sum = 0, n = nums.size();
    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
    }

    if (sum % 2 != 0)
        return false;
    else
    {
        int k = sum / 2;
        return subsetSumToK(n, k, nums);
    }
}

bool subsetSumToK(int n, int k, vector<int> &arr)
{
    // Write your code here.
    if (k == 0)
        return true;

    vector<vector<bool>> dp(n + 1, vector<bool>(k + 1, false));

    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = true;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j - arr[i - 1] >= 0)
            {
                dp[i][j] = dp[i][j] || dp[i - 1][j - arr[i - 1]];
            }
        }
    }

    return dp[n][k];
}

bool subsetSumToK(int n, int k, vector<int> &arr)
{
    // Write your code here.

    if (k < 0)
    {
        return false;
    }
    else if (k == 0)
    {
        return true;
    }
    else if (n <= 0)
    {
        return false;
    }
    else
    {
        return subsetSumToK(n - 1, k - arr[n - 1], arr) ||
               subsetSumToK(n - 1, k, arr);
    }
}