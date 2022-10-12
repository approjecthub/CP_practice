// https://practice.geeksforgeeks.org/problems/find-number-of-closed-islands/1

void BFS(vector<vector<int>> &grid, int r, int c, int num)
{
    int n = grid.size();
    int m = grid[0].size();
    queue<pair<int, int>> q;

    q.push({r, c});
    grid[r][c] = -1;

    vector<int> rd = {0, 0, 1, -1};
    vector<int> cd = {1, -1, 0, 0};

    while (!q.empty())
    {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();

        for (int l = 0; l < 4; l++)
        {
            int fi = i + rd[l];
            int fj = j + cd[l];

            if (fi >= 0 && fj >= 0 && fi < n && fj < m)
            {
                if (grid[fi][fj] == num)
                {
                    grid[fi][fj] = -1;
                    q.push({fi, fj});
                }
            }
        }
    }
}

int closedIslands(vector<vector<int>> &matrix, int N, int M)
{
    // Code here
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if ((i == 0 || j == 0 || i == N - 1 || j == M - 1) && matrix[i][j] != -1)
            {
                BFS(matrix, i, j, matrix[i][j]);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (i == 0 || j == 0)
                continue;
            if (matrix[i][j] == 1)
            {
                ans++;
                BFS(matrix, i, j, 1);
            }
        }
    }

    return ans;
}