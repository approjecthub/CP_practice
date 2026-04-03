# Master Quick Reference - All Patterns

🔥 **ONE-PAGE CHEAT SHEET** - Review 15 mins before interview

---

## Pattern Decision Tree

```
INPUT: Problem Statement
│
├─ Array/String?
│  ├─ Two elements? → Two Pointer
│  ├─ Subarray/substring? → Sliding Window
│  ├─ Max subarray sum? → Kadane's
│  ├─ Product except self? → Prefix/Suffix Product
│  └─ Find duplicate/missing? → Hash Map or XOR
│
├─ Tree?
│  ├─ Level-by-level? → BFS (queue)
│  ├─ Path related? → DFS (recursion)
│  ├─ BST property? → In-order traversal
│  └─ Bottom-up calculation? → Tree DP
│
├─ Graph?
│  ├─ Shortest path (unweighted)? → BFS
│  ├─ Shortest path (weighted)? → Dijkstra
│  ├─ All pairs shortest? → Floyd-Warshall
│  ├─ Connected components? → DFS/Union-Find
│  ├─ Cycle detection? → DFS (directed), Union-Find (undirected)
│  ├─ Topological sort? → Kahn's (BFS) or DFS
│  └─ MST? → Kruskal/Prim
│
├─ DP?
│  ├─ Choice at each step? → 0/1 Knapsack
│  ├─ Unlimited choices? → Unbounded Knapsack
│  ├─ Two sequences? → LCS pattern
│  ├─ One sequence increasing? → LIS pattern
│  ├─ String partition? → MCM pattern
│  ├─ Grid movement? → Grid DP
│  └─ State machine? → Buy/Sell Stock
│
├─ Linked List?
│  ├─ Cycle? → Floyd's (fast/slow)
│  ├─ Reverse? → Three pointers
│  ├─ Merge? → Two pointers
│  └─ Random pointer? → Hash map
│
├─ Stack/Queue?
│  ├─ Next greater/smaller? → Monotonic Stack
│  ├─ Expression? → Stack
│  └─ Stream processing? → Deque
│
├─ Backtracking?
│  ├─ All subsets? → Subsets pattern
│  ├─ All arrangements? → Permutations pattern
│  ├─ Choose k from n? → Combinations pattern
│  └─ Place on board? → N-Queens pattern
│
├─ Bit Manipulation?
│  ├─ Find unique? → XOR all
│  ├─ Count bits? → Brian Kernighan
│  ├─ Subsets? → Bit mask (2^n)
│  └─ Check power of 2? → n & (n-1) == 0
│
├─ Math/Geometry?
│  ├─ Matrix rotation? → Transpose + Reverse
│  ├─ Spiral? → 4 pointers (top/bottom/left/right)
│  ├─ Large numbers? → String math
│  └─ Fast power? → Binary exponentiation
│
├─ Greedy/Intervals?
│  ├─ Merge intervals? → Sort by start
│  ├─ Non-overlapping? → Sort by end
│  └─ Maximize meetings? → Activity selection
│
└─ Brute force? → Try all possibilities (may need optimization)
```

---

## Pattern Templates (Copy-Paste Ready)

### **Two Pointer**
```cpp
int left = 0, right = n - 1;
while (left < right) {
    if (condition) left++;
    else right--;
}
```

### **Sliding Window**
```cpp
int left = 0, maxLen = 0;
for (int right = 0; right < n; right++) {
    // Add right
    while (invalid) {
        // Remove left
        left++;
    }
    maxLen = max(maxLen, right - left + 1);
}
```

### **BFS (Tree/Graph)**
```cpp
queue<Node*> q;
q.push(root);
while (!q.empty()) {
    Node* curr = q.front(); q.pop();
    // Process curr
    for (auto neighbor : curr->neighbors) {
        q.push(neighbor);
    }
}
```

### **DFS (Tree/Graph)**
```cpp
void dfs(Node* node, unordered_set<Node*>& visited) {
    if (!node || visited.count(node)) return;
    visited.insert(node);
    for (auto neighbor : node->neighbors) {
        dfs(neighbor, visited);
    }
}
```

### **Binary Search**
```cpp
int left = 0, right = n - 1;
while (left <= right) {
    int mid = left + (right - left) / 2;
    if (arr[mid] == target) return mid;
    if (arr[mid] < target) left = mid + 1;
    else right = mid - 1;
}
```

### **DP (0/1 Knapsack)**
```cpp
dp[i][j] = max(dp[i-1][j], dp[i-1][j-wt[i]] + val[i]);
```

### **DP (Unbounded Knapsack)**
```cpp
dp[j] = max(dp[j], dp[j-wt[i]] + val[i]);
```

### **DP (LCS)**
```cpp
if (s1[i] == s2[j]) dp[i][j] = 1 + dp[i-1][j-1];
else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
```

### **DP (LIS)**
```cpp
for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
        if (arr[j] < arr[i]) {
            dp[i] = max(dp[i], dp[j] + 1);
        }
    }
}
```

### **Floyd's (Cycle Detection)**
```cpp
ListNode *slow = head, *fast = head;
while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast) return true; // Cycle detected
}
return false;
```

### **Monotonic Stack (Next Greater)**
```cpp
stack<int> st;
for (int i = n - 1; i >= 0; i--) {
    while (!st.empty() && arr[st.top()] <= arr[i]) {
        st.pop();
    }
    result[i] = st.empty() ? -1 : arr[st.top()];
    st.push(i);
}
```

### **Backtracking (Subsets)**
```cpp
void backtrack(vector<int>& nums, int start, vector<int>& curr) {
    result.push_back(curr);
    for (int i = start; i < nums.size(); i++) {
        curr.push_back(nums[i]);
        backtrack(nums, i + 1, curr);
        curr.pop_back();
    }
}
```

### **Dijkstra**
```cpp
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
vector<int> dist(n, INT_MAX);
pq.push({0, start}); dist[start] = 0;

while (!pq.empty()) {
    auto [d, u] = pq.top(); pq.pop();
    if (d > dist[u]) continue;
    
    for (auto [v, w] : adj[u]) {
        if (dist[u] + w < dist[v]) {
            dist[v] = dist[u] + w;
            pq.push({dist[v], v});
        }
    }
}
```

### **Union-Find**
```cpp
int find(int x) {
    if (parent[x] != x) parent[x] = find(parent[x]);
    return parent[x];
}

void unite(int x, int y) {
    int px = find(x), py = find(y);
    if (px == py) return;
    if (rank[px] < rank[py]) parent[px] = py;
    else if (rank[px] > rank[py]) parent[py] = px;
    else { parent[py] = px; rank[px]++; }
}
```

---

## Time Complexity Quick Reference

| Pattern | Best | Average | Worst | Space |
|---------|------|---------|-------|-------|
| Two Pointer | O(n) | O(n) | O(n) | O(1) |
| Sliding Window | O(n) | O(n) | O(n) | O(k) |
| Binary Search | O(1) | O(log n) | O(log n) | O(1) |
| BFS | O(V+E) | O(V+E) | O(V+E) | O(V) |
| DFS | O(V+E) | O(V+E) | O(V+E) | O(V) |
| Dijkstra | O(E log V) | O(E log V) | O(E log V) | O(V) |
| Bellman-Ford | O(VE) | O(VE) | O(VE) | O(V) |
| Floyd-Warshall | O(V³) | O(V³) | O(V³) | O(V²) |
| Kruskal MST | O(E log E) | O(E log E) | O(E log E) | O(V) |
| Prim MST | O(E log V) | O(E log V) | O(E log V) | O(V) |
| Union-Find | O(α(n)) | O(α(n)) | O(α(n)) | O(n) |
| DP (Knapsack) | O(nW) | O(nW) | O(nW) | O(W) |
| DP (LCS) | O(mn) | O(mn) | O(mn) | O(n) |
| DP (LIS) | O(n log n) | O(n log n) | O(n log n) | O(n) |
| Backtracking | O(2^n) | O(2^n) | O(2^n) | O(n) |
| Heap operations | O(1) | O(log n) | O(log n) | O(n) |
| Trie insert/search | O(L) | O(L) | O(L) | O(ALPHABET_SIZE * N * L) |

---

## Data Structure Choice

| Requirement | Data Structure | Why |
|-------------|----------------|-----|
| Fast lookup | Hash Map | O(1) average |
| Sorted data | TreeMap (BST) | O(log n) operations |
| Min/Max retrieval | Heap | O(1) peek, O(log n) insert |
| FIFO | Queue | O(1) operations |
| LIFO | Stack | O(1) operations |
| Range queries | Segment Tree | O(log n) |
| Prefix matching | Trie | O(L) where L is length |
| Dynamic min/max | Deque | O(1) amortized |
| Disjoint sets | Union-Find | O(α(n)) |
| String search | KMP / Rabin-Karp | O(n+m) |

---

## Common Traps & Tricks

### **Integer Overflow**
```cpp
// BAD
int mid = (left + right) / 2;

// GOOD
int mid = left + (right - left) / 2;
```

### **Comparing Floats**
```cpp
// BAD
if (a == b)

// GOOD
const double EPS = 1e-9;
if (abs(a - b) < EPS)
```

### **Modulo Operations**
```cpp
// Negative modulo
int mod(int a, int m) {
    return ((a % m) + m) % m;
}
```

### **Fast I/O (Competitive Programming)**
```cpp
ios_base::sync_with_stdio(false);
cin.tie(nullptr);
```

### **Checking Bounds**
```cpp
// Always check before accessing
if (i >= 0 && i < n && j >= 0 && j < m) {
    // Safe to access arr[i][j]
}
```

---

## Pre-Interview 15-Minute Review

1. **Minute 1-5:** Read decision tree, identify 3 weak patterns
2. **Minute 6-10:** Write out weak pattern templates from memory
3. **Minute 11-12:** Review time complexities
4. **Minute 13-14:** Visualize: Two Pointer, Sliding Window, BFS, DFS
5. **Minute 15:** Deep breath, "I've solved 99 problems, I know patterns"

---

## Pattern Frequency in Top Companies

| Pattern | Google | Meta | Amazon | Microsoft | Apple |
|---------|--------|------|--------|-----------|-------|
| Two Pointer | ★★★ | ★★★ | ★★★ | ★★ | ★★★ |
| Sliding Window | ★★★ | ★★★ | ★★ | ★★ | ★★ |
| BFS/DFS | ★★★★ | ★★★★ | ★★★★ | ★★★★ | ★★★ |
| DP | ★★★★★ | ★★★★ | ★★★★ | ★★★★★ | ★★★ |
| Binary Search | ★★ | ★★★ | ★★★ | ★★ | ★★ |
| Backtracking | ★★★ | ★★ | ★★ | ★★ | ★ |
| Greedy | ★★★ | ★★★ | ★★★★ | ★★★ | ★★ |
| Graph Algorithms | ★★★★ | ★★★★ | ★★★ | ★★★★ | ★★★ |
| Trie | ★★ | ★★★ | ★★ | ★★ | ★ |
| Bit Manipulation | ★★ | ★★ | ★ | ★ | ★ |

**★ = frequency (more stars = more common)**

---

## Master Pattern Recognition

**See "substring"** → Sliding Window  
**See "sorted array"** → Binary Search  
**See "graph/tree"** → BFS/DFS  
**See "optimize"** → DP or Greedy  
**See "all combinations"** → Backtracking  
**See "intervals"** → Sort + Greedy  
**See "find unique"** → XOR  
**See "matrix rotation"** → Transpose trick  
**See "k elements"** → Heap  
**See "prefix"** → Trie  

---

**PRINT THIS PAGE - Keep near your desk during practice!**
