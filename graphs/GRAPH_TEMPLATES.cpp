#include <bits/stdc++.h>
using namespace std;

// ============================================
// GRAPH ALGORITHM CODE TEMPLATES
// Quick copy-paste templates for each pattern
// ============================================

// ============================================
// PATTERN 1: BFS on Matrix (Grid Traversal)
// ============================================
namespace GridBFS {
    bool isValid(int i, int j, int m, int n, vector<vector<int>>& grid, vector<vector<bool>>& visited) {
        return i >= 0 && i < m && j >= 0 && j < n && !visited[i][j];
    }

    void BFS(vector<vector<int>>& grid, int sr, int sc) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int offsets[] = {0, 1, 0, -1, 0}; // 4-directional

        q.push({sr, sc});
        visited[sr][sc] = true;

        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int ni = i + offsets[k];
                int nj = j + offsets[k + 1];

                if (isValid(ni, nj, m, n, grid, visited)) {
                    visited[ni][nj] = true;
                    q.push({ni, nj});
                }
            }
        }
    }
}

// ============================================
// PATTERN 2: Multi-Source BFS
// ============================================
namespace MultiSourceBFS {
    int solve(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<vector<int>> q; // {row, col, time}
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int offsets[] = {0, 1, 0, -1, 0};

        // Add all sources to queue
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == SOURCE_VALUE) {
                    q.push({i, j, 0});
                    visited[i][j] = true;
                }
            }
        }

        int maxTime = 0;
        while (!q.empty()) {
            auto v = q.front();
            q.pop();
            int r = v[0], c = v[1], time = v[2];
            maxTime = max(maxTime, time);

            for (int k = 0; k < 4; k++) {
                int nr = r + offsets[k];
                int nc = c + offsets[k + 1];

                if (nr >= 0 && nr < m && nc >= 0 && nc < n && !visited[nr][nc]) {
                    visited[nr][nc] = true;
                    q.push({nr, nc, time + 1});
                }
            }
        }
        return maxTime;
    }
}

// ============================================
// PATTERN 3: Simple BFS (Unweighted Shortest Path)
// ============================================
namespace SimpleBFS {
    int shortestPath(vector<int> adj[], int n, int src, int dest) {
        queue<pair<int, int>> q; // {node, distance}
        vector<bool> visited(n, false);

        q.push({src, 0});
        visited[src] = true;

        while (!q.empty()) {
            auto [node, dist] = q.front();
            q.pop();

            if (node == dest) return dist;

            for (auto adjNode : adj[node]) {
                if (!visited[adjNode]) {
                    visited[adjNode] = true;
                    q.push({adjNode, dist + 1});
                }
            }
        }
        return -1; // Not reachable
    }
}

// ============================================
// PATTERN 4: Dijkstra (Weighted Shortest Path)
// ============================================
namespace DijkstraAlgorithm {
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int src) {
        set<pair<int, int>> st; // {distance, node}
        vector<int> dist(V, INT_MAX);

        st.insert({0, src});
        dist[src] = 0;

        while (!st.empty()) {
            auto top = st.begin();
            int node = top->second;
            int d = top->first;
            st.erase(top);

            for (auto& edge : adj[node]) {
                int adjNode = edge[0];
                int weight = edge[1];
                int newDist = d + weight;

                if (newDist < dist[adjNode]) {
                    auto it = st.find({dist[adjNode], adjNode});
                    if (it != st.end()) st.erase(it);

                    dist[adjNode] = newDist;
                    st.insert({newDist, adjNode});
                }
            }
        }
        return dist;
    }
}

// ============================================
// PATTERN 5A: Topological Sort (DFS + Stack)
// ============================================
namespace TopoSortDFS {
    void DFS(int node, vector<int> adj[], vector<bool>& visited, stack<int>& st) {
        visited[node] = true;

        for (auto adjNode : adj[node]) {
            if (!visited[adjNode]) {
                DFS(adjNode, adj, visited, st);
            }
        }
        st.push(node); // Push AFTER exploring all neighbors
    }

    vector<int> topoSort(int V, vector<int> adj[]) {
        stack<int> st;
        vector<bool> visited(V, false);

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                DFS(i, adj, visited, st);
            }
        }

        vector<int> result;
        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }
        return result;
    }
}

// ============================================
// PATTERN 5B: Topological Sort (Kahn's Algorithm - BFS)
// ============================================
namespace KahnsAlgorithm {
    vector<int> topoSort(int V, vector<int> adj[]) {
        vector<int> indegree(V, 0);
        queue<int> q;

        // Calculate indegree
        for (int i = 0; i < V; i++) {
            for (auto adjNode : adj[i]) {
                indegree[adjNode]++;
            }
        }

        // Push nodes with 0 indegree
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> result;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            result.push_back(node);

            for (auto adjNode : adj[node]) {
                if (--indegree[adjNode] == 0) {
                    q.push(adjNode);
                }
            }
        }

        // If result.size() != V, cycle exists
        return result;
    }

    // Cycle detection using Kahn's
    bool hasCycle(int V, vector<int> adj[]) {
        return topoSort(V, adj).size() != V;
    }
}

// ============================================
// PATTERN 6A: Cycle Detection (Directed Graph - DFS)
// ============================================
namespace CycleDetectionDirected {
    bool DFS(int node, vector<int> adj[], vector<bool>& visited, vector<bool>& recStack) {
        visited[node] = true;
        recStack[node] = true;

        for (auto adjNode : adj[node]) {
            if (!visited[adjNode]) {
                if (DFS(adjNode, adj, visited, recStack)) {
                    return true;
                }
            } else if (recStack[adjNode]) {
                return true; // Back edge found
            }
        }

        recStack[node] = false;
        return false;
    }

    bool hasCycle(int V, vector<int> adj[]) {
        vector<bool> visited(V, false);
        vector<bool> recStack(V, false);

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (DFS(i, adj, visited, recStack)) {
                    return true;
                }
            }
        }
        return false;
    }
}

// ============================================
// PATTERN 6B: Cycle Detection (Undirected Graph - DFS)
// ============================================
namespace CycleDetectionUndirected {
    bool DFS(int node, int parent, vector<int> adj[], vector<bool>& visited) {
        visited[node] = true;

        for (auto adjNode : adj[node]) {
            if (!visited[adjNode]) {
                if (DFS(adjNode, node, adj, visited)) {
                    return true;
                }
            } else if (adjNode != parent) {
                return true; // Cycle found
            }
        }
        return false;
    }

    bool hasCycle(int V, vector<int> adj[]) {
        vector<bool> visited(V, false);

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (DFS(i, -1, adj, visited)) {
                    return true;
                }
            }
        }
        return false;
    }
}

// ============================================
// PATTERN 7: Bipartite Check (2-Coloring)
// ============================================
namespace BipartiteCheck {
    bool BFS(int src, vector<int> adj[], vector<int>& color) {
        queue<int> q;
        q.push(src);
        color[src] = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto adjNode : adj[node]) {
                if (color[adjNode] == -1) {
                    color[adjNode] = !color[node];
                    q.push(adjNode);
                } else if (color[adjNode] == color[node]) {
                    return false; // Not bipartite
                }
            }
        }
        return true;
    }

    bool isBipartite(int V, vector<int> adj[]) {
        vector<int> color(V, -1);

        for (int i = 0; i < V; i++) {
            if (color[i] == -1) {
                if (!BFS(i, adj, color)) {
                    return false;
                }
            }
        }
        return true;
    }
}

// ============================================
// PATTERN 8: Prim's MST (Using Set - Optimized)
// ============================================
namespace PrimsMST {
    int spanningTree(int V, vector<vector<int>> adj[]) {
        set<pair<int, int>> st; // {weight, node}
        vector<bool> inMST(V, false);
        vector<int> key(V, INT_MAX);

        st.insert({0, 0});
        key[0] = 0;

        for (int i = 0; i < V - 1; i++) {
            auto top = st.begin();
            int node = top->second;
            int weight = top->first;
            st.erase(top);
            inMST[node] = true;

            for (auto& edge : adj[node]) {
                int adjNode = edge[0];
                int edgeWeight = edge[1];

                if (!inMST[adjNode] && edgeWeight < key[adjNode]) {
                    auto it = st.find({key[adjNode], adjNode});
                    if (it != st.end()) st.erase(it);

                    key[adjNode] = edgeWeight;
                    st.insert({edgeWeight, adjNode});
                }
            }
        }

        int mstWeight = 0;
        for (int i = 0; i < V; i++) {
            mstWeight += key[i];
        }
        return mstWeight;
    }
}

// ============================================
// PATTERN 9: Kosaraju's SCC Algorithm
// ============================================
namespace KosarajuSCC {
    void DFS1(int node, vector<int> adj[], vector<bool>& visited, stack<int>& st) {
        visited[node] = true;
        for (auto adjNode : adj[node]) {
            if (!visited[adjNode]) {
                DFS1(adjNode, adj, visited, st);
            }
        }
        st.push(node);
    }

    void DFS2(int node, vector<int> transposed[], vector<bool>& visited) {
        visited[node] = true;
        for (auto adjNode : transposed[node]) {
            if (!visited[adjNode]) {
                DFS2(adjNode, transposed, visited);
            }
        }
    }

    int kosaraju(int V, vector<int> adj[]) {
        // Step 1: DFS to fill stack
        stack<int> st;
        vector<bool> visited(V, false);
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                DFS1(i, adj, visited, st);
            }
        }

        // Step 2: Transpose the graph
        vector<int> transposed[V];
        for (int i = 0; i < V; i++) {
            visited[i] = false; // Reset visited
            for (auto adjNode : adj[i]) {
                transposed[adjNode].push_back(i);
            }
        }

        // Step 3: DFS on transposed graph in stack order
        int sccCount = 0;
        while (!st.empty()) {
            int node = st.top();
            st.pop();
            if (!visited[node]) {
                DFS2(node, transposed, visited);
                sccCount++;
            }
        }

        return sccCount;
    }
}

// ============================================
// PATTERN 10: Tarjan's Bridge Detection
// ============================================
namespace TarjanBridge {
    void DFS(int node, int parent, int& timer, vector<int> adj[],
             vector<int>& disc, vector<int>& low, vector<pair<int, int>>& bridges) {
        disc[node] = low[node] = timer++;

        for (auto adjNode : adj[node]) {
            if (disc[adjNode] == -1) {
                DFS(adjNode, node, timer, adj, disc, low, bridges);
                low[node] = min(low[node], low[adjNode]);

                if (low[adjNode] > disc[node]) {
                    bridges.push_back({node, adjNode});
                }
            } else if (adjNode != parent) {
                low[node] = min(low[node], disc[adjNode]);
            }
        }
    }

    vector<pair<int, int>> findBridges(int V, vector<int> adj[]) {
        vector<int> disc(V, -1);
        vector<int> low(V, -1);
        vector<pair<int, int>> bridges;
        int timer = 0;

        for (int i = 0; i < V; i++) {
            if (disc[i] == -1) {
                DFS(i, -1, timer, adj, disc, low, bridges);
            }
        }

        return bridges;
    }
}

// ============================================
// PATTERN 11: Graph Cloning (BFS)
// ============================================
namespace GraphClone {
    struct Node {
        int val;
        vector<Node*> neighbors;
        Node(int v) : val(v) {}
    };

    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;

        unordered_map<int, Node*> nodeMap;
        queue<Node*> q;

        nodeMap[node->val] = new Node(node->val);
        q.push(node);

        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();

            for (auto neighbor : curr->neighbors) {
                if (nodeMap.find(neighbor->val) == nodeMap.end()) {
                    nodeMap[neighbor->val] = new Node(neighbor->val);
                    q.push(neighbor);
                }
                nodeMap[curr->val]->neighbors.push_back(nodeMap[neighbor->val]);
            }
        }

        return nodeMap[node->val];
    }
}

// ============================================
// UTILITY: Common Helper Functions
// ============================================
namespace Utils {
    // Direction offsets for 4-directional movement
    int dx4[] = {0, 0, 1, -1};
    int dy4[] = {1, -1, 0, 0};

    // Direction offsets for 8-directional movement
    int dx8[] = {0, 0, 1, -1, 1, 1, -1, -1};
    int dy8[] = {1, -1, 0, 0, 1, -1, 1, -1};

    // Knight moves
    int knightX[] = {2, 1, -1, -2, -2, -1, 1, 2};
    int knightY[] = {1, 2, 2, 1, -1, -2, -2, -1};

    // Check if (x, y) is valid in m x n grid
    bool isValid(int x, int y, int m, int n) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }
}

int main() {
    // Test your implementations here
    return 0;
}
