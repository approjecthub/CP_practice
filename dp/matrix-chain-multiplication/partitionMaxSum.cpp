// https://leetcode.com/problems/partition-array-for-maximum-sum/description/

int solve(vector<int> &arr, int idx, int k)
{
    int n = arr.size();

    if (idx > n)
        return 0;

    int ans = 0, temp = 0;
    for (int i = idx; i < n && i < idx + k; i++)
    {
        temp = max(temp, arr[i]);
        ans = max(ans, ((temp * (i - idx + 1)) + solve(arr, i + 1, k)));
    }

    return ans;
}
int maxSumAfterPartitioning(vector<int> &arr, int k)
{
    // return solve(arr, 0, k);

    int n = arr.size();
    vector<int> dp(n + 1, 0);

    for (int idx = n - 1; idx >= 0; idx--)
    {
        int ans = 0, temp = 0;
        for (int i = idx; i < n && i < idx + k; i++)
        {
            temp = max(temp, arr[i]);
            ans = max(ans, ((temp * (i - idx + 1)) + dp[i + 1]));
        }

        dp[idx] = ans;
    }

    return dp[0];
}