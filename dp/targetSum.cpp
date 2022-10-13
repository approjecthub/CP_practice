// https://leetcode.com/problems/target-sum/

class Solution {
public:
    int solve(vector<int>& nums, int target, int n, vector<vector<int>> &dp){
        if(n==0 && target==0) return 1;
        else if(n==0) return 0;
        else{
            if(dp[n-1][target+2000]!=-1) return dp[n-1][target+2000];
            dp[n-1][target+2000]= solve(nums, target-nums[n-1], n-1, dp)+solve(nums, target+nums[n-1], n-1, dp);
            return dp[n-1][target+2000];
        }
        
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>> dp(n, vector<int>(4001, -1));
        solve(nums, target, n, dp);
        return dp[n-1][target+2000];
    }
};