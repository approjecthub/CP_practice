// https://practice.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1

stack<int> st;
void DFS(int node, vector<int> adj[], vector<int> &isVisited, bool rev)
{
    isVisited[node] = 1;
    for (int i = 0; i < adj[node].size(); i++)
    {

        if (!isVisited[adj[node][i]])
        {
            DFS(adj[node][i], adj, isVisited, rev);
        }
    }

    if (!rev)
        st.push(node);
}
int kosaraju(int V, vector<int> adj[])
{
    // code here
    vector<int> isVisited(V, 0);

    // 1. topo sort
    for (int i = 0; i < V; i++)
    {
        if (!isVisited[i])
        {
            DFS(i, adj, isVisited, false);
        }
    }

    // 2. transpose the graph
    vector<int> transp[V];
    for (int i = 0; i < V; i++)
    {
        isVisited[i] = 0;
        for (int l = 0; l < adj[i].size(); l++)
        {
            transp[adj[i][l]].push_back(i);
        }
    }

    int ans = 0;
    // 3.apply dfs on transposed graph
    while (st.size() > 0)
    {
        int node = st.top();
        st.pop();
        if (!isVisited[node])
        {
            DFS(node, transp, isVisited, true);
            ans++;
        }
    }

    return ans;
}