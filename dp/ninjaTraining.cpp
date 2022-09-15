// https://www.codingninjas.com/codestudio/problems/ninja-s-training_3621003?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

int ninjaTraining(int n, vector<vector<int>> &A)
{
    // Write your code here.
    if (n == 0)
        return 0;

    vector<vector<int>> dp(n, vector<int>(3, 0));
    dp[0][0] = A[0][0];
    dp[0][1] = A[0][1];
    dp[0][2] = A[0][2];

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                if (j == k)
                    continue;
                dp[i][j] = max(dp[i][j], A[i][j] + dp[i - 1][k]);
            }
        }
    }

    return max(dp[n - 1][0], max(dp[n - 1][1], dp[n - 1][2]));
}