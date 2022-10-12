// https://practice.geeksforgeeks.org/problems/rotten-oranges2536/1

bool isValid(int r, int c, vector<vector<int>> &isVisited)
{
    int n = isVisited.size(), m = isVisited[0].size();
    return r >= 0 && r < n && c >= 0 && c < m && isVisited[r][c] == 0;
}
int orangesRotting(vector<vector<int>> &grid)
{
    // Code here
    queue<vector<int>> que;
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> isVisited(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 2)
            {
                isVisited[i][j] = 1;
                que.push({i, j, 0});
            }
            else if (grid[i][j] == 0)
            {
                isVisited[i][j] = 1;
            }
        }
    }

    int maxTime = 0;
    vector<int> rowOffset = {0, 0, 1, -1};
    vector<int> colOffset = {1, -1, 0, 0};
    while (que.size() > 0)
    {
        vector<int> v = que.front();
        que.pop();
        int r = v[0], c = v[1], time = v[2];
        maxTime = max(maxTime, time);

        for (int i = 0; i < 4; i++)
        {
            int r1 = r + rowOffset[i];
            int c1 = c + colOffset[i];

            if (isValid(r1, c1, isVisited))
            {
                isVisited[r1][c1] = 1;
                que.push({r1, c1, time + 1});
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!isVisited[i][j])
                return -1;
        }
    }

    return maxTime;
}