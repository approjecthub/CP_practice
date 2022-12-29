// https://leetcode.com/problems/shortest-common-supersequence/description/
string shortestCommonSupersequence(string s1, string s2)
{
    int x = s1.size(), y = s2.size();

    vector<vector<int>> dp(x + 1, vector<int>(y + 1, 0));
    for (int i = 1; i <= x; i++)
    {

        for (int j = 1; j <= y; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    // int ansLen = x+y-dp[x][y];
    // char ans[ansLen];
    string ans = "";
    while (x > 0 && y > 0)
    {
        if (s1[x - 1] == s2[y - 1])
        {
            ans = s1[x - 1] + ans;
            x--;
            y--;
        }
        else
        {
            if (dp[x][y] == dp[x - 1][y])
            {
                ans = s1[x - 1] + ans;
                x--;
            }
            else
            {
                ans = s2[y - 1] + ans;
                y--;
            }
        }
    }
    while (x > 0)
    {
        ans = s1[x - 1] + ans;
        x--;
    }
    while (y > 0)
    {
        ans = s2[y - 1] + ans;
        y--;
    }
    return ans;
}