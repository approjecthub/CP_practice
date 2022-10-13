// https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1

int knapSack(int W, int wt[], int val[], int n)
{
    vector<int> prev(W + 1, 0);
    vector<int> curr(W + 1, 0);
    if (wt[0] <= W)
        prev[wt[0]] = val[0];
    for (int w = wt[0]; w <= W; w++)
    {
        prev[w] = val[0];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            int notTake = prev[j], take = 0;
            if (wt[i] <= j)
                take = val[i] + prev[j - wt[i]];

            curr[j] = max(take, notTake);
        }
        prev = curr;
    }
    return prev[W];
}

int knapSack(int W, int wt[], int val[], int n)
{
    // Your code here
    //   if(n==0 || W==0) return 0;
    //   if(wt[n-1]<=W) return max(val[n-1] + knapSack(W-wt[n-1], wt, val, n-1),
    //                     knapSack(W, wt, val, n-1));
    //   else knapSack(W, wt, val, n-1);

    vector<vector<int>> dp(n, vector<int>(W + 1, 0));
    if (wt[0] <= W)
        dp[0][wt[0]] = val[0];

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            int notTake = dp[i - 1][j], take = 0;
            if (wt[i] <= j)
                take = val[i] + dp[i - 1][j - wt[i]];

            dp[i][j] = max(take, notTake);
        }
    }
    int ans = 0;
    for (int i = 1; i <= W; i++)
    {
        ans = max(ans, dp[n - 1][i]);
    }
    return ans;
}