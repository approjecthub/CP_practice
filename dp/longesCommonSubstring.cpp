// https://practice.geeksforgeeks.org/problems/longest-common-substring1452/1
int longestCommonSubstr(string s1, string s2, int x, int y)
{
    // your code here
    // if(x<=0 || y<=0) return 0;

    // else{
    //     int tempCount = 0;
    //     if(s1[x-1] == s2[y-1]){
    //         int x1=x,y1=y;
    //         while(x>0 && y>0 && s1[x-1] == s2[y-1]){
    //             tempCount++;
    //             x--;
    //             y--;
    //         }
    //         return max(tempCount, max(longestCommonSubstr(s1, s2,x1-1, y1), longestCommonSubstr( s1, s2,x1, y1-1)));
    //     }
    //     else{
    //         return max(longestCommonSubstr(s1, s2,x-1, y), longestCommonSubstr( s1, s2,x, y-1));
    //     }
    // }
    vector<vector<int>> dp(x + 1, vector<int>(y + 1, 0));
    int maxm = 0;
    for (int i = 1; i <= x; i++)
    {

        for (int j = 1; j <= y; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                maxm = max(maxm, dp[i][j]);
            }
        }
    }
    return maxm;
}