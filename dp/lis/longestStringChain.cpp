// https://leetcode.com/problems/longest-string-chain/description/

class Solution
{
public:
    bool isStringChain(string &x, string &y)
    {
        int i = 0, j = 0, n = x.size(), m = y.size();
        int numOfMatches = 0;
        if (m + 1 != n)
            return false;

        while (i < n && j < m)
        {
            if (x[i] == y[j])
            {
                i++;
                j++;
                numOfMatches++;
            }
            else
            {
                i++;
            }
        }

        return numOfMatches == m;
    }

    bool static compare(string &x, string &y)
    {
        int n = x.size(), m = y.size();
        if (n < m)
            return true;
        else if (n > m)
            return false;
        else
            return x < y;
    }

    int longestStrChain(vector<string> &words)
    {

        int maxm = 0, n = words.size();
        sort(words.begin(), words.end(), compare);

        vector<int> dp(n, 1);
        for (int i = 0; i < n; i++)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                if (isStringChain(words[i], words[j]) && dp[j] + 1 > dp[i])
                {
                    dp[i] = dp[j] + 1;
                }
            }
            if (dp[i] > maxm)
            {
                maxm = dp[i];
            }
        }

        return maxm;
    }
};