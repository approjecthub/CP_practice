// https://practice.geeksforgeeks.org/problems/distinct-occurrences/1

// int solve(string s1, string s2, int x, int y){
//     if(y==0) return 1;
//     if(x==0) return 0;
//     int ans=0;
//     if(s1[x-1]==s2[y-1]){
//         ans += solve(s1,s2,x-1,y-1);
//     }
//     ans += solve(s1, s2, x-1, y);
//     return ans;
// }

// int solve(string s1, string s2, int x, int y,vector<vector<int>> &dp){
//     if(y==0) return 1;
//     if(x==0) return 0;
//     if(dp[x][y]!=-1) return dp[x][y];
//     int ans=0;
//     if(s1[x-1]==s2[y-1]){
//         ans += solve(s1,s2,x-1,y-1, dp);
//     }
//     ans += solve(s1, s2, x-1, y, dp);
//     dp[x][y] = ans;
//     return ans;
// }
int subsequenceCount(string s1, string s2)
{
    // Your code here
    int mod = 1e9 + 7;
    int x = s1.size(), y = s2.size();
    vector<vector<int>> dp(x + 1, vector<int>(y + 1, 0));
    // return solve(s1, s2,x,y,dp );
    for (int i = 0; i <= x; i++)
        dp[i][0] = 1;
    for (int i = 1; i <= x; i++)
    {
        for (int j = 1; j <= y; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] % mod;
            }
            dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;
        }
    }

    return dp[x][y];
}