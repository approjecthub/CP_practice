bool contains_cycle(int, vector<pair<int, int>> edges)
{

    queue<pair<int, int>> q;
    unordered_map<int, vector<int>> g;
    unordered_map<int, bool> visited;
    for (auto p : edges)
    {
        g[p.first].push_back(p.second);
        visited[p.first] = false;
    }

    q.push({edges[0].first, -1});
    visited[edges[0].first] = true;
    while (!q.empty())
    {
        auto p = q.front();
        // p.first => source node, p.second=> parent of the source
        q.pop();
        for (auto x : g[p.first])
        {
            if (visited[x] && x != p.second)
            {
                return true;
            }
            else if (!visited[x])
            {
                q.push({x, p.first});
            }
        }
    }
    return false;
}

// https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

bool solve(int src, int V, vector<int> adj[], vector<bool> &isVisited)
{
    queue<pair<int, int>> que;

    que.push({-1, src});
    isVisited[src] = true;

    while (que.size() > 0)
    {
        pair<int, int> topP = que.front();
        int parent = topP.first, node = topP.second;
        que.pop();

        for (auto it : adj[node])
        {
            if (isVisited[it])
            {
                if (it != parent)
                    return true;
            }
            else
            {
                isVisited[it] = true;
                que.push({node, it});
            }
        }
    }

    return false;
}
bool isCycle(int V, vector<int> adj[])
{
    // Code here
    vector<bool> isVisited(V, false);
    bool ans = false;
    for (int i = 0; i < V; i++)
    {
        if (!isVisited[i])
        {
            ans = ans || solve(i, V, adj, isVisited);
        }
    }
    return ans;
}