# Problem to Pattern Quick Lookup

Use this for instant pattern identification when you see a problem.

---

## Pattern 1: BFS/DFS on Matrix (Grid Traversal)
- numberOfIslands.cpp
- Max Area of Island.cpp
- closedIsland.cpp
- floodFlll.cpp
- Surrounded Region.cpp
- ReplaceO.cpp
- wordBoggle.cpp

---

## Pattern 2: Multi-Source BFS
- rottenOranges.cpp

---

## Pattern 3: Shortest Path (Unweighted BFS)
- wordLadder.cpp
- wordLadder2.cpp
- stepsByKnight.cpp
- Snakes and Ladders.cpp
- checkPath.cpp
- moonJourney.cpp

---

## Pattern 4: Dijkstra (Weighted Shortest Path)
- dijkstra.cpp
- Network Delay Time.cpp
- Path With Minimum Effort.cpp (modified Dijkstra)
- Path with Maximum Probability.cpp (modified Dijkstra)
- Find City with Least Neighbours.cpp

---

## Pattern 5: Topological Sort
- topologicalSort.cpp
- courseSchedule.cpp
- alienDic.cpp
- circleOfStrings.cpp

---

## Pattern 6: Cycle Detection
- CycleDetectionDirectedGraph.cpp
- CycleDetectionUndirectedGraph.cpp
- courseSchedule.cpp (uses topo sort for cycle detection)

---

## Pattern 7: Bipartite Check
- isBipartite.cpp
- binaryPalindrome.cpp

---

## Pattern 8: Minimum Spanning Tree (MST)
- prims.cpp
- connectPoints.cpp

---

## Pattern 9: Strongly Connected Components (SCC)
- kosarajuAlgo.cpp

---

## Pattern 10: Bridge Detection
- bridgeEdge.cpp

---

## Pattern 11: Graph Cloning
- cloneGraph.cpp

---

## By Algorithm Type

### BFS-based
- numberOfIslands.cpp
- rottenOranges.cpp
- wordLadder.cpp
- wordLadder2.cpp
- isBipartite.cpp
- stepsByKnight.cpp
- Snakes and Ladders.cpp

### DFS-based
- topologicalSort.cpp
- kosarajuAlgo.cpp
- bridgeEdge.cpp
- CycleDetectionDirectedGraph.cpp
- CycleDetectionUndirectedGraph.cpp
- alienDic.cpp

### Dijkstra/Priority Queue
- dijkstra.cpp
- Network Delay Time.cpp
- Path With Minimum Effort.cpp
- Path with Maximum Probability.cpp

### Prim's Algorithm
- prims.cpp
- connectPoints.cpp

### Topological Sort (Kahn's Algorithm)
- courseSchedule.cpp
- alienDic.cpp

---

## By Problem Characteristics

### Matrix/Grid Problems
- numberOfIslands.cpp
- rottenOranges.cpp
- Max Area of Island.cpp
- closedIsland.cpp
- floodFlll.cpp
- Surrounded Region.cpp
- ReplaceO.cpp
- stepsByKnight.cpp
- Path With Minimum Effort.cpp

### String/Word Problems
- wordLadder.cpp
- wordLadder2.cpp
- alienDic.cpp
- wordBoggle.cpp
- circleOfStrings.cpp

### Shortest Path Problems
- dijkstra.cpp
- wordLadder.cpp
- stepsByKnight.cpp
- Network Delay Time.cpp
- Path With Minimum Effort.cpp
- Path with Maximum Probability.cpp

### Graph Construction Problems
(Build graph first, then apply algorithm)
- alienDic.cpp
- connectPoints.cpp
- circleOfStrings.cpp

---

## Quick Decision Tree

```
START
│
├─ Is it a 2D grid/matrix?
│  ├─ YES → Pattern 1: BFS/DFS on Matrix
│  │       → Multiple sources? → Pattern 2: Multi-source BFS
│  └─ NO → Continue
│
├─ Need shortest path?
│  ├─ Weighted graph?
│  │  ├─ YES → Pattern 4: Dijkstra
│  │  └─ NO → Pattern 3: Simple BFS
│  └─ NO → Continue
│
├─ Need ordering/scheduling?
│  └─ YES → Pattern 5: Topological Sort
│      └─ Can also detect cycles!
│
├─ Detect cycles?
│  ├─ Directed? → Pattern 6A: DFS with rec stack
│  └─ Undirected? → Pattern 6B: DFS with parent
│
├─ Check if bipartite?
│  └─ YES → Pattern 7: 2-Coloring with BFS/DFS
│
├─ Minimum cost to connect all?
│  └─ YES → Pattern 8: MST (Prim's/Kruskal)
│
├─ Find strongly connected components?
│  └─ YES → Pattern 9: Kosaraju's Algorithm
│
├─ Find bridges/critical edges?
│  └─ YES → Pattern 10: Tarjan's Algorithm
│
└─ Clone/copy graph?
   └─ YES → Pattern 11: Graph Cloning
```

---

## One-Liner Problem Summaries

| Problem | Pattern | One-Liner |
|---------|---------|-----------|
| dijkstra.cpp | Dijkstra | Weighted shortest path from source |
| prims.cpp | MST | Minimum cost to connect all nodes |
| kosarajuAlgo.cpp | SCC | Find strongly connected components |
| topologicalSort.cpp | Topo Sort | Order nodes by dependencies |
| numberOfIslands.cpp | Grid BFS/DFS | Count connected components in matrix |
| wordLadder.cpp | BFS | Shortest transformation with 1-char changes |
| wordLadder2.cpp | BFS | All shortest transformation paths |
| courseSchedule.cpp | Topo Sort | Check if DAG, detect cycle |
| alienDic.cpp | Topo Sort | Build graph from word order → topo sort |
| isBipartite.cpp | Bipartite | Check if 2-colorable |
| rottenOranges.cpp | Multi-source BFS | Spread from all sources simultaneously |
| cloneGraph.cpp | Graph Clone | Deep copy with BFS/DFS |
| bridgeEdge.cpp | Bridge | Find critical edges using Tarjan's |
| CycleDetectionDirectedGraph.cpp | Cycle | DFS with recursion stack |
| CycleDetectionUndirectedGraph.cpp | Cycle | DFS with parent tracking |
| floodFlll.cpp | Grid BFS/DFS | Fill connected region |
| closedIsland.cpp | Grid BFS/DFS | Islands not touching boundary |
| connectPoints.cpp | MST | Prim's on coordinate points |
| Network Delay Time.cpp | Dijkstra | Max time to reach all nodes |
| Path With Minimum Effort.cpp | Modified Dijkstra | Minimize max edge on path |
| Path with Maximum Probability.cpp | Modified Dijkstra | Maximize path probability |
| Max Area of Island.cpp | Grid BFS/DFS | Largest connected component |
| Snakes and Ladders.cpp | BFS | Shortest path with special edges |
| Surrounded Region.cpp | Grid BFS/DFS | Capture regions not on boundary |
| ReplaceO.cpp | Grid BFS/DFS | Mark/replace surrounded regions |
| wordBoggle.cpp | Backtracking + Trie | Find words in grid |
| stepsByKnight.cpp | BFS | Shortest path with knight moves |
| binaryPalindrome.cpp | Bipartite | Check if palindrome graph is 2-colorable |
| checkPath.cpp | BFS/DFS | Check if path exists |
| circleOfStrings.cpp | Eulerian Path | Check if Eulerian path exists |
| moonJourney.cpp | BFS | Shortest path variant |
| Find City with Least Neighbours.cpp | Dijkstra | Floyd-Warshall variant |

---

## Pro Tips for Fast Recall

1. **See "island/region/connected"** → BFS/DFS on matrix
2. **See "shortest + unweighted"** → Simple BFS
3. **See "shortest + weighted"** → Dijkstra
4. **See "order/schedule/dependency"** → Topological Sort
5. **See "minimum cost connect all"** → MST
6. **See "cycle"** → DFS-based detection
7. **See "bipartite/partition/2 groups"** → 2-Coloring
8. **See "strongly connected"** → Kosaraju's
9. **See "bridge/critical"** → Tarjan's
10. **Multiple starting points spread** → Multi-source BFS
