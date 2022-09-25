// https://www.codingninjas.com/codestudio/problems/maximum-path-sum-in-the-matrix_797998?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

#include <bits/stdc++.h>

int getMaxPathSum(vector<vector<int>> &matrix)
{
    //  Write your code here.
    int n = matrix.size();
    if (n == 0)
        return 0;
    int m = matrix[0].size();
    if (m == 0)
        return 0;
    vector<vector<int>> dp(n, vector<int>(m, 0));

    for (int i = 0; i < m; i++)
    {
        dp[0][i] = matrix[0][i];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int temp = dp[i - 1][j];
            if (j > 0)
                temp = max(temp, dp[i - 1][j - 1]);
            if (j < m - 1)
                temp = max(temp, dp[i - 1][j + 1]);

            dp[i][j] = matrix[i][j] + temp;
        }
    }

    int ans = INT_MIN;
    for (int i = 0; i < m; i++)
    {
        ans = max(ans, dp[n - 1][i]);
    }
    return ans;
}