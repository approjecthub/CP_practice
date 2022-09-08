// https://leetcode.com/problems/number-of-ways-to-reach-a-position-after-exactly-k-steps/

class Solution
{
public:
    int mod = 1e9 + 7;

    long solve(int strt, int end, int k, vector<vector<long>> &dp)
    {
        if (dp[strt + 1000][k] != -1)
            return dp[strt + 1000][k];
        if (k == 0)
        {
            if (strt == end)
            {
                dp[strt + 1000][k] = 1;
            }
            else
            {
                dp[strt + 1000][k] = 0;
            }
        }
        else
        {
            long temp1, temp2;
            temp1 = solve(strt + 1, end, k - 1, dp) % mod;
            temp2 = solve(strt - 1, end, k - 1, dp) % mod;
            dp[strt + 1000][k] = (temp1 + temp2) % mod;
        }
        return dp[strt + 1000][k];
    }
    int numberOfWays(int startPos, int endPos, int k)
    {
        vector<vector<long>> dp(3001, vector<long>(1001, -1));
        return solve(startPos, endPos, k, dp);
    }
};