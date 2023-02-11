// https://leetcode.com/problems/number-of-longest-increasing-subsequence/description/

int findNumberOfLIS(vector<int> &nums)
{
    int n = nums.size(), maxm = 0;

    vector<int> dp(n, 1), count(n, 1);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[i] > nums[j] && dp[j] + 1 > dp[i])
            {
                dp[i] = dp[j] + 1;
                count[i] = count[j];
            }
            else if (nums[i] > nums[j] && dp[j] + 1 == dp[i])
            {
                count[i] += count[j];
            }
        }
        maxm = max(maxm, dp[i]);
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (dp[i] == maxm)
        {
            ans += count[i];
        }
    }
    return ans;
}