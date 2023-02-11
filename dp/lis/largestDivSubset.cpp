// https://leetcode.com/problems/largest-divisible-subset/description/

vector<int> largestDivisibleSubset(vector<int> &nums)
{
    sort(nums.begin(), nums.end());

    int maxm = 0, maxmEle = 0, n = nums.size();
    vector<int> ans, dp(n, 1);

    for (int i = 0; i < n; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i])
            {
                dp[i] = dp[j] + 1;
            }
        }
        if (dp[i] > maxm)
        {
            maxm = dp[i];
            maxmEle = nums[i];
        }
    }

    for (int i = n - 1; i >= 0; i--)
    {
        if (dp[i] == maxm && maxmEle % nums[i] == 0)
        {
            maxmEle = nums[i];
            ans.push_back(maxmEle);
            maxm--;
        }
    }

    return ans;
}