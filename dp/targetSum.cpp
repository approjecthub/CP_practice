// https://leetcode.com/problems/target-sum/

int findTargetSumWays(vector<int> &arr, int d)
{
    int n = arr.size();
    int total = 0;
    for (int i = 0; i < n; i++)
        total += arr[i];

    if ((total - d) >= 0 && (total - d) % 2 == 0)
    {
        int k = (total - d) / 2;
        vector<int> prev(k + 1, 0);
        vector<int> curr(k + 1);

        if (arr[0] == 0)
            prev[0] = 2;
        else
            prev[0] = 1;
        if (arr[0] != 0 && arr[0] <= k)
            prev[arr[0]] = 1;

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j <= k; j++)
            {
                int notTake = prev[j];
                int take = 0;
                if (j >= arr[i])
                {
                    take = prev[j - arr[i]];
                }
                curr[j] = (notTake + take);
            }
            prev = curr;
        }

        return prev[k];
    }
    else
    {
        return 0;
    }
}

class Solution
{
public:
    int solve(vector<int> &nums, int target, int n, vector<vector<int>> &dp)
    {
        if (n == 0 && target == 0)
            return 1;
        else if (n == 0)
            return 0;
        else
        {
            if (dp[n - 1][target + 2000] != -1)
                return dp[n - 1][target + 2000];
            dp[n - 1][target + 2000] = solve(nums, target - nums[n - 1], n - 1, dp) + solve(nums, target + nums[n - 1], n - 1, dp);
            return dp[n - 1][target + 2000];
        }
    }
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(4001, -1));
        solve(nums, target, n, dp);
        return dp[n - 1][target + 2000];
    }
};