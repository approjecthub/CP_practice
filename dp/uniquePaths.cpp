// https://leetcode.com/problems/unique-paths/

int uniquePaths(int m, int n)
{
    //         if(m==1 && n==1) return 1;
    //         else if(m<1 || n<1) return -1;

    //         else{
    //             //left
    //             int d1 = uniquePaths(m, n-1);

    //             //up
    //             int d2 = uniquePaths(m-1, n);

    //             if(d1>-1 && d2>-1){
    //                 return d1+d2;
    //             }
    //             else if(d1>-1){
    //                 return d1;
    //             }
    //             else {
    //                 return d2;
    //             }
    //         }

    vector<vector<int>> dp(m, vector<int>(n, 0));
    dp[0][0] = 1;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j > 0)
            {
                dp[i][j] += dp[i][j - 1];
            }
            if (i > 0)
            {
                dp[i][j] += dp[i - 1][j];
            }
        }
    }

    return dp[m - 1][n - 1];
}