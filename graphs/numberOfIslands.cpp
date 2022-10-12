// https://leetcode.com/problems/number-of-islands/

class Solution
{
public:
    bool isValid(vector<vector<char>> &grid, int i, int j)
    {
        int m = grid.size(), n = grid[0].size();
        return i >= 0 && i < m && j >= 0 && j < n && grid[i][j] == '1';
    }
    void BFS(vector<vector<char>> &grid, int r, int c)
    {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;
        q.push({r, c});
        grid[r][c] = '0';

        while (!q.empty())
        {
            pair<int, int> p = q.front();
            int i = p.first;
            int j = p.second;
            q.pop();

            if (isValid(grid, i - 1, j))
            {
                grid[i - 1][j] = '0';
                q.push({i - 1, j});
            }
            if (isValid(grid, i + 1, j))
            {
                grid[i + 1][j] = '0';
                q.push({i + 1, j});
            }
            if (isValid(grid, i, j - 1))
            {
                grid[i][j - 1] = '0';
                q.push({i, j - 1});
            }
            if (isValid(grid, i, j + 1))
            {
                grid[i][j + 1] = '0';
                q.push({i, j + 1});
            }
        }
    }
    int numIslands(vector<vector<char>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        int offsets[] = {0, 1, 0, -1, 0};
        // vector<vector<bool>> isVisited(m, vector<bool>(n, false));
        int ans = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // cout<<"ok=>"<<i<<","<<j<<endl;
                if (grid[i][j] == '1')
                {
                    ans++;
                    BFS(grid, i, j);
                }
            }
        }

        return ans;
    }
};