bool DFS(unordered_map<int, vector<int>> &g, unordered_map<int, bool> &visited, int src)
{
    visited[src] = true;
    bool ans = false;
    for (auto x : g[src])
    {
        if (visited[x])
        {
            return true;
        }
        else
        {
            ans = ans || DFS(g, visited, x);
            if (ans)
                return true;
        }
    }
    visited[src] = false;
    return ans;
}
bool contains_cycle(int, vector<pair<int, int>> edges)
{
    // Complete this method
    unordered_map<int, vector<int>> g;
    unordered_map<int, bool> visited;
    for (auto p : edges)
    {
        g[p.first].push_back(p.second);
        visited[p.first] = false;
    }
    return DFS(g, visited, edges[0].first);
}

// https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
// cycle detection using topological sort
bool isCyclic(int V, vector<int> adj[])
{
    // code here
    vector<int> in(V, 0);
    queue<int> que;

    for (int i = 0; i < V; i++)
    {
        for (int l = 0; l < adj[i].size(); l++)
        {
            in[adj[i][l]]++;
        }
    }

    for (int i = 0; i < V; i++)
    {
        if (in[i] == 0)
        {
            que.push(i);
        }
    }

    while (que.size() > 0)
    {
        int node = que.front();
        que.pop();
        for (int adjNode : adj[node])
        {
            in[adjNode]--;
            if (in[adjNode] == 0)
            {
                que.push(adjNode);
            }
        }
    }

    for (int i = 0; i < V; i++)
    {
        if (in[i] > 0)
        {
            return true;
        }
    }

    return false;
}