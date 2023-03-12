// https://leetcode.com/problems/burst-balloons/description/

int solve(vector<int> &nums, int i, int j)
{
    if (i > j)
        return 0;

    int n = nums.size(), maxCost = -1e9;
    for (int k = i; k <= j; k++)
    {
        int cost = nums[k];
        if (i - 1 >= 0)
            cost *= nums[i - 1];
        if (j + 1 < n)
            cost *= nums[j + 1];
        maxCost = max(maxCost, cost +
                                   solve(nums, i, k - 1) + solve(nums, k + 1, j));
    }

    return maxCost;
}
int maxCoins(vector<int> &nums)
{
    // return solve(nums, 0, nums.size()-1);
    int numsLen = nums.size();
    vector<vector<int>> dp(numsLen, vector<int>(numsLen, 0));

    for (int i = numsLen - 1; i >= 0; i--)
    {
        for (int j = i; j < numsLen; j++)
        {
            int maxm = -1e9;
            for (int k = i; k <= j; k++)
            {
                int cost1 = nums[k];
                int cost2 = 0;
                if (i - 1 >= 0)
                {
                    cost1 *= nums[i - 1];
                }
                if (j + 1 < numsLen)
                {
                    cost1 *= nums[j + 1];
                }

                if (k - 1 >= 0)
                {
                    cost2 += dp[i][k - 1];
                }
                if (k + 1 < numsLen)
                {
                    cost2 += dp[k + 1][j];
                }
                maxm = max(maxm, cost1 + cost2);
            }

            dp[i][j] = maxm;
        }
    }

    return dp[0][numsLen - 1];
}