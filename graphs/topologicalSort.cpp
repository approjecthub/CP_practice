// https://practice.geeksforgeeks.org/problems/topological-sort/1
// https://www.youtube.com/watch?v=Yh6EFazXipA&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=12

void DFS(int node, vector<int> adj[], vector<bool> &isVisited, stack<int> &st)
{
    isVisited[node] = true;
    for (int i = 0; i < adj[node].size(); i++)
    {
        if (!isVisited[adj[node][i]])
        {
            DFS(adj[node][i], adj, isVisited, st);
        }
    }
    st.push(node);
}
vector<int> topoSort(int V, vector<int> adj[])
{
    // code here
    stack<int> st;
    vector<bool> isVisited(V, false);
    for (int i = 0; i < V; i++)
    {
        if (!isVisited[i])
        {
            DFS(i, adj, isVisited, st);
        }
    }
    vector<int> ans;
    while (st.size() > 0)
    {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}