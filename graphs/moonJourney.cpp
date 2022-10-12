//https://www.hackerrank.com/challenges/journey-to-the-moon/problem

int BFS(unordered_map<int, vector<int>> &umap, vector<bool> &visit, int i)
{
    queue<int> que;
    que.push(i);
    visit[i] = true;
    int c = 0;
    while (que.size() > 0)
    {
        int node = que.front();
        c++;
        que.pop();

        for (auto it : umap[node])
        {
            if (!visit[it])
            {
                visit[it] = true;
                que.push(it);
            }
        }
    }

    return c;
}
int journeyToMoon(int n, vector<vector<int>> astronaut)
{
    vector<bool> visit(n, false);
    unordered_map<int, vector<int>> umap;
    for (auto it : astronaut)
    {
        umap[it[0]].push_back(it[1]);
        umap[it[1]].push_back(it[0]);
    }

    int temp = 0;
    for (int i = 0; i < n; i++)
    {
        if (!visit[i])
        {
            int c = BFS(umap, visit, i);
            temp += (c * (c - 1)) / 2;
        }
    }
    int total = n * (n - 1) / 2;
    return total - temp;
}