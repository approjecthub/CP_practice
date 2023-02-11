// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/

class Solution {
public:
    int solve(vector<int>& prices, int idx, bool isBuy){
        int n = prices.size();
        if(idx>=n) return 0;

        if(isBuy){
            return max( -prices[idx]+
            solve(prices, idx+1, !isBuy),
            solve(prices, idx+1, isBuy));
        }
        else{
            return max( prices[idx]+
            solve(prices, idx+1, !isBuy),
            solve(prices, idx+1, isBuy));
        }
    }
    int maxProfit(vector<int>& prices) {
        // return solve(prices, 0, true);
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, 0));
        //base case 
        dp[n][0]=dp[n][1]=0;

        for(int idx=n-1; idx>=0; idx--){
            for(int isBuy=0; isBuy<=1; isBuy++){
                if(isBuy){
                    dp[idx][isBuy] = max( -prices[idx]+
                    dp[idx+1][!isBuy],dp[idx+1][isBuy]);
                }
                else{
                    dp[idx][isBuy] = max( prices[idx]+
                    dp[idx+1][!isBuy],dp[idx+1][isBuy]);
                }
            }
        }

        return dp[0][1];
    }
};