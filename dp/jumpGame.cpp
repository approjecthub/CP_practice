// https://practice.geeksforgeeks.org/problems/jump-game/1

int solve(int A[], int N, int i, vector<int> &dp)
{
    if (dp[i] != -1)
        return dp[i];

    if (i == N - 1)
    {
        dp[i] = 1;
    }
    else if (i > N - 1)
    {
        dp[i] = 0;
    }
    else
    {
        dp[i] = 0;
        for (int j = 1; j <= A[i]; j++)
        {
            int tempAns = solve(A, N, i + j, dp);
            if (tempAns == 1)
            {
                dp[i] = 1;
                break;
            }
        }
    }

    return dp[i];
}
int canReach(int A[], int N)
{
    // code here
    vector<int> dp(N, -1);
    solve(A, N, 0, dp);
    return dp[N - 1] == -1 ? 0 : dp[N - 1];
}

// bottom up approach

void solve(int A[], int N, vector<int> &dp)
{
    dp[0] = 1;
    for (int i = 0; i < N; i++)
    {
        if (!dp[i])
            break;
        int m = min(A[i], N - i - 1);
        for (int j = m; j >= 1; j--)
        {
            if (!dp[i + j])
            {
                dp[i + j] = 1;
            }
            else
            {
                break;
            }
        }
    }
}
int canReach(int A[], int N)
{
    // code here
    vector<int> dp(N, 0);
    solve(A, N, dp);
    return dp[N - 1];
}