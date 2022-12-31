// https://practice.geeksforgeeks.org/problems/wildcard-pattern-matching/1

bool solve(string s1, string s2, int x, int y)
{
    if (x == 0 && y == 0)
        return true;
    else if (x == 0)
    {
        return false;
    }
    else if (y == 0)
    {
        if (s1[x - 1] == '*')
            return solve(s1, s2, x - 1, y);
        else
            return false;
    }
    else
    {
        if (s1[x - 1] == s2[y - 1] || s1[x - 1] == '?')
            return solve(s1, s2, x - 1, y - 1);
        else if (s1[x - 1] == '*')
        {
            return solve(s1, s2, x - 1, y - 1) || solve(s1, s2, x, y - 1) || solve(s1, s2, x - 1, y);
        }
        else
        {
            return false;
        }
    }
}
int wildCard(string s1, string s2)
{
    int x = s1.size(), y = s2.size();
    // return solve(s1, s2, x, y);
    vector<vector<bool>> dp(x + 1, vector<bool>(y + 1, false));
    // x==0 && y==0
    dp[0][0] = true;

    // x==0
    for (int i = 1; i <= y; i++)
    {
        dp[0][i] = false;
    }
    // y==0
    for (int i = 1; i <= x; i++)
    {
        if (s1[i - 1] == '*')
        {
            dp[i][0] = dp[i - 1][0];
        }
        else
        {
            dp[i][0] = false;
        }
    }

    for (int i = 1; i <= x; i++)
    {
        for (int j = 1; j <= y; j++)
        {
            if (s1[i - 1] == s2[j - 1] || s1[i - 1] == '?')
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else if (s1[i - 1] == '*')
            {
                dp[i][j] = dp[i - 1][j - 1] || dp[i][j - 1] || dp[i - 1][j];
            }
            else
            {
                dp[i][j] = false;
            }
        }
    }
    return dp[x][y];
}