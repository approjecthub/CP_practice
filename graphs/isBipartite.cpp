// https://leetcode.com/problems/is-graph-bipartite/

class Solution
{
public:
    bool isBipartite(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<int> colours(n, -1);

        for (int i = 0; i < n; i++)
        {
            if (colours[i] == -1)
            {
                queue<int> q;
                colours[i] = 0;
                q.push(i);
                while (q.size() > 0)
                {
                    int node = q.front();
                    q.pop();
                    // cout<<"node col: "<<colours[node]<<endl;
                    for (auto it : graph[node])
                    {
                        // cout<<"adj col: "<<colours[it]<<endl;
                        if (colours[it] == -1)
                        {
                            colours[it] = !colours[node];
                            q.push(it);
                        }
                        else if (colours[it] == colours[node])
                        {
                            return false;
                        }
                    }
                }
            }
        }

        return true;
    }
};

// https://practice.geeksforgeeks.org/problems/bipartite-graph/1
bool BFS(int src, vector<int> adj[], vector<int> &colour)
{
    queue<int> que;

    que.push(src);
    colour[src] = 0;

    while (que.size() > 0)
    {
        int node = que.front();
        que.pop();
        for (int adjNode : adj[node])
        {
            if (colour[adjNode] == -1)
            {
                colour[adjNode] = !colour[node];
                que.push(adjNode);
            }
            else
            {
                if (colour[adjNode] == colour[node])
                {
                    return false;
                }
            }
        }
    }

    return true;
}
bool isBipartite(int V, vector<int> adj[])
{
    // Code here
    vector<int> colour(V, -1);

    bool ans = true;
    for (int i = 0; i < V; i++)
    {
        if (colour[i] == -1)
        {
            ans = ans && BFS(i, adj, colour);
        }
    }

    return ans;
}