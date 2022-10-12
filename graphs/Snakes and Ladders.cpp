// https://leetcode.com/problems/snakes-and-ladders/

class Solution
{
public:
    bool checkVisit(vector<vector<int>> &visit, int i, int j, int n)
    {
        return (i >= n || i < 0 || j >= n || j < 0 || visit[i][j] > 0);
    }
    pair<int, int> getRowCol(int i, int n)
    {
        int row, col;
        int div = i / n, rem = i % n;
        row = n - div - 1;
        if (div % 2 == 0)
        {
            col = rem;
        }
        else
        {
            col = n - rem - 1;
        }
        return {row, col};
    }

    int snakesAndLadders(vector<vector<int>> &board)
    {
        int n = board.size();
        vector<vector<int>> visit(n, vector<int>(n, 0));

        int src = 0, dest = (n * n) - 1;
        queue<pair<int, int>> q;
        q.push({src, 0});
        pair<int, int> p = getRowCol(src, n);
        visit[p.first][p.second] = 1;
        int ans = INT_MAX;

        while (!q.empty())
        {
            pair<int, int> front = q.front();

            if (front.first == (n * n) - 1)
            {
                ans = min(ans, front.second);
            }
            q.pop();
            for (int i = front.first + 1; i <= front.first + 6 && i < (n * n); i++)
            {
                p = getRowCol(i, n);
                int dst = i;
                if (board[p.first][p.second] != -1)
                {
                    dst = board[p.first][p.second] - 1;
                    p = getRowCol(dst, n);
                }
                if (!checkVisit(visit, p.first, p.second, n))
                {
                    visit[p.first][p.second] = 1;
                    q.push({dst, front.second + 1});
                }
            }
        }
        if (ans == INT_MAX)
            return -1;
        return ans;
    }
};

// https://practice.geeksforgeeks.org/problems/snake-and-ladder-problem4816/1

int minThrow(int N, int arr[])
{
    // code here
    unordered_map<int, int> umap;
    for (int i = 0; i < 2 * N; i += 2)
    {
        umap[arr[i]] = arr[i + 1];
    }
    queue<pair<int, int>> que;
    vector<bool> isVisited(31, false);

    int src = 1, dst = 30;
    que.push({src, 0});
    isVisited[src] = true;
    while (que.size() > 0)
    {
        pair<int, int> nodeP = que.front();
        que.pop();
        int node = nodeP.first;
        int level = nodeP.second;
        if (node == dst)
        {
            return level;
        }

        for (int i = 1; i <= 6; i++)
        {
            int adjNode = node + i;
            if (umap.find(adjNode) != umap.end())
            {
                adjNode = umap[adjNode];
            }
            if (adjNode <= dst && !isVisited[adjNode])
            {
                isVisited[adjNode] = true;
                que.push({adjNode, level + 1});
            }
        }
    }

    return -1;
}