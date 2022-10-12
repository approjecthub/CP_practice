// https://practice.geeksforgeeks.org/problems/minimum-sum-partition3317/1

int minDifference(int arr[], int n)
{
    // Your code goes here

    int total = 0;
    for (int i = 0; i < n; i++)
    {
        total += arr[i];
    }
    vector<vector<bool>> dp(n + 1, vector<bool>(total + 1, false));

    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = true;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= total; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j - arr[i - 1] >= 0)
            {
                dp[i][j] = dp[i][j] || dp[i - 1][j - arr[i - 1]];
            }
        }
    }

    int diff = INT_MAX;
    for (int i = 0; i <= total; i++)
    {
        if (dp[n][i])
        {
            diff = min(abs(total - (2 * i)), diff);
        }
    }

    return diff;
}

int solve(int arr[], int n, int ss, int total)
{
    if (n <= 0)
    {
        return abs(total - (2 * ss));
    }
    else
    {
        return min(solve(arr, n - 1, ss + arr[n - 1], total), solve(arr, n - 1, ss, total));
    }
}
int minDifference(int arr[], int n)
{
    // Your code goes here
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        total += arr[i];
    }
    return solve(arr, n, 0, total);
}