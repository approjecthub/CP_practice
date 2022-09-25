// https://leetcode.com/problems/cherry-pickup-ii/

// bottom-up
class Solution
{
public:
    int cherryPickup(vector<vector<int>> &grid)
    {

        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, 0)));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i == j)
                    dp[n - 1][i][j] = grid[n - 1][i];
                else
                    dp[n - 1][i][j] = grid[n - 1][i] + grid[n - 1][j];
            }
        }

        for (int i = n - 2; i >= 0; i--)
        {
            for (int j1 = 0; j1 < m; j1++)
            {
                for (int j2 = 0; j2 < m; j2++)
                {
                    int tempAns1 = 0;
                    if (j1 == j2)
                    {
                        tempAns1 = grid[i][j2];
                    }
                    else
                    {
                        tempAns1 = grid[i][j1] + grid[i][j2];
                    }
                    int tempAns2 = 0;
                    int delta[] = {-1, 0, 1};
                    for (int d1 = 0; d1 < 3; d1++)
                    {
                        for (int d2 = 0; d2 < 3; d2++)
                        {
                            int dj1 = j1 + delta[d1], dj2 = j2 + delta[d2];
                            if (dj1 >= m || dj2 >= m || dj1 < 0 || dj2 < 0)
                                continue;
                            tempAns2 = max(dp[i + 1][dj1][dj2], tempAns2);
                        }
                    }

                    dp[i][j1][j2] = tempAns1 + tempAns2;
                }
            }
        }
        return dp[0][0][m - 1];
    }
};

// top-down
class Solution
{
public:
    int solve(vector<vector<int>> &grid, int i, int j1, int j2, vector<vector<vector<int>>> &dp)
    {
        int n = grid.size(), m = grid[0].size();
        if (i >= n || j1 >= m || j2 >= m || j1 < 0 || j2 < 0)
            return 0;
        if (dp[i][j1][j2] != -1)
            return dp[i][j1][j2];

        int tempAns1 = 0;
        if (j1 == j2)
        {
            tempAns1 = grid[i][j2];
        }
        else
        {
            tempAns1 = grid[i][j1] + grid[i][j2];
        }

        int delta[] = {-1, 0, 1};
        int tempAns2 = INT_MIN;
        for (int d1 = 0; d1 < 3; d1++)
        {
            for (int d2 = 0; d2 < 3; d2++)
            {
                tempAns2 = max(solve(grid, i + 1, j1 + delta[d1], j2 + delta[d2], dp), tempAns2);
            }
        }

        dp[i][j1][j2] = tempAns1 + tempAns2;
        return dp[i][j1][j2];
    }

    int cherryPickup(vector<vector<int>> &grid)
    {

        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
        return solve(grid, 0, 0, m - 1, dp);
    }
};

// recursive
class Solution
{
public:
    int solve(vector<vector<int>> &grid, int i, int j1, int j2)
    {
        int n = grid.size(), m = grid[0].size();
        if (i >= n || j1 >= m || j2 >= m || j1 < 0 || j2 < 0)
            return 0;

        int tempAns1 = 0;
        if (j1 == j2)
        {
            tempAns1 = grid[i][j2];
        }
        else
        {
            tempAns1 = grid[i][j1] + grid[i][j2];
        }

        int delta[] = {-1, 0, 1};
        int tempAns2 = INT_MIN;
        for (int d1 = 0; d1 < 3; d1++)
        {
            for (int d2 = 0; d2 < 3; d2++)
            {
                tempAns2 = max(solve(grid, i + 1, j1 + delta[d1], j2 + delta[d2]), tempAns2);
            }
        }

        return tempAns1 + tempAns2;
    }
    int cherryPickup(vector<vector<int>> &grid)
    {

        int m = grid[0].size();
        return solve(grid, 0, 0, m - 1);
    }
};