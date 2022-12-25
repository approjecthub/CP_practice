// https://practice.geeksforgeeks.org/problems/rod-cutting0840/1

int solve(int price[], int n, int W)
{

    if (W <= 0 || n <= 0)
        return 0;
    else
    {
        if (W >= n)
        {
            return max(price[n - 1] + solve(price, n, W - n), solve(price, n - 1, W));
        }
        else
        {
            solve(price, n - 1, W);
        }
    }
}
int cutRod(int price[], int n)
{
    // code here
    return solve(price, n, n);
}

/////////////////////////////////////////////////////////////////////////

int cutRod(int price[], int n)
{
    // code here
    //  vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
    //  return solve(price, n, n, dp);
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    // for(int i=1; i<=n; i++) dp[0][i] = price[0]*i;

    for (int N = 1; N <= n; N++)
    {
        for (int W = 1; W <= n; W++)
        {
            int notTake = dp[N - 1][W], take = 0;
            if (W >= N)
            {
                take = price[N - 1] + dp[N][W - N];
            }
            dp[N][W] = max(take, notTake);
        }
    }
    return dp[n][n];
}