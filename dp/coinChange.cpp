// https://leetcode.com/problems/coin-change/

class Solution {
public:
    int solve(vector<int>& coins, int amt, int n){
        // cout<<amt<<","<<n<<endl;
        vector<vector<int>> dp(n, vector<int>(amt+1, -1));
        for(int i=0; i<n; i++) dp[i][0] = 0;
        for(int i=1; i<=amt; i++){
            if(i%coins[0]==0) dp[0][i] = i/coins[0];
        }
        
        for(int i=1; i<n; i++){
            for(int j=1; j<=amt; j++){
                int take=-1, notTake = dp[i-1][j];
                if(coins[i]<=j){
                take = dp[i][j-coins[i]];
                }
                int tempAns;
                if(take>-1 && notTake>-1) tempAns= min(1+take, notTake);
                else if(take>-1) tempAns= 1+take;
                else if(notTake>-1) tempAns= notTake;
                else tempAns= -1;
                dp[i][j] = tempAns;
            }
        }
        return dp[n-1][amt];
    }
    
    int coinChange(vector<int>& coins, int amount) {
        return solve(coins, amount, coins.size());
    }
};

class Solution {
public:
    int solve(vector<int>& coins, int amt, int n){
        // cout<<amt<<","<<n<<endl;
        if(amt==0) return 0;
        else if(amt<0 || n<=0) return -1;
        else{
            int take=-1, notTake = solve(coins, amt, n-1);
            
            if(coins[n-1]<=amt){
                take = solve(coins, amt-coins[n-1], n);
            }
            
            if(take>-1 && notTake>-1) return min(1+take, notTake);
            else if(take>-1) return 1+take;
            else if(notTake>-1) return notTake;
            else return -1;
        }
    }
    int coinChange(vector<int>& coins, int amount) {
        return solve(coins, amount, coins.size());
    }
};