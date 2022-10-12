// https://practice.geeksforgeeks.org/problems/bridge-edge-in-graph/1

void DFS(int parent, int node, int &count,
         vector<int> adj[], vector<int> &strt, vector<int> &end, vector<pair<int, int>> &ans)
{

    strt[node] = count;
    end[node] = count;

    for (int i = 0; i < adj[node].size(); i++)
    {
        int adjNode = adj[node][i];
        if (strt[adjNode] == -1)
        {
            count++;
            DFS(node, adjNode, count, adj, strt, end, ans);
        }
        if (strt[node] < end[adjNode])
        {
            ans.push_back({node, adjNode});
        }
    }

    for (int i = 0; i < adj[node].size(); i++)
    {
        int adjNode = adj[node][i];
        if (parent != adjNode)
        {
            end[node] = min(end[node], end[adjNode]);
        }
    }
}
int isBridge(int V, vector<int> adj[], int c, int d)
{
    // Code here
    vector<int> strt(V, -1);
    vector<int> end(V, -1);
    vector<pair<int, int>> ans;
    int src = c;
    int count = 1;

    DFS(-1, src, count, adj, strt, end, ans);
    for (auto it : ans)
    {
        // cout<<it.first<<","<<it.second<<endl;
        if (it.first == c && it.second == d)
        {
            return 1;
        }
    }

    return 0;
}