# Problem to Pattern Map - All Topics

🔍 **QUICK LOOKUP** - Find pattern for any problem in 5 seconds

---

## How to Use This File

1. **Ctrl+F** / **Cmd+F** → Search problem name
2. See pattern & approach
3. Open corresponding pattern file for template
4. Code it in 15-20 mins

---

## Arrays (14 problems)

| Problem | Pattern | Key Insight | File |
|---------|---------|-------------|------|
| Two Sum | Hash Map | Store complement | ARRAY_PATTERNS.md |
| 3Sum | Two Pointer | Sort + fix one, two pointer rest | [3sum.cpp](../arrays/3sum.cpp) |
| 3Sum Closest | Two Pointer | Sort + minimize difference | [3Sum_Closest.ipynb](../arrays/3Sum_Closest.ipynb) |
| 4Sum | Two Pointer | Sort + fix two, two pointer rest | [4sum.ipynb](../arrays/4sum.ipynb) |
| Container With Most Water | Two Pointer | Move smaller height | ARRAY_PATTERNS.md |
| Product of Array Except Self | Prefix/Suffix Product | Left product * Right product | [Product of Array Except Self.cpp](../arrays/Product%20of%20Array%20Except%20Self.cpp) |
| Maximum Subarray | Kadane's Algorithm | Reset on negative sum | [maximum_subarray_sum.cpp](../arrays/maximum_subarray_sum.cpp) |
| Maximum Product Subarray | Kadane's Variant | Track min & max (negatives flip) | ARRAY_PATTERNS.md |
| Find Minimum in Rotated Sorted Array | Binary Search | Compare with right | ARRAY_PATTERNS.md |
| Search in Rotated Sorted Array | Binary Search | Find sorted half | [Search in Rotated Sorted Array.cpp](../binary_search/Search%20in%20Rotated%20Sorted%20Array.cpp) |
| Longest Consecutive Sequence | Hash Set | Start sequence only if no left neighbor | ARRAY_PATTERNS.md |
| Trapping Rain Water | Two Pointer | Track leftMax & rightMax | [trapping_water.cpp](../arrays/trapping_water.cpp) |
| Spiral Matrix | Matrix Manipulation | 4 pointers (top/bottom/left/right) | MATH_GEOMETRY_PATTERNS.md |
| Spiral Matrix II | Matrix Manipulation | Fill clockwise with boundaries | [Spiral_Matrix_II.cpp](../arrays/Spiral_Matrix_II.cpp) |

---

## Binary Search (7 problems)

| Problem | Pattern | Key Insight | File |
|---------|---------|-------------|------|
| Binary Search | Classic Binary Search | left + (right-left)/2 | ARRAY_PATTERNS.md |
| Find Minimum in Rotated Sorted Array | Modified Binary Search | Compare mid with right | ARRAY_PATTERNS.md |
| Search in Rotated Sorted Array | Modified Binary Search | Identify sorted half | [Search in Rotated Sorted Array.cpp](../binary_search/Search%20in%20Rotated%20Sorted%20Array.cpp) |
| Search in Rotated Sorted Array II | Modified Binary Search (with duplicates) | Skip duplicates first | [Search in rotated soted array2.cpp](../binary_search/Search%20in%20rotated%20soted%20array2.cpp) |
| Find Peak Element | Binary Search on Slope | Go towards increasing side | [peak_element.cpp](../binary_search/peak_element.cpp) |
| Single Element in Sorted Array | Binary Search on Pairs | Check pair alignment | [findSingleElement.cpp](../binary_search/findSingleElement.cpp) |
| Koko Eating Bananas | Binary Search on Answer | Binary search on speed | ARRAY_PATTERNS.md |

---

## Dynamic Programming (23 problems)

| Problem | Pattern | Key Insight | File |
|---------|---------|-------------|------|
| Climbing Stairs | Fibonacci DP | dp[i] = dp[i-1] + dp[i-2] | DP_PATTERNS.md |
| Coin Change | Unbounded Knapsack | Min coins for each amount | [coinChange.cpp](../dp/coinChange.cpp) |
| Coin Change II | Unbounded Knapsack | Count ways | [coinChange2.cpp](../dp/coinChange2.cpp) |
| Longest Increasing Subsequence | LIS Pattern | dp[i] = max length ending at i | [lis/](../dp/lis/) |
| Longest Common Subsequence | LCS Pattern | Match or skip | [lcs.cpp](../dp/lcs.cpp) |
| Word Break | Unbounded Knapsack / DP on String | dp[i] = can form s[0...i] | DP_PATTERNS.md |
| Combination Sum IV | Unbounded Knapsack | Count ways (order matters) | DP_PATTERNS.md |
| House Robber | State Machine DP | Rob or skip | [sticklerThief.cpp](../dp/sticklerThief.cpp) |
| House Robber II | State Machine DP (circular) | Two passes (exclude first or last) | DP_PATTERNS.md |
| Decode Ways | Fibonacci DP | Check 1-digit & 2-digit | [decode_ways.cpp](../dp/decode_ways.cpp) |
| Unique Paths | Grid DP | dp[i][j] = dp[i-1][j] + dp[i][j-1] | [uniquePaths.cpp](../dp/uniquePaths.cpp) |
| Unique Paths II | Grid DP with obstacles | Skip obstacles | [uniquePaths2.cpp](../dp/uniquePaths2.cpp) |
| Jump Game | Greedy / DP | maxReach >= target | [jumpGame.cpp](../dp/jumpGame.cpp) |
| Jump Game II | Greedy / BFS | Track current & next reach | [Minimum_Jmps.cpp](../dp/Minimum_Jmps.cpp) |
| Partition Equal Subset Sum | 0/1 Knapsack | Target = sum/2 | [subsetSumEqK.cpp](../dp/subsetSumEqK.cpp) |
| Target Sum | 0/1 Knapsack | Convert to subset sum | [targetSum.cpp](../dp/targetSum.cpp) |
| Best Time to Buy and Sell Stock | Kadane's Variant | Track min so far | [buy-sell-stocks/](../dp/buy-sell-stocks/) |
| Best Time to Buy and Sell Stock II | Greedy | Sum all profits | [buy-sell-stocks/](../dp/buy-sell-stocks/) |
| Best Time to Buy and Sell Stock with Cooldown | State Machine DP | 3 states: hold, sold, cooldown | [buy-sell-stocks/](../dp/buy-sell-stocks/) |
| Longest Palindromic Substring | Expand Around Center | Check odd & even length | [longestPalindromicSs.cpp](../dp/longestPalindromicSs.cpp) |
| Palindromic Substrings | Expand Around Center | Count all | DP_PATTERNS.md |
| Edit Distance | LCS Variant | Insert/Delete/Replace | [editDistance.cpp](../dp/editDistance.cpp) |
| 0/1 Knapsack | 0/1 Knapsack | Include or exclude | [0-1knapsack.cpp](../dp/0-1knapsack.cpp) |

---

## Graphs (13 problems)

| Problem | Pattern | Key Insight | File |
|---------|---------|-------------|------|
| Clone Graph | BFS/DFS + Hash Map | Map old -> new nodes | [cloneGraph.cpp](../graphs/cloneGraph.cpp) |
| Course Schedule | Topological Sort (Cycle Detection) | Kahn's or DFS | [courseSchedule.cpp](../graphs/courseSchedule.cpp) |
| Course Schedule II | Topological Sort | Return order | [courseSchedule.cpp](../graphs/courseSchedule.cpp) |
| Pacific Atlantic Water Flow | DFS from edges | Two DFS (pacific & atlantic) | graphs/GRAPH_PATTERNS_MEMORY_MAP.md |
| Number of Islands | BFS/DFS | Mark visited | [numberOfIslands.cpp](../graphs/numberOfIslands.cpp) |
| Longest Consecutive Sequence | Union-Find or Hash Set | In arrays section | ARRAY_PATTERNS.md |
| Alien Dictionary | Topological Sort | Build graph from order | [alienDic.cpp](../graphs/alienDic.cpp) |
| Graph Valid Tree | Cycle Detection + Connected | No cycle & n-1 edges | [CycleDetectionUndirectedGraph.cpp](../graphs/CycleDetectionUndirectedGraph.cpp) |
| Number of Connected Components | DFS/Union-Find | Count components | graphs/GRAPH_PATTERNS_MEMORY_MAP.md |
| Word Ladder | BFS | Shortest transformation | graphs/GRAPH_PATTERNS_MEMORY_MAP.md |
| Network Delay Time | Dijkstra | Shortest path to all | [Network Delay Time.cpp](../graphs/Network%20Delay%20Time.cpp) |
| Redundant Connection | Union-Find | First edge causing cycle | graphs/GRAPH_PATTERNS_MEMORY_MAP.md |
| Find City with Least Neighbours | Floyd-Warshall | All pairs shortest path | [Find City with Least Neighbours.cpp](../graphs/Find%20City%20with%20Least%20Neighbours.cpp) |

---

## Intervals (6 problems)

| Problem | Pattern | Key Insight | File |
|---------|---------|-------------|------|
| Insert Interval | Interval Merge | Add non-overlapping, merge overlapping | GREEDY_INTERVAL_PATTERNS.md |
| Merge Intervals | Sort by Start | Sort + merge consecutive | GREEDY_INTERVAL_PATTERNS.md |
| Non-overlapping Intervals | Sort by End + Greedy | Remove minimum | GREEDY_INTERVAL_PATTERNS.md |
| Meeting Rooms | Sort + Check Overlap | Sort by start, check consecutive | GREEDY_INTERVAL_PATTERNS.md |
| Meeting Rooms II | Min Heap | Track end times | GREEDY_INTERVAL_PATTERNS.md |
| Minimum Interval to Include Each Query | Sort + Heap | Sort both, sweep | GREEDY_INTERVAL_PATTERNS.md |

---

## Linked List (11 problems)

| Problem | Pattern | Key Insight | File |
|---------|---------|-------------|------|
| Reverse Linked List | Three Pointers | prev, curr, next | LINKED_LIST_PATTERNS.md |
| Detect Cycle in Linked List | Floyd's Cycle Detection | Slow & fast pointers | LINKED_LIST_PATTERNS.md |
| Merge Two Sorted Lists | Two Pointers | Compare & link | [merge 2 sorted LinkList.cpp](../link_list/merge%202%20sorted%20LinkList.cpp) |
| Merge k Sorted Lists | Min Heap | K-way merge | [merge_K_LinkList.cpp](../link_list/merge_K_LinkList.cpp) |
| Remove Nth Node From End | Two Pass or Two Pointer | Fast ahead by n | [kth_node_from_end.cpp](../link_list/kth_node_from_end.cpp) |
| Reorder List | Find Mid + Reverse + Merge | L0→Ln→L1→Ln-1... | [reorder_list.cpp](../link_list/reorder_list.cpp) |
| Linked List Cycle II | Floyd's Extended | Meet + reset to find start | LINKED_LIST_PATTERNS.md |
| Add Two Numbers | Digit-by-Digit Addition | Track carry | [add_2_linklist.cpp](../link_list/add_2_linklist.cpp) |
| Copy List with Random Pointer | Hash Map | Map old -> new | LINKED_LIST_PATTERNS.md |
| LRU Cache | Hash Map + Doubly Linked List | O(1) get/put | [LRU_cache.cpp](../link_list/LRU_cache.cpp) |
| Find Duplicate Number | Floyd's Cycle Detection | Treat as linked list | LINKED_LIST_PATTERNS.md |

---

## Matrix (5 problems)

| Problem | Pattern | Key Insight | File |
|---------|---------|-------------|------|
| Set Matrix Zeroes | In-place Marking | Use first row/col as markers | MATH_GEOMETRY_PATTERNS.md |
| Spiral Matrix | Boundary Simulation | 4 pointers | MATH_GEOMETRY_PATTERNS.md |
| Rotate Image | Transpose + Reverse | 90° = transpose + reverse rows | MATH_GEOMETRY_PATTERNS.md |
| Word Search | Backtracking + DFS | Mark visited, backtrack | BACKTRACKING_PATTERNS.md |
| Longest Increasing Path in Matrix | DFS + Memoization | Tree DP on DAG | TREE_PATTERNS.md |

---

## Strings (9 problems)

| Problem | Pattern | Key Insight | File |
|---------|---------|-------------|------|
| Longest Substring Without Repeating Characters | Sliding Window | Hash map for last seen | [max substring without rep.cpp](../strings/max%20substring%20without%20rep.cpp) |
| Longest Repeating Character Replacement | Sliding Window | maxFreq + k flips | [Longest Repeating Character Replacement.cpp](../strings/Longest%20Repeating%20Character%20Replacement.cpp) |
| Minimum Window Substring | Sliding Window | Contract when valid | [minimum_window.cpp](../strings/minimum_window.cpp) |
| Valid Anagram | Hash Map / Sorting | Count characters | [valid_anagram.cpp](../strings/valid_anagram.cpp) |
| Group Anagrams | Hash Map | Sort as key | [group_anagram.cpp](../strings/group_anagram.cpp) |
| Valid Parentheses | Stack | Push open, pop on close | [valid_parentheses.cpp](../strings/valid_parentheses.cpp) |
| Valid Palindrome | Two Pointer | Skip non-alphanumeric | [valid_palindrome.cpp](../strings/valid_palindrome.cpp) |
| Longest Palindromic Substring | Expand Around Center | Check odd & even | [longestPalindromicSs.cpp](../dp/longestPalindromicSs.cpp) |
| Palindromic Substrings | Expand Around Center | Count all | DP_PATTERNS.md |

---

## Trees (15 problems)

| Problem | Pattern | Key Insight | File |
|---------|---------|-------------|------|
| Maximum Depth of Binary Tree | DFS Recursion | 1 + max(left, right) | [HeightOfTree.cpp](../trees/HeightOfTree.cpp) |
| Same Tree | DFS Recursion | Compare roots & recurse | [identical_tree.cpp](../trees/identical_tree.cpp) |
| Invert Binary Tree | DFS/BFS | Swap left & right | [mirror.cpp](../trees/mirror.cpp) |
| Binary Tree Maximum Path Sum | Tree DP | Track max including root | [maxPathSum.cpp](../dp/maxPathSum.cpp) |
| Binary Tree Level Order Traversal | BFS | Queue for level-by-level | [levelOrderTraversal.cpp](../trees/levelOrderTraversal.cpp) |
| Serialize and Deserialize Binary Tree | BFS/DFS | Preorder with null markers | [serializeAndDeserialize.cpp](../trees/serializeAndDeserialize.cpp) |
| Subtree of Another Tree | DFS | Check isSame at each node | [subtree.cpp](../trees/subtree.cpp) |
| Construct Binary Tree from Preorder and Inorder | Divide & Conquer | Root = preorder[0], split by inorder | [build_tree.cpp](../trees/build_tree.cpp) |
| Validate Binary Search Tree | DFS with Range | Track min & max | [isBST.cpp](../trees/BST/isBST.cpp) |
| Kth Smallest Element in BST | In-order Traversal | BST in-order is sorted | [kth_smallest.cpp](../trees/BST/kth_smallest.cpp) |
| Lowest Common Ancestor of BST | BST Property | Go left/right based on values | [lca_BST.cpp](../trees/BST/lca_BST.cpp) |
| Implement Trie | Trie Data Structure | 26-child array | [word_search.cpp](../trie/word_search.cpp) |
| Design Add and Search Words | Trie + DFS | Handle '.' with recursion | [design_word_dic.cpp](../trie/design_word_dic.cpp) |
| Word Search II | Trie + Backtracking | DFS with trie pruning | [word_search_2.cpp](../trie/word_search_2.cpp) |
| Binary Tree Right Side View | BFS | Last node of each level | [right_view.cpp](../trees/right_view.cpp) |

---

## Heaps / Priority Queue (3 problems)

| Problem | Pattern | Key Insight | File |
|---------|---------|-------------|------|
| Merge k Sorted Lists | Min Heap | K-way merge | [merge_K_LinkList.cpp](../link_list/merge_K_LinkList.cpp) |
| Top K Frequent Elements | Max Heap or Bucket Sort | Count + heap | [top_k_frequent.cpp](../priority_queue/top_k_frequent.cpp) |
| Find Median from Data Stream | Two Heaps | Max heap (left) + min heap (right) | [Median of Stream.cpp](../priority_queue/Median%20of%20Stream.cpp) |

---

## Backtracking (9 problems)

| Problem | Pattern | Key Insight | File |
|---------|---------|-------------|------|
| Combination Sum | Backtracking (Combinations) | Can reuse elements | BACKTRACKING_PATTERNS.md |
| Combination Sum II | Backtracking (Combinations) | Skip duplicates | BACKTRACKING_PATTERNS.md |
| Permutations | Backtracking (Permutations) | Swap or used array | BACKTRACKING_PATTERNS.md |
| Subsets | Backtracking (Subsets) | Include or exclude | BACKTRACKING_PATTERNS.md |
| Subsets II | Backtracking (Subsets) | Sort + skip duplicates | BACKTRACKING_PATTERNS.md |
| Word Search | Backtracking + DFS | Mark visited, backtrack | BACKTRACKING_PATTERNS.md |
| Palindrome Partitioning | Backtracking | Check palindrome, recurse | BACKTRACKING_PATTERNS.md |
| Letter Combinations of Phone Number | Backtracking | Map digits to letters | BACKTRACKING_PATTERNS.md |
| N-Queens | Backtracking | Check cols, diagonals | BACKTRACKING_PATTERNS.md |

---

## Bit Manipulation (7 problems)

| Problem | Pattern | Key Insight | File |
|---------|---------|-------------|------|
| Single Number | XOR All | a ^ a = 0, a ^ 0 = a | [findSingleElement.cpp](../binary_search/findSingleElement.cpp) |
| Number of 1 Bits | Brian Kernighan | n & (n-1) removes rightmost 1 | [num_1_bits.cpp](../bit_manipulation/num_1_bits.cpp) |
| Counting Bits | DP + Bit Trick | dp[i] = dp[i >> 1] + (i & 1) | [count_bits.cpp](../bit_manipulation/count_bits.cpp) |
| Reverse Bits | Bit Shifting | Shift left, add bit | [reverse_bits.cpp](../bit_manipulation/reverse_bits.cpp) |
| Missing Number | XOR or Sum Formula | XOR all or n*(n+1)/2 - sum | [missing_num.cpp](../bit_manipulation/missing_num.cpp) |
| Sum of Two Integers | Bit Manipulation | XOR for sum, AND<<1 for carry | [sum.cpp](../bit_manipulation/sum.cpp) |
| Reverse Integer | Math | Multiply by 10, add digit | BIT_MANIPULATION_PATTERNS.md |

---

## Math & Geometry (8 problems)

| Problem | Pattern | Key Insight | File |
|---------|---------|-------------|------|
| Rotate Image | Transpose + Reverse | 90° clockwise | MATH_GEOMETRY_PATTERNS.md |
| Spiral Matrix | Boundary Simulation | 4 pointers | MATH_GEOMETRY_PATTERNS.md |
| Set Matrix Zeroes | In-place Marking | Use first row/col | MATH_GEOMETRY_PATTERNS.md |
| Happy Number | Cycle Detection | Floyd's or hash set | MATH_GEOMETRY_PATTERNS.md |
| Plus One | Array Manipulation | Handle carry | MATH_GEOMETRY_PATTERNS.md |
| Pow(x, n) | Binary Exponentiation | O(log n) | MATH_GEOMETRY_PATTERNS.md |
| Multiply Strings | String Math | Digit-by-digit | MATH_GEOMETRY_PATTERNS.md |
| Detect Squares | Hash Map | Store points, calculate | [countRectangles.cpp](../hashing/countRectangles.cpp) |

---

## Greedy (8 problems)

| Problem | Pattern | Key Insight | File |
|---------|---------|-------------|------|
| Maximum Subarray | Kadane's Algorithm | Reset on negative | [maximum_subarray_sum.cpp](../arrays/maximum_subarray_sum.cpp) |
| Jump Game | Greedy | Track maxReach | [jumpGame.cpp](../dp/jumpGame.cpp) |
| Jump Game II | Greedy BFS | Track current & next reach | [Minimum_Jmps.cpp](../dp/Minimum_Jmps.cpp) |
| Gas Station | Greedy | Start where surplus begins | [circularTour.cpp](../sliding%20window/circularTour.cpp) |
| Hand of Straights | Greedy + Hash Map | Sort, form consecutive groups | GREEDY_INTERVAL_PATTERNS.md |
| Merge Triplets | Greedy | Track max achievable | GREEDY_INTERVAL_PATTERNS.md |
| Partition Labels | Greedy | Track last occurrence | [Partition_Labels.ipynb](../notebooks/Partition_Labels.ipynb) |
| Valid Parenthesis String | Greedy | Track min/max open count | GREEDY_INTERVAL_PATTERNS.md |

---

## Stack (4 problems)

| Problem | Pattern | Key Insight | File |
|---------|---------|-------------|------|
| Valid Parentheses | Stack | Push '(', pop on ')' | [valid_parentheses.cpp](../strings/valid_parentheses.cpp) |
| Min Stack | Design | Use min stack or store diffs | [min_stack.cpp](../stack%20%26%20queue/min_stack.cpp) |
| Evaluate Reverse Polish Notation | Stack | Pop operands, push result | STACK_PATTERNS.md |
| Generate Parentheses | Backtracking | Track open & close counts | BACKTRACKING_PATTERNS.md |

---

## Sliding Window (6 problems)

| Problem | Pattern | Key Insight | File |
|---------|---------|-------------|------|
| Best Time to Buy and Sell Stock | Kadane's Variant | Track min so far | [buy-sell-stocks/](../dp/buy-sell-stocks/) |
| Longest Substring Without Repeating Characters | Sliding Window | Hash map last seen | [max substring without rep.cpp](../strings/max%20substring%20without%20rep.cpp) |
| Longest Repeating Character Replacement | Sliding Window | maxFreq + k | [Longest Repeating Character Replacement.cpp](../strings/Longest%20Repeating%20Character%20Replacement.cpp) |
| Permutation in String | Sliding Window | Fixed size window | [permutation_in_string.cpp](../sliding%20window/permutation_in_string.cpp) |
| Minimum Window Substring | Sliding Window | Expand, contract when valid | [minimum_window.cpp](../strings/minimum_window.cpp) |
| Sliding Window Maximum | Deque (Monotonic) | Store indices | [max_sliding_window.cpp](../sliding%20window/max_sliding_window.cpp) |

---

## How to Read This Map

**Format:** Problem → Pattern → Key Insight → File Location

**Example:**
```
3Sum → Two Pointer → Sort + fix one, two pointer rest → arrays/3sum.cpp
```

**Workflow:**
1. See problem name in interview
2. Ctrl+F in this file
3. Jump to pattern file for template
4. Code in 15 mins

---

**Pro Tip:** If you forget a problem, come here first. Pattern name will trigger memory!
