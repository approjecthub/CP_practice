// https://leetcode.com/problems/coin-change-ii/

class Solution
{
public:
    int solve(vector<int> &coins, int amt, int n)
    {
        vector<vector<int>> dp(n, vector<int>(amt + 1, 0));
        for (int i = 1; i <= amt; i++)
        {
            if (i % coins[0] == 0)
                dp[0][i] = 1;
        }
        for (int i = 0; i < n; i++)
        {
            dp[i][0] = 1;
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j <= amt; j++)
            {
                int take = 0, notTake = dp[i - 1][j];
                if (coins[i] <= j)
                {
                    take = dp[i][j - coins[i]];
                }
                dp[i][j] = take + notTake;
            }
        }
        return dp[n - 1][amt];
    }
    //     int solve(vector<int>& coins, int amt, int n){
    //         if(amt==0) return 1;
    //         else if(amt<0 || n<=0) return 0;
    //         else{
    //             int take=0, notTake = solve(coins, amt, n-1);

    //             if(coins[n-1]<=amt){
    //                 take = solve(coins, amt-coins[n-1], n);
    //             }

    //             return take+notTake;
    //         }
    //     }
    int change(int amount, vector<int> &coins)
    {
        return solve(coins, amount, coins.size());
    }
};