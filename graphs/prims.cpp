// https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1

// TC: O(n^2), SC: O(n)
int spanningTree(int V, vector<vector<int>> adj[])
{
    // code here
    vector<int> key(V, INT_MAX);
    vector<int> mst(V, false);
    vector<int> parent(V, -1);

    key[0] = 0;
    for (int i = 0; i < V - 1; i++)
    {
        int node, minDis = INT_MAX;
        for (int l = 0; l < V; l++)
        {
            if (key[l] < minDis && !mst[l])
            {
                node = l;
                minDis = key[l];
            }
        }
        mst[node] = true;

        for (auto it : adj[node])
        { // it[0]=adj node, it[1]=adj node's weight
            if (key[it[0]] > it[1] && !mst[it[0]])
            {
                key[it[0]] = it[1];
                parent[it[0]] = node;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < V; i++)
    {
        ans += key[i];
    }

    return ans;
}

//  TC: ElogV

int spanningTree(int V, vector<vector<int>> adj[])
{
    // code here
    int ans = 0;
    set<pair<int, int>> key;
    vector<int> mst(V, false);
    vector<int> weight(V, INT_MAX);

    key.insert({0, 0});
    weight[0] = 0;

    for (int i = 0; i < V - 1; i++)
    {
        auto top = key.begin();
        int node = top->second;
        key.erase(top);
        mst[node] = true;

        for (auto it : adj[node])
        { // it[0]=adj node, it[1]=adj node's weight

            if (weight[it[0]] > it[1] && !mst[it[0]])
            {

                auto adjNodeP = key.find({weight[it[0]], it[0]});
                if (adjNodeP != key.end())
                {
                    key.erase(adjNodeP);
                }
                weight[it[0]] = it[1];
                key.insert({it[1], it[0]});
            }
        }
    }

    for (int i = 0; i < V; i++)
    {
        ans += weight[i];
    }

    return ans;
}