# Master Revision Strategy

🔄 **RETENTION > NEW SOLVING** - 99 problems are useless if you forget them

---

## The Forgetting Curve Problem

**Reality Check:**
- Solve a DP problem today → 60% forgotten in 24 hours
- No revision for 1 week → 90% forgotten
- Interview in 2 weeks → Can't recall pattern

**Solution:** Spaced Repetition + Active Recall

---

## 6 Revision Methods

### **Method 1: Pattern-Based Batch Revision (45 mins/session)**

**What:** Solve 4-5 problems of SAME pattern back-to-back

**When:** After completing each pattern file

**How:**
1. Open pattern MD file
2. Read template (5 mins)
3. Code 4 problems from memory WITHOUT looking (30 mins)
4. Review mistakes (10 mins)

**Example (Week 3, Day 2):**
- 9:00 - Read DP_PATTERNS.md (0/1 Knapsack section)
- 9:05 - Code: Partition Equal Subset Sum
- 9:15 - Code: Target Sum
- 9:25 - Code: 0/1 Knapsack
- 9:35 - Code: Subset Sum Equal to K
- 9:45 - Compare with solutions, note mistakes

**Frequency:** 
- Weak patterns: Every 3 days
- Medium patterns: Every 7 days
- Strong patterns: Every 14 days

---

### **Method 2: Speed Coding Drill (20 mins/session)**

**What:** Re-solve PREVIOUSLY SOLVED problems under time pressure

**When:** Daily (first thing in practice session)

**How:**
1. Pick 1 problem you solved ≥3 days ago
2. Set timer: Easy (8 mins), Medium (12 mins), Hard (18 mins)
3. Code from SCRATCH without looking
4. If stuck after 5 mins, peek at pattern template ONLY
5. If can't finish, mark for re-review

**Daily Rotation:**
- **Monday:** Arrays/Two Pointer problem
- **Tuesday:** DP problem
- **Wednesday:** Graph/Tree problem
- **Thursday:** Sliding Window/Stack problem
- **Friday:** Backtracking/Bit Manipulation problem
- **Saturday:** Yesterday's failed problem
- **Sunday:** Random from weak category

**Goal:** Build muscle memory for 99 solved problems

---

### **Method 3: Spaced Repetition System (15 mins/day)**

**What:** Review problems at increasing intervals

**Schedule for Each Problem:**
```
Day 0:  Solve problem (first time)
Day 1:  Quick review (read code, write approach)
Day 3:  Re-solve from scratch (12 mins)
Day 7:  Re-solve from scratch (10 mins)
Day 14: Re-solve from scratch (8 mins)
Day 30: Re-solve from scratch (6 mins) ← NOW IN LONG-TERM MEMORY
```

**Implementation:**
Create `revision_tracker.md` with columns:
```
| Problem | Solved | Day 1 | Day 3 | Day 7 | Day 14 | Day 30 |
|---------|--------|-------|-------|-------|--------|--------|
| 3Sum    | ✅     | ✅    | ✅    | ⬜    | ⬜     | ⬜     |
```

**Pro Tip:** Focus on Day 3 & Day 7 revisions - these are CRITICAL for retention

---

### **Method 4: Pattern Recognition Drill (10 mins/day)**

**What:** Train your brain to identify patterns INSTANTLY

**How:**
1. Open [PROBLEM_TO_PATTERN_MAP_ALL_TOPICS.md](PROBLEM_TO_PATTERN_MAP_ALL_TOPICS.md)
2. Cover the "Pattern" column
3. Read 20 problem names
4. Say pattern name OUT LOUD before uncovering
5. Score yourself

**Target:** 18/20 correct (90%) by Week 6

**Example:**
```
See: "Longest Substring Without Repeating Characters"
Think: Sliding Window! (look for subarray/substring → sliding window)

See: "Course Schedule"
Think: Topological Sort! (look for dependencies → topo sort)

See: "Combination Sum"
Think: Backtracking! (look for "all combinations" → backtracking)
```

**Bonus:** Do this with ACTUAL interview problems on LeetCode homepage

---

### **Method 5: Mock Interview Simulation (1 hour/week)**

**What:** Simulate real interview pressure

**When:** Every Sunday (Week 3-8)

**Setup:**
1. Pick 2 problems (1 Medium, 1 Medium-Hard) you solved 2+ weeks ago
2. Open blank file
3. Set timer: 45 mins for both
4. Explain solution OUT LOUD while coding
5. No peeking at solutions/pattern files

**Evaluation Criteria:**
- [ ] Identified pattern in <2 mins
- [ ] Explained approach before coding
- [ ] Handled edge cases
- [ ] Analyzed time/space complexity
- [ ] Completed in time limit
- [ ] Code compiled without errors

**Problem Combos (by week):**
- **Week 3:** Two Sum + 3Sum (warm-up)
- **Week 4:** Merge Intervals + Course Schedule
- **Week 5:** LIS + Alien Dictionary
- **Week 6:** Word Search II + Serialize Tree
- **Week 7:** LRU Cache + Max Path Sum
- **Week 8:** Median Stream + Trapping Rain Water

---

### **Method 6: Weak Spot Deep Dive (30 mins/week)**

**What:** Intensively review your WORST category

**How:**
1. Check PROBLEM_CHECKLIST.md - find lowest %
2. Open corresponding pattern file
3. Re-read entire pattern file
4. Code ALL problems in that category from scratch
5. Create summary note card (1 page)

**Current Priorities (you):**
1. **Backtracking (11%)** - URGENT
   - Week 3: Solve all 8 problems
   - Week 4: Re-solve all 8 problems
   - Week 6: Speed drill all 8 problems

2. **Bit Manipulation (14%)** - URGENT  
   - Week 3: Solve all 6 problems
   - Week 5: Re-solve all 6 problems

3. **Math & Geometry (13%)** - URGENT
   - Week 3: Solve all 7 problems
   - Week 5: Re-solve all 7 problems

---

## Weekly Revision Breakdown (11 hours total)

### **Weekdays (1 hour/day × 5 = 5 hours)**
- **0:00-0:20** - Speed Coding Drill (Method 2)
- **0:20-0:30** - Pattern Recognition Drill (Method 4)
- **0:30-0:45** - Spaced Repetition (Method 3) - 2-3 problems
- **0:45-1:00** - New problem solving

**Ratio:** 45% revision, 55% new (optimal for retention)

### **Weekends (3 hours/day × 2 = 6 hours)**

**Saturday:**
- **0:00-0:45** - Pattern-Based Batch Revision (Method 1)
- **0:45-1:30** - Weak Spot Deep Dive (Method 6)
- **1:30-3:00** - New problem solving (3-4 problems)

**Sunday:**
- **0:00-1:00** - Mock Interview Simulation (Method 5)
- **1:00-1:30** - Review mock interview mistakes
- **1:30-3:00** - New problem solving (3-4 problems)

---

## Revision Clusters (Group Related Problems)

### **Cluster 1: Two Pointer Family**
- Two Sum, 3Sum, 3Sum Closest, 4Sum
- Container With Most Water
- Trapping Rain Water
- Valid Palindrome

**Revision:** All 7 problems in 45 mins (Week 4, Saturday)

---

### **Cluster 2: Knapsack Family (DP)**
- 0/1 Knapsack, Partition Equal Subset Sum, Target Sum
- Coin Change, Coin Change II
- Unbounded Knapsack variants

**Revision:** All 6 problems in 50 mins (Week 5, Saturday)

---

### **Cluster 3: LCS Family (DP)**
- Longest Common Subsequence
- Edit Distance
- Shortest Common Supersequence
- Longest Common Substring
- Distinct Occurrences

**Revision:** All 5 problems in 45 mins (Week 5, Sunday)

---

### **Cluster 4: Graph Shortest Path**
- BFS (unweighted)
- Dijkstra (weighted, non-negative)
- Bellman-Ford (weighted, negative)
- Floyd-Warshall (all pairs)

**Revision:** Code all 4 from scratch (Week 6, Saturday)

---

### **Cluster 5: Tree Traversals**
- Pre-order, In-order, Post-order (recursive + iterative)
- Level Order
- Vertical Order
- Zigzag

**Revision:** All 8 variations in 40 mins (Week 6, Sunday)

---

### **Cluster 6: Sliding Window Variants**
- Fixed size window (Permutation in String)
- Variable size window (Longest Substring)
- With hash map (Minimum Window Substring)
- With deque (Sliding Window Maximum)

**Revision:** All 6 problems in 50 mins (Week 7, Saturday)

---

### **Cluster 7: Backtracking Templates**
- Subsets, Subsets II
- Permutations, Permutations II
- Combinations, Combination Sum, Combination Sum II
- N-Queens, Word Search

**Revision:** All 9 problems in 60 mins (Week 7, Sunday)

---

## Red Flags (When to Re-Revise Immediately)

⚠️ **Can't recall pattern**: Solve 3 similar problems back-to-back TODAY  
⚠️ **Took >2× time limit**: Re-solve tomorrow + read pattern template  
⚠️ **Couldn't explain in interview**: Write explanation, re-solve in 3 days  
⚠️ **Wrong time complexity**: Re-read pattern, solve 2 similar problems  
⚠️ **Lots of bugs**: Code same problem 3 times until bug-free  

---

## Retention Metrics (Track Weekly)

```
Week X Metrics:
- Problems solved this week: __
- Problems revised this week: __
- Speed drill success rate: __/7 (aim for 6/7)
- Pattern recognition accuracy: __/20 (aim for 18/20)
- Mock interview score: __/6 criteria (aim for 5/6)
- Current completion: __/149 (target: 149 by Week 8)
```

---

## The 80/20 Rule for Revision

**80% of interview problems** come from **20% of patterns**:

1. **Two Pointer** (appears in 15% of problems)
2. **Sliding Window** (appears in 12% of problems)
3. **DFS/BFS** (appears in 18% of problems)
4. **DP (0/1 Knapsack, LCS)** (appears in 16% of problems)
5. **Binary Search** (appears in 10% of problems)

**Action:** Revise these 5 patterns WEEKLY, others bi-weekly

---

## Pre-Interview Final Review (3 days before)

### **Day -3 (3 hours):**
- Re-solve 1 problem from EACH of 10 categories (10 problems total)
- Review all pattern templates in [MASTER_QUICK_REFERENCE.md](MASTER_QUICK_REFERENCE.md)

### **Day -2 (3 hours):**
- Mock interview: 3 problems (1 Easy, 1 Medium, 1 Medium-Hard)
- Re-read weak pattern files

### **Day -1 (2 hours):**
- Speed drill: 8 problems (8 mins each) across all categories
- Review [PROBLEM_TO_PATTERN_MAP_ALL_TOPICS.md](PROBLEM_TO_PATTERN_MAP_ALL_TOPICS.md)
- Visualize: "See problem → Identify pattern → Write template" loop

### **Day 0 (Interview Day):**
- 15-min review: [MASTER_QUICK_REFERENCE.md](MASTER_QUICK_REFERENCE.md)
- NO NEW PROBLEMS (maintain confidence)

---

## Example: Full Week 5 Revision Schedule

**Monday (1 hour):**
- 0:00-0:20: Speed drill → 3Sum (solved Week 2)
- 0:20-0:30: Pattern recognition drill
- 0:30-0:45: Spaced repetition → Course Schedule (Day 7), Word Break (Day 3)
- 0:45-1:00: New problem → Happy Number

**Tuesday-Friday:** Similar structure, rotate categories

**Saturday (3 hours):**
- 0:00-0:45: Pattern-Based Batch → LCS family (5 problems)
- 0:45-1:30: Weak Spot Deep Dive → Bit Manipulation (re-solve all 6)
- 1:30-3:00: New problems → Pow(x,n), Multiply Strings

**Sunday (3 hours):**
- 0:00-1:00: Mock interview → LRU Cache + Alien Dictionary
- 1:00-1:30: Review mistakes, update revision tracker
- 1:30-3:00: New problems → Palindrome Partitioning, Letter Combinations

---

## Why This Works

**Science:**
- Spaced repetition → 70% retention after 30 days
- Active recall (re-solving) > passive reading by 3x
- Pattern recognition → cuts solving time by 50%

**Your Goal:** Transform 99 solved → 99 RETAINED → Interview ready

**Remember:** "I've seen this pattern before" > "I think I can solve this"

---

**PRINT & TRACK:** Use revision tracker spreadsheet from Week 3 onwards!
