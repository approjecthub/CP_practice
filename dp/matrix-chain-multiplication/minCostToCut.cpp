// https://leetcode.com/problems/minimum-cost-to-cut-a-stick/

class Solution
{
public:
    int n;
    int solve(vector<int> &cuts, int i, int j)
    {
        if (i > j)
            return 0;
        int minm = 1e9;
        for (int k = i; k <= j; k++)
        {
            int lele = i - 1 >= 0 ? cuts[i - 1] : 0;
            int rele = j + 1 < cuts.size() ? cuts[j + 1] : n;

            int cost = (rele - lele) + solve(cuts, i, k - 1) + solve(cuts, k + 1, j);
            minm = min(minm, cost);
        }

        return minm;
    }

    int minCost(int n, vector<int> &cuts)
    {
        // this->n = n;
        // sort(cuts.begin(), cuts.end());
        // return solve(cuts, 0, cuts.size()-1);

        int cutsLen = cuts.size();
        vector<vector<int>> dp(cutsLen, vector<int>(cutsLen, 0));
        sort(cuts.begin(), cuts.end());

        for (int i = cutsLen - 1; i >= 0; i--)
        {
            for (int j = i; j < cutsLen; j++)
            {
                int minm = 1e9;
                for (int k = i; k <= j; k++)
                {
                    int lele = i - 1 >= 0 ? cuts[i - 1] : 0;
                    int rele = j + 1 < cuts.size() ? cuts[j + 1] : n;

                    int cost = rele - lele;
                    if (k - 1 >= 0)
                    {
                        cost += dp[i][k - 1];
                    }
                    if (k + 1 < cutsLen)
                    {
                        cost += dp[k + 1][j];
                    }
                    minm = min(minm, cost);
                }

                dp[i][j] = minm;
            }
        }

        return dp[0][cutsLen - 1];
    }
};

// below top/bottom down dp is producing TLE, need to do better

// int solve(vector<int>& cuts, int i, int j){
//     if(j-i<=1) return 0;
//     int minm = 1e9;
//     for(int k=0; k<cuts.size(); k++){
//         if(cuts[k]>i && cuts[k]<j){
//             int cost = (j-i)+solve(cuts, i,cuts[k])
//                     +solve(cuts, cuts[k], j);
//             minm = min(minm, cost);
//         }
//     }

//     return minm==1e9?0:minm;
// }

int solve(vector<int> &cuts, int i, int j,
          vector<vector<int>> &dp)
{
    if (j - i <= 1)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int minm = 1e9;
    for (int k = 0; k < cuts.size(); k++)
    {
        if (cuts[k] > i && cuts[k] < j)
        {
            int cost = (j - i) + solve(cuts, i, cuts[k], dp) + solve(cuts, cuts[k], j, dp);
            minm = min(minm, cost);
        }
    }

    dp[i][j] = minm == 1e9 ? 0 : minm;
    return dp[i][j];
}
int minCost(int n, vector<int> &cuts)
{
    // vector<vector<int>> dp(n+1, vector<int>(n+1,-1));
    // return solve(cuts, 0, n, dp);

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int i = n; i >= 0; i--)
    {
        for (int j = i + 2; j <= n; j++)
        {
            int minm = 1e9;
            for (int k = 0; k < cuts.size(); k++)
            {
                if (cuts[k] > i && cuts[k] < j)
                {
                    int cost = (j - i) + dp[i][cuts[k]] + dp[cuts[k]][j];
                    minm = min(minm, cost);
                }
            }
            dp[i][j] = minm == 1e9 ? 0 : minm;
        }
    }

    return dp[0][n];
}