// https://practice.geeksforgeeks.org/problems/palindromic-patitioning4845/1

bool isPalindrome(string str, int idx1, int idx2)
{
    string s1 = str.substr(idx1, idx2 - idx1 + 1);
    string s2 = s1;
    reverse(s2.begin(), s2.end());

    return s1 == s2;
}
int solve(string str, int idx)
{
    int n = str.size();
    if (idx > n)
        return 0;

    // int ans = n-idx-1;
    int ans = 1e9;
    for (int i = idx; i < n; i++)
    {
        if (isPalindrome(str, idx, i))
        {
            ans = min(ans, 1 + solve(str, i + 1));
        }
    }

    return ans;
}
int palindromicPartition(string str)
{
    // code here
    // return solve(str, 0)-1;
    int n = str.size();
    vector<int> dp(n + 1, 0);

    for (int idx = n - 1; idx >= 0; idx--)
    {
        int ans = 1e9;
        for (int i = idx; i < n; i++)
        {
            if (isPalindrome(str, idx, i))
            {
                ans = min(ans, 1 + dp[i + 1]);
            }
        }

        dp[idx] = ans;
    }

    return dp[0] - 1;
}