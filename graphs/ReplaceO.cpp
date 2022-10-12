// https://practice.geeksforgeeks.org/problems/replace-os-with-xs0052/1

bool isValid(int r, int c, vector<vector<char>> &mat)
{
    int n = mat.size(), m = mat[0].size();
    return r >= 0 && r < n && c >= 0 && c < m && mat[r][c] == 'O';
}

vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
{
    // code here
    queue<vector<int>> que;
    for (int i = 0; i < m; i++)
    {
        if (mat[0][i] == 'O')
        {
            mat[0][i] = 'Y';
            que.push({0, i});
        }

        if (mat[n - 1][i] == 'O')
        {
            mat[n - 1][i] = 'Y';
            que.push({n - 1, i});
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (mat[i][0] == 'O')
        {
            mat[i][0] = 'Y';
            que.push({i, 0});
        }

        if (mat[i][m - 1] == 'O')
        {
            mat[i][m - 1] = 'Y';
            que.push({i, m - 1});
        }
    }

    vector<int> rowOffset = {0, 0, 1, -1};
    vector<int> colOffset = {1, -1, 0, 0};
    while (que.size() > 0)
    {
        vector<int> v = que.front();
        que.pop();
        int r = v[0], c = v[1];

        for (int i = 0; i < 4; i++)
        {
            int r1 = r + rowOffset[i];
            int c1 = c + colOffset[i];
            // cout<<"adj: "<<r1<<","<<c1<<endl;
            if (isValid(r1, c1, mat))
            {
                // cout<<"ok"<<endl;
                mat[r1][c1] = 'Y';
                que.push({r1, c1});
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == 'O')
            {
                mat[i][j] = 'X';
            }
            else if (mat[i][j] == 'Y')
            {
                mat[i][j] = 'O';
            }
        }
    }

    return mat;
}