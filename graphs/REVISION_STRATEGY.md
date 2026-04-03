# Graph Problems Revision Strategy

How to use your memory map resources for efficient revision.

---

## Your Resources

1. **GRAPH_PATTERNS_MEMORY_MAP.md** - Detailed pattern explanations with templates
2. **PROBLEM_TO_PATTERN_MAP.md** - Quick lookup: problem → pattern
3. **GRAPH_TEMPLATES.cpp** - Copy-paste ready code snippets
4. **This file** - How to revise efficiently

---

## Revision Approach 1: Pattern-First (Recommended for beginners)

**Goal:** Master one pattern at a time

**Steps:**
1. Pick a pattern from GRAPH_PATTERNS_MEMORY_MAP.md
2. Read the pattern explanation and when to use it
3. Study the template code
4. Open PROBLEM_TO_PATTERN_MAP.md and find 2-3 problems for that pattern
5. Try coding them from scratch
6. If stuck, refer to GRAPH_TEMPLATES.cpp
7. Move to next pattern

**Time per pattern:** 30-45 minutes

**Recommended order:**
- Day 1: Pattern 1 (Grid BFS/DFS) + Pattern 3 (Simple BFS)
- Day 2: Pattern 4 (Dijkstra)
- Day 3: Pattern 5 (Topological Sort)
- Day 4: Pattern 6 (Cycle Detection)
- Day 5: Pattern 7 (Bipartite) + Pattern 2 (Multi-source BFS)
- Day 6: Pattern 8 (MST)
- Day 7: Pattern 9 (SCC) + Pattern 10 (Bridge)

---

## Revision Approach 2: Problem-Based (Recommended for experienced)

**Goal:** Quickly revise all problems

**Steps:**
1. Open PROBLEM_TO_PATTERN_MAP.md
2. Pick a problem file randomly
3. Look at the problem link (first line of .cpp file)
4. Without looking at your solution, try to:
   - Identify the pattern
   - Recall the approach
   - Code key parts (BFS/DFS loop, main logic)
5. Compare with your solution
6. If you got it wrong, mark the pattern for deeper review
7. Repeat for 10-15 problems per session

**Time per problem:** 5-10 minutes (just recall, not full implementation)

---

## Revision Approach 3: Speed Coding (Before a contest/interview)

**Goal:** Build muscle memory for templates

**Steps:**
1. Open GRAPH_TEMPLATES.cpp
2. Create a new blank file
3. Set a timer for 5 minutes per template
4. Try to code the template from memory
5. Compare with GRAPH_TEMPLATES.cpp
6. Repeat until you can code each template fluently

**Practice these first:**
- Simple BFS
- Dijkstra
- Topological Sort (Kahn's)
- Cycle Detection (Directed)

---

## Revision Approach 4: Decision Tree Practice

**Goal:** Get fast at pattern recognition

**Steps:**
1. Look at problem titles in PROBLEM_TO_PATTERN_MAP.md
2. For each problem title, ask yourself:
   - What pattern does this use?
   - What's the time complexity?
   - What's the key data structure?
3. Check your answer
4. If wrong, review the decision tree in PROBLEM_TO_PATTERN_MAP.md

**Do this daily:** 5 minutes, 10-15 problems

---

## Weekly Revision Schedule (Recommended)

### Week 1: Deep Dive
- **Day 1-2:** Pattern 1 (Grid) + Pattern 3 (BFS)
  - Do: numberOfIslands, wordLadder, stepsByKnight
- **Day 3-4:** Pattern 4 (Dijkstra) + Pattern 5 (Topo Sort)
  - Do: dijkstra, topologicalSort, courseSchedule, alienDic
- **Day 5:** Pattern 6 (Cycle) + Pattern 7 (Bipartite)
  - Do: CycleDetectionDirectedGraph, isBipartite
- **Day 6:** Pattern 8 (MST) + Pattern 2 (Multi-source BFS)
  - Do: prims, connectPoints, rottenOranges
- **Day 7:** Pattern 9 (SCC) + Pattern 10 (Bridge) + Pattern 11 (Clone)
  - Do: kosarajuAlgo, bridgeEdge, cloneGraph

### Week 2+: Random Practice
- **Daily:**
  - 10 minutes: Decision tree practice (Approach 4)
  - 30 minutes: Pick 3-4 random problems and code (Approach 2)
  - 15 minutes: Speed code 2-3 templates (Approach 3)

---

## Pattern Mastery Checklist

Mark ✅ when you can code the pattern from memory without reference.

### Basic Patterns (Must Master)
- [ ] Simple BFS on graph
- [ ] BFS on matrix (4-directional)
- [ ] DFS on graph
- [ ] Dijkstra using set
- [ ] Topological Sort (Kahn's algorithm)
- [ ] Cycle Detection (Directed graph - DFS)
- [ ] Cycle Detection (Undirected graph - DFS)

### Intermediate Patterns
- [ ] Bipartite check using BFS
- [ ] Multi-source BFS
- [ ] Prim's MST
- [ ] Topological Sort (DFS + Stack)
- [ ] Modified Dijkstra problems

### Advanced Patterns
- [ ] Kosaraju's SCC
- [ ] Tarjan's Bridge Detection
- [ ] Graph Cloning

---

## Problem Difficulty Levels

### Easy (Start here if rusty)
1. numberOfIslands.cpp
2. floodFlll.cpp
3. checkPath.cpp
4. Max Area of Island.cpp

### Medium (Core problems)
1. wordLadder.cpp
2. courseSchedule.cpp
3. rottenOranges.cpp
4. isBipartite.cpp
5. dijkstra.cpp
6. topologicalSort.cpp
7. alienDic.cpp
8. CycleDetectionDirectedGraph.cpp

### Hard (Challenge yourself)
1. wordLadder2.cpp
2. kosarajuAlgo.cpp
3. bridgeEdge.cpp
4. Path With Minimum Effort.cpp
5. Snakes and Ladders.cpp

---

## Common Mistakes to Avoid

### 1. Not handling disconnected components
```cpp
// WRONG
if (!visited[0]) {
    DFS(0, adj, visited);
}

// CORRECT
for (int i = 0; i < n; i++) {
    if (!visited[i]) {
        DFS(i, adj, visited);
    }
}
```

### 2. Using wrong visited check in Dijkstra
```cpp
// Use set/priority_queue for Dijkstra, not simple visited array
// Because we might find shorter paths later
```

### 3. Forgetting to mark visited BEFORE pushing to queue
```cpp
// WRONG - might push same node multiple times
if (!visited[adj]) {
    q.push(adj);
    visited[adj] = true; // TOO LATE!
}

// CORRECT
if (!visited[adj]) {
    visited[adj] = true; // Mark immediately
    q.push(adj);
}
```

### 4. Wrong parent handling in undirected cycle detection
```cpp
// MUST exclude parent node
if (!visited[adjNode]) {
    DFS(adjNode, node, adj, visited);
} else if (adjNode != parent) { // Check parent!
    return true;
}
```

### 5. Not resetting visited array in Kosaraju's
```cpp
// After step 1, must reset visited for step 3
for (int i = 0; i < V; i++) {
    visited[i] = false;
}
```

---

## Quick Recall Triggers

When you see these keywords in a problem:

| Keyword | Think |
|---------|-------|
| "shortest" + unweighted | → Simple BFS |
| "shortest" + weighted | → Dijkstra |
| "schedule" OR "order" | → Topological Sort |
| "island" OR "region" | → Grid BFS/DFS |
| "cycle" | → DFS with rec stack/parent |
| "bipartite" OR "2 groups" | → 2-Coloring |
| "minimum cost connect all" | → MST (Prim's) |
| "strongly connected" | → Kosaraju's |
| "bridge" OR "critical" | → Tarjan's |
| "spreading" OR "multi-source" | → Multi-source BFS |

---

## Time Complexity Quick Reference

| Algorithm | Time | Space | When to use |
|-----------|------|-------|-------------|
| BFS/DFS | O(V + E) | O(V) | Traversal, connected components |
| Dijkstra | O(E log V) | O(V) | Weighted shortest path (non-negative) |
| Topological Sort | O(V + E) | O(V) | DAG ordering |
| Prim's MST | O(E log V) | O(V) | Minimum spanning tree |
| Kosaraju's SCC | O(V + E) | O(V) | Strongly connected components |
| Tarjan's Bridge | O(V + E) | O(V) | Find bridges/articulation points |

---

## Before Your Next Interview/Contest

**Day before:**
1. Read through GRAPH_PATTERNS_MEMORY_MAP.md once (20 mins)
2. Code 3 templates from memory (15 mins):
   - Simple BFS
   - Dijkstra
   - Topological Sort
3. Do the decision tree quiz (5 mins)

**1 hour before:**
1. Review Quick Recall Triggers section
2. Glance through PROBLEM_TO_PATTERN_MAP.md
3. Check Common Mistakes section

---

## Progress Tracking

Track your revision sessions:

```
Date: _________
Patterns Revised: _______________
Problems Solved: _______________
Templates Coded from Memory: _______________
Confidence (1-5): ___

Notes/Mistakes:
```

---

## Pro Tips

1. **Visualization helps:** Draw the graph/tree on paper before coding
2. **Start with brute force:** Then optimize if needed
3. **Test with small inputs:** n=3 or n=4 first
4. **Edge cases to always check:**
   - Empty graph (n=0)
   - Single node (n=1)
   - Disconnected graph
   - Cycles
5. **Common test cases:**
   - All nodes connected (tree)
   - No edges at all
   - Complete graph
   - Graph with cycle
   - Directed vs undirected

---

## When Stuck on a Problem

1. **Step 1:** What pattern is this? (Check PROBLEM_TO_PATTERN_MAP.md)
2. **Step 2:** Read pattern explanation (GRAPH_PATTERNS_MEMORY_MAP.md)
3. **Step 3:** Look at template (GRAPH_TEMPLATES.cpp)
4. **Step 4:** Check your original solution in graphs/ folder
5. **Step 5:** Code it again from scratch

---

## Maintenance Schedule

- **Daily (5 mins):** Decision tree practice
- **Weekly (1 hour):** Code 5-7 random problems
- **Monthly (2 hours):** Full pattern review + code all templates

---

Good luck with your revision! 🚀
