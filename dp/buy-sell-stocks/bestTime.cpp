// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
// Topics: Dynamic Programming, Array, Greedy

int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    int minm = prices[0], maxmProfit = 0;
    for (int i = 1; i < n; i++)
    {
        maxmProfit = max(maxmProfit, prices[i] - minm);
        minm = min(minm, prices[i]);
    }
    return maxmProfit;
}