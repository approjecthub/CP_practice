// https://leetcode.com/problems/decode-ways/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int recursiveSolve(string s, int i)
    {
        if (i == s.size())
            return 1;

        if (s[i] == '0')
            return 0;

        if (i < s.size() - 1 && ((s[i] == '2' && s[i + 1] <= '6') || s[i] == '1'))
            return recursiveSolve(s, i + 1) + recursiveSolve(s, i + 2);
        return recursiveSolve(s, i + 1);
    }

    int numDecodings(string s)
    {
        // return recursiveSolve(s, 0);

        int n = s.size();
        if ((n == 1 && s[0] == '0'))
            return 0;

        vector<int> dp(n + 1, 0);

        dp[n] = 1;

        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] == '0')
            {
                dp[i] = 0;
                continue;
            }
            else if (i < n - 1 && ((s[i] == '2' && s[i + 1] <= '6') || s[i] == '1'))
            {
                dp[i] = dp[i + 1] + dp[i + 2];
            }
            else
            {
                dp[i] = dp[i + 1];
            }
        }
        return dp[0];
    }
};