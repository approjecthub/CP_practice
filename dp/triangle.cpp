// https://leetcode.com/problems/triangle/

// TC: O(N^2), SC: O(N)
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> prev(n,0);
        vector<int> curr(n,0);
        prev[0] = triangle[0][0];
        
        for(int i=1;i<n; i++){
            for(int j=0; j<=i; j++){
                int temp=1e9;
                if(j<i) temp = prev[j];
                if(j>0) temp = min(temp, prev[j-1]);
                
                curr[j] = triangle[i][j] + temp;
            }
            
            for(int k=0; k<n; k++){
                prev[k] = curr[k];
            }
        }
        
        int ans=INT_MAX;
        for(int i=0; i<n; i++){
            ans = min(ans, prev[i]);
        }
        
        return ans;
    }
};

// TC: O(N^2), SC: O(N^2)
class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        dp[0][0] = triangle[0][0];

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                int prev = 1e9;
                if (j < i)
                    prev = dp[i - 1][j];
                if (j > 0)
                    prev = min(prev, dp[i - 1][j - 1]);

                dp[i][j] = triangle[i][j] + prev;
            }
        }

        int ans = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            ans = min(ans, dp[n - 1][i]);
        }

        return ans;
    }
};