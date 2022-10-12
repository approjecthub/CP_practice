// https://practice.geeksforgeeks.org/problems/find-whether-path-exist5238/1

bool isValid(int r, int c, vector<vector<int>> &isVisited)
{
    int n = isVisited.size(), m = isVisited[0].size();
    return r >= 0 && r < n && c >= 0 && c < m && isVisited[r][c] == 0;
}
bool is_Possible(vector<vector<int>> &grid)
{
    // code here
    queue<vector<int>> que;
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> isVisited(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
            {
                isVisited[i][j] = 1;
                que.push({i, j});
            }
            else if (grid[i][j] == 0)
            {
                isVisited[i][j] = 1;
            }
        }
    }

    vector<int> rowOffset = {0, 0, 1, -1};
    vector<int> colOffset = {1, -1, 0, 0};
    while (que.size() > 0)
    {
        vector<int> v = que.front();
        que.pop();
        int r = v[0], c = v[1];
        // cout<<r<<","<<c<<endl;
        for (int i = 0; i < 4; i++)
        {
            int r1 = r + rowOffset[i];
            int c1 = c + colOffset[i];
            // cout<<"adj: "<<r1<<","<<c1<<endl;
            if (isValid(r1, c1, isVisited))
            {
                // cout<<"ok"<<endl;
                if (grid[r1][c1] == 2)
                {
                    return 1;
                }
                isVisited[r1][c1] = 1;
                que.push({r1, c1});
            }
        }
    }

    return 0;
}