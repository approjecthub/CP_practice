// https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

#include <bits/stdc++.h>

using namespace std;

vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    // Code here
    set<pair<int, int>> s;
    vector<int> dist(V, INT_MAX);

    s.insert({0, S});
    dist[S] = 0;

    while (s.size() > 0)
    {
        auto top = s.begin();
        int node = top->second;
        int distTillNode = top->first;
        s.erase(top);

        for (int i = 0; i < adj[node].size(); i++)
        {
            int adjNode = adj[node][i][0];
            int distFromNode = adj[node][i][1];
            int distTillAdj = distTillNode + distFromNode;

            if (distTillAdj < dist[adjNode])
            {
                auto it = s.find({dist[adjNode], adjNode});
                if (it != s.end())
                {
                    s.erase(it);
                }
                dist[adjNode] = distTillAdj;
                s.insert({distTillAdj, adjNode});
            }
        }
    }

    return dist;
}