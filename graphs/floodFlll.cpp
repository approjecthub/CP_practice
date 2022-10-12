//https://leetcode.com/problems/flood-fill/

class Solution
{
public:
    bool isValid(int r, int c, int parentColor, vector<vector<int>> &image)
    {
        int n = image.size(), m = image[0].size();
        return r >= 0 && r < n && c >= 0 && c < m && image[r][c] == parentColor;
    }
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        queue<vector<int>> que;
        int n = image.size(), m = image[0].size();
        que.push({sr, sc});
        int parentColor = image[sr][sc];
        image[sr][sc] = -1;
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
                if (isValid(r1, c1, parentColor, image))
                {
                    image[r1][c1] = -1;
                    que.push({r1, c1});
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (image[i][j] == -1)
                {
                    image[i][j] = newColor;
                }
            }
        }

        return image;
    }
};