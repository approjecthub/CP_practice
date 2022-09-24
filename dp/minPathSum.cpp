// https://leetcode.com/problems/minimum-path-sum/

class Solution
{
public:
    int solve(vector<vector<int>> &grid, int r, int c)
    {
        //         if(r==0 && c==0) return grid[r][c];
        //         else if(r<0 || c<0) return -1;
        //         else{
        //             int uSol = solve(grid, r-1, c);
        //             int lSol = solve(grid, r, c-1);

        //             if(uSol>-1 && lSol>-1) return grid[r][c]+min(uSol, lSol);
        //             else if(uSol>-1) return grid[r][c]+uSol;
        //             else return grid[r][c]+lSol;
        //         }

        vector<vector<int>> dp(r, vector<int>(c, 0));

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {

                int lSol = -1, uSol = -1;
                if (j > 0)
                {
                    lSol = dp[i][j - 1];
                }
                if (i > 0)
                {
                    uSol = dp[i - 1][j];
                }

                int prev = 0;
                if (lSol > -1 && uSol > -1)
                {
                    prev = min(lSol, uSol);
                }
                else if (lSol > -1)
                {
                    prev = lSol;
                }
                else if (uSol > -1)
                {
                    prev = uSol;
                }

                dp[i][j] = grid[i][j] + prev;
            }
        }
        return dp[r - 1][c - 1];
    }

    int minPathSum(vector<vector<int>> &grid)
    {
        int r = grid.size(), c = grid[0].size();
        return solve(grid, r, c);
    }
};