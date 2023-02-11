// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/

int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

    for (int idx = n - 1; idx >= 0; idx--)
    {
        for (int isBuy = 0; isBuy <= 1; isBuy++)
        {
            for (int cap = 1; cap <= 2; cap++)
            {

                if (isBuy)
                {
                    dp[idx][isBuy][cap] = max(-prices[idx] +
                                                  dp[idx + 1][!isBuy][cap],
                                              dp[idx + 1][isBuy][cap]);
                }
                else
                {
                    dp[idx][isBuy][cap] = max(prices[idx] +
                                                  dp[idx + 1][!isBuy][cap - 1],
                                              dp[idx + 1][isBuy][cap]);
                }
            }
        }
    }

    return dp[0][1][2];
}