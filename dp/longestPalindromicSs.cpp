// https://practice.geeksforgeeks.org/problems/longest-palindromic-subsequence-1612327878/1
int longestPalinSubseq(string A)
{
    // code here
    string s1 = A;
    reverse(A.begin(), A.end());
    string s2 = A;
    int x = A.size(), y = A.size();

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

    return dp[x][y];
}