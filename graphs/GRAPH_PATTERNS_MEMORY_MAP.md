# Graph Patterns Memory Map

Quick reference guide for identifying and implementing graph problem patterns.

---

## Pattern 1: BFS/DFS on Matrix (Grid Traversal)

**When to use:**
- 2D grid/matrix given
- Need to explore connected cells
- Count islands/regions
- Flood fill problems

**Key Indicators:**
- Keywords: island, region, connected, flood fill, surrounded
- Matrix with 0s and 1s OR different cell types
- 4-directional or 8-directional movement

**Template:**
```cpp
// BFS approach
queue<pair<int,int>> q;
vector<vector<bool>> visited(m, vector<bool>(n, false));
int offsets[] = {0, 1, 0, -1, 0}; // direction offsets

// Check validity
bool isValid(int i, int j, int m, int n) {
    return i >= 0 && i < m && j >= 0 && j < n;
}

// BFS from (r, c)
while (!q.empty()) {
    auto [i, j] = q.front(); q.pop();
    for (int k = 0; k < 4; k++) {
        int ni = i + offsets[k];
        int nj = j + offsets[k+1];
        if (isValid(ni, nj, m, n) && !visited[ni][nj]) {
            visited[ni][nj] = true;
            q.push({ni, nj});
        }
    }
}
```

**Problems:**
- numberOfIslands.cpp
- Max Area of Island.cpp
- closedIsland.cpp
- floodFlll.cpp
- Surrounded Region.cpp
- ReplaceO.cpp

---

## Pattern 2: Multi-Source BFS

**When to use:**
- Multiple starting points simultaneously
- Need to find shortest time/distance from ANY source
- Problems with spreading/propagation

**Key Indicators:**
- Keywords: rotten, spreading, multi-source, simultaneously
- Start BFS from ALL sources at once
- Track levels/time

**Template:**
```cpp
queue<vector<int>> q; // {row, col, time/level}
// Push ALL sources into queue initially
for (each source) {
    q.push({r, c, 0});
    visited[r][c] = true;
}

int maxTime = 0;
while (!q.empty()) {
    auto v = q.front(); q.pop();
    int r = v[0], c = v[1], time = v[2];
    maxTime = max(maxTime, time);

    // Explore neighbors
    for (neighbors) {
        q.push({nr, nc, time + 1});
    }
}
```

**Problems:**
- rottenOranges.cpp

---

## Pattern 3: Shortest Path (Unweighted) - Simple BFS

**When to use:**
- Find shortest path/distance
- All edges have equal weight (unweighted)
- Single source shortest path

**Key Indicators:**
- Keywords: shortest path, minimum steps, level
- Unweighted graph or unit weights
- Need distance from source

**Template:**
```cpp
queue<pair<int, int>> q; // {node, distance}
vector<bool> visited(n, false);
q.push({src, 0});
visited[src] = true;

while (!q.empty()) {
    auto [node, dist] = q.front(); q.pop();
    if (node == target) return dist;

    for (auto adj : graph[node]) {
        if (!visited[adj]) {
            visited[adj] = true;
            q.push({adj, dist + 1});
        }
    }
}
```

**Problems:**
- wordLadder.cpp
- stepsByKnight.cpp
- Snakes and Ladders.cpp

---

## Pattern 4: Dijkstra (Weighted Shortest Path)

**When to use:**
- Find shortest path in WEIGHTED graph
- All weights are NON-NEGATIVE
- Single source shortest path

**Key Indicators:**
- Keywords: weighted, minimum cost, shortest path
- Edge weights provided
- Need to minimize total weight

**Template:**
```cpp
set<pair<int, int>> s; // {distance, node}
vector<int> dist(n, INT_MAX);
s.insert({0, src});
dist[src] = 0;

while (!s.empty()) {
    auto [d, node] = *s.begin();
    s.erase(s.begin());

    for (auto [adjNode, weight] : adj[node]) {
        int newDist = d + weight;
        if (newDist < dist[adjNode]) {
            auto it = s.find({dist[adjNode], adjNode});
            if (it != s.end()) s.erase(it);

            dist[adjNode] = newDist;
            s.insert({newDist, adjNode});
        }
    }
}
```

**Variations:**
- Modified distance calculation (max effort, probability)
- Matrix-based Dijkstra

**Problems:**
- dijkstra.cpp
- Network Delay Time.cpp
- Path With Minimum Effort.cpp (modified: max of path efforts)
- Path with Maximum Probability.cpp (modified: product instead of sum)

---

## Pattern 5: Topological Sort (DAG Ordering)

**When to use:**
- Directed Acyclic Graph (DAG)
- Need ordering where all dependencies come before
- Course scheduling, task ordering

**Key Indicators:**
- Keywords: schedule, order, dependencies, prerequisites
- Directed graph
- Need valid sequence

**Two Approaches:**

### A. DFS + Stack
```cpp
stack<int> st;
vector<bool> visited(n, false);

void DFS(int node, vector<int> adj[]) {
    visited[node] = true;
    for (auto adjNode : adj[node]) {
        if (!visited[adjNode]) {
            DFS(adjNode, adj);
        }
    }
    st.push(node); // Push after exploring all neighbors
}

// Call DFS for all unvisited nodes
// Result is in stack (pop to get topo order)
```

### B. Kahn's Algorithm (BFS + Indegree)
```cpp
vector<int> indegree(n, 0);
queue<int> q;

// Calculate indegree
for (int i = 0; i < n; i++) {
    for (auto adj : graph[i]) {
        indegree[adj]++;
    }
}

// Push nodes with 0 indegree
for (int i = 0; i < n; i++) {
    if (indegree[i] == 0) q.push(i);
}

while (!q.empty()) {
    int node = q.front(); q.pop();
    // Process node

    for (auto adj : graph[node]) {
        if (--indegree[adj] == 0) {
            q.push(adj);
        }
    }
}
```

**Problems:**
- topologicalSort.cpp
- courseSchedule.cpp (cycle detection using topo sort)
- alienDic.cpp (build graph from word order, then topo sort)

---

## Pattern 6: Cycle Detection

### A. Directed Graph Cycle Detection

**Two Approaches:**

**1. DFS with recursion stack:**
```cpp
vector<bool> visited(n, false);
vector<bool> recStack(n, false);

bool hasCycleDFS(int node) {
    visited[node] = true;
    recStack[node] = true;

    for (auto adj : graph[node]) {
        if (!visited[adj]) {
            if (hasCycleDFS(adj)) return true;
        } else if (recStack[adj]) {
            return true; // Back edge found
        }
    }

    recStack[node] = false;
    return false;
}
```

**2. Topological Sort (Kahn's):**
- If topo sort completes successfully → No cycle
- If indegree > 0 remains → Cycle exists

### B. Undirected Graph Cycle Detection

```cpp
bool hasCycleDFS(int node, int parent) {
    visited[node] = true;

    for (auto adj : graph[node]) {
        if (!visited[adj]) {
            if (hasCycleDFS(adj, node)) return true;
        } else if (adj != parent) {
            return true; // Cycle found
        }
    }
    return false;
}
```

**Problems:**
- CycleDetectionDirectedGraph.cpp
- CycleDetectionUndirectedGraph.cpp
- courseSchedule.cpp

---

## Pattern 7: Bipartite Check (2-Coloring)

**When to use:**
- Check if graph can be divided into 2 sets
- No edge within same set
- Graph coloring with 2 colors

**Key Indicators:**
- Keywords: bipartite, two groups, partition
- Need to check if alternate coloring possible

**Template:**
```cpp
vector<int> color(n, -1);
queue<int> q;

// For each component
for (int i = 0; i < n; i++) {
    if (color[i] == -1) {
        q.push(i);
        color[i] = 0;

        while (!q.empty()) {
            int node = q.front(); q.pop();

            for (auto adj : graph[node]) {
                if (color[adj] == -1) {
                    color[adj] = !color[node];
                    q.push(adj);
                } else if (color[adj] == color[node]) {
                    return false; // Not bipartite
                }
            }
        }
    }
}
return true;
```

**Problems:**
- isBipartite.cpp

---

## Pattern 8: Minimum Spanning Tree (MST)

**When to use:**
- Connect all nodes with minimum total edge weight
- Weighted undirected graph
- Need minimum cost to connect all

**Key Indicators:**
- Keywords: minimum cost, connect all, spanning tree
- Find subset of edges connecting all vertices

**Prim's Algorithm:**
```cpp
// Using set for optimization: O(E log V)
set<pair<int, int>> st; // {weight, node}
vector<bool> inMST(n, false);
vector<int> key(n, INT_MAX);

st.insert({0, 0});
key[0] = 0;
int ans = 0;

for (int i = 0; i < n-1; i++) {
    auto [weight, node] = *st.begin();
    st.erase(st.begin());
    inMST[node] = true;
    ans += weight;

    for (auto [adjNode, edgeWeight] : adj[node]) {
        if (!inMST[adjNode] && edgeWeight < key[adjNode]) {
            auto it = st.find({key[adjNode], adjNode});
            if (it != st.end()) st.erase(it);

            key[adjNode] = edgeWeight;
            st.insert({edgeWeight, adjNode});
        }
    }
}
```

**Problems:**
- prims.cpp
- connectPoints.cpp (MST on coordinate points)

---

## Pattern 9: Strongly Connected Components (SCC)

**When to use:**
- Find strongly connected components in directed graph
- Group of nodes where every node is reachable from every other

**Key Indicators:**
- Keywords: strongly connected, SCC
- Directed graph

**Kosaraju's Algorithm:**
```cpp
// Step 1: DFS to fill stack (finish times)
stack<int> st;
void DFS1(int node) {
    visited[node] = true;
    for (auto adj : graph[node]) {
        if (!visited[adj]) DFS1(adj);
    }
    st.push(node);
}

// Step 2: Transpose the graph
vector<int> transposed[n];
for (int i = 0; i < n; i++) {
    for (auto adj : graph[i]) {
        transposed[adj].push_back(i);
    }
}

// Step 3: DFS on transposed graph in stack order
int sccCount = 0;
while (!st.empty()) {
    int node = st.top(); st.pop();
    if (!visited[node]) {
        DFS2(node, transposed);
        sccCount++;
    }
}
```

**Problems:**
- kosarajuAlgo.cpp

---

## Pattern 10: Bridge Detection (Tarjan's Algorithm)

**When to use:**
- Find critical edges whose removal disconnects graph
- Bridge edges in undirected graph

**Key Indicators:**
- Keywords: bridge, critical connection, cut edge
- Need to find edges whose removal increases components

**Template:**
```cpp
vector<int> disc(n, -1), low(n, -1);
int timer = 0;

void DFS(int node, int parent) {
    disc[node] = low[node] = timer++;

    for (auto adj : graph[node]) {
        if (disc[adj] == -1) {
            DFS(adj, node);
            low[node] = min(low[node], low[adj]);

            if (low[adj] > disc[node]) {
                // Bridge found: node - adj
            }
        } else if (adj != parent) {
            low[node] = min(low[node], disc[adj]);
        }
    }
}
```

**Problems:**
- bridgeEdge.cpp

---

## Pattern 11: Graph Cloning

**When to use:**
- Deep copy a graph
- Clone with all connections preserved

**Template:**
```cpp
unordered_map<int, Node*> nodeMap;
queue<Node*> q;

Node* cloneGraph(Node* node) {
    if (!node) return nullptr;

    nodeMap[node->val] = new Node(node->val);
    q.push(node);

    while (!q.empty()) {
        Node* curr = q.front(); q.pop();

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
```

**Problems:**
- cloneGraph.cpp

---

## Quick Pattern Recognition Guide

| Problem Type | Algorithm | Time Complexity |
|--------------|-----------|-----------------|
| Unweighted shortest path | BFS | O(V + E) |
| Weighted shortest path (non-negative) | Dijkstra | O(E log V) |
| All pairs shortest path | Floyd-Warshall | O(V³) |
| Minimum spanning tree | Prim's/Kruskal | O(E log V) |
| Topological sort | DFS/Kahn's | O(V + E) |
| Cycle detection (directed) | DFS + rec stack / Kahn's | O(V + E) |
| Cycle detection (undirected) | DFS with parent | O(V + E) |
| Bipartite check | BFS/DFS 2-coloring | O(V + E) |
| Strongly connected components | Kosaraju's | O(V + E) |
| Bridge detection | Tarjan's | O(V + E) |
| Connected components | DFS/BFS | O(V + E) |

---

## Common Edge Cases to Remember

1. **Disconnected graphs**: Loop through all nodes
2. **Self loops**: Handle in cycle detection
3. **Multiple edges**: Use appropriate data structure
4. **Empty graph**: Check n == 0
5. **Single node**: Base case

---

## Data Structure Choices

| Need | Data Structure |
|------|----------------|
| Fast minimum extraction | `set<pair<int,int>>` or priority_queue |
| Visited tracking | `vector<bool>` or `unordered_set` |
| Graph representation | `vector<vector<int>>` (adjacency list) |
| Level order traversal | `queue` |
| Finish time ordering | `stack` |

---

## Revision Checklist

- [ ] Can identify BFS vs DFS use cases
- [ ] Know when to use Dijkstra vs BFS
- [ ] Understand topological sort (both methods)
- [ ] Can detect cycles in directed/undirected graphs
- [ ] Remember Kosaraju's three steps
- [ ] Know MST algorithms (Prim's/Kruskal)
- [ ] Understand bridge detection concept
- [ ] Can handle multi-source BFS
- [ ] Remember bipartite checking technique
- [ ] Comfortable with matrix-based graphs
