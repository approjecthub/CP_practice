// https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1

int solve(int i, int j, int arr[])
{
    if (i == j)
    {
        return 0; // since it means a single matrix
    }
    int minm = 1e9;
    for (int k = i; k < j; k++)
    {
        minm = min(minm, (arr[i - 1] * arr[k] * arr[j]) +
                             solve(i, k, arr) + solve(k + 1, j, arr));
    }

    return minm;
}
int matrixMultiplication(int N, int arr[])
{
    // code here
    // return solve(1, N-1, arr);
    int dp[N][N];

    for (int i = 0; i < N; i++)
        dp[i][i] = 0;

    for (int i = N - 1; i >= 1; i--)
    {
        for (int j = i + 1; j < N; j++)
        {
            int minm = 1e9;
            for (int k = i; k < j; k++)
            {
                minm = min(minm, (arr[i - 1] * arr[k] * arr[j]) +
                                     dp[i][k] + dp[k + 1][j]);
            }

            dp[i][j] = minm;
        }
    }

    return dp[1][N - 1];
}