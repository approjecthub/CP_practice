// https://practice.geeksforgeeks.org/problems/edit-distance3702/1

int editDistance(string s1, string s2)
{
    // Code here
    int x = s1.size(), y = s2.size();
    vector<vector<int>> dp(x + 1, vector<int>(y + 1, 0));

    for (int i = 0; i <= x; i++)
    {
        dp[i][0] = i;
    }
    for (int i = 0; i <= y; i++)
    {
        dp[0][i] = i;
    }
    for (int i = 1; i <= x; i++)
    {

        for (int j = 1; j <= y; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1]));
            }
        }
    }

    return dp[x][y];
}