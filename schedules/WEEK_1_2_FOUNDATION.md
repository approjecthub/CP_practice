# Week 1-2: Foundation & Pattern Mastery

🎯 **Goal:** Build strong foundation in weak areas, master all pattern templates

**Time:** 11 hours/week × 2 weeks = 22 hours total  
**New Problems:** 20-25 problems  
**Revision:** Daily spaced repetition starts

---

## Week 1 Overview

**Focus:** Backtracking → Bit Manipulation → Math/Geometry (Your 3 weakest)

**Daily Structure:**
- Weekdays: 1 hour (2-3 problems)
- Weekends: 3 hours (5-6 problems)

---

## Week 1 Daily Breakdown

### **Monday (1 hour) - Backtracking Foundations**

**Morning Review (10 mins):**
- Read [BACKTRACKING_PATTERNS.md](../patterns/BACKTRACKING_PATTERNS.md) - Subsets section

**New Problems (50 mins):**
1. [Subsets](https://leetcode.com/problems/subsets/) - 15 mins ⬜
   - Pattern: Backtracking (Subsets)
   - Template: Include/Exclude decision tree
   - Target: O(2^n) time, O(n) space

2. [Subsets II](https://leetcode.com/problems/subsets-ii/) - 20 mins ⬜
   - Pattern: Backtracking (Subsets with duplicates)
   - Key: Sort + skip duplicates at same level
   - Edge case: [1,1,2] → don't repeat [1,2]

3. [Combination Sum](https://leetcode.com/problems/combination-sum/) - 15 mins ⬜
   - Pattern: Backtracking (Combinations)
   - Key: Can reuse same element
   - Target: O(2^target) time

**After Solving:**
- Update PROBLEM_CHECKLIST.md
- Add to revision tracker (Day 0)

---

### **Tuesday (1 hour) - Backtracking Continued**

**Speed Drill (15 mins):**
- Re-solve: Subsets (from yesterday) in 10 mins WITHOUT looking

**New Problems (45 mins):**
1. [Permutations](https://leetcode.com/problems/permutations/) - 15 mins ⬜
   - Pattern: Backtracking (Permutations)
   - Template: Swap or used array
   - Target: O(n! × n) time

2. [Combination Sum II](https://leetcode.com/problems/combination-sum-ii/) - 20 mins ⬜
   - Pattern: Backtracking (Combinations)
   - Key: Sort + skip duplicates + can't reuse
   - Harder than Combination Sum

3. Review patterns: Write templates from memory (10 mins)
   - Subsets template
   - Permutations template

---

### **Wednesday (1 hour) - Backtracking Advanced**

**Pattern Recognition Drill (10 mins):**
- Open [PROBLEM_TO_PATTERN_MAP_ALL_TOPICS.md](../patterns/PROBLEM_TO_PATTERN_MAP_ALL_TOPICS.md)
- Practice: Cover patterns, identify 15 problems

**New Problems (50 mins):**
1. [Letter Combinations of Phone Number](https://leetcode.com/problems/letter-combinations-of-a-phone-number/) - 15 mins ⬜
   - Pattern: Backtracking
   - Key: Map digits to letters, DFS
   - Good warm-up problem

2. [Palindrome Partitioning](https://leetcode.com/problems/palindrome-partitioning/) - 20 mins ⬜
   - Pattern: Backtracking + String
   - Key: Check if substring is palindrome
   - Harder problem

**Revision (15 mins):**
- Day 1 revision: Combination Sum (read code + approach)

---

### **Thursday (1 hour) - Bit Manipulation Foundations**

**Morning Review (15 mins):**
- Read [BIT_MANIPULATION_PATTERNS.md](../patterns/BIT_MANIPULATION_PATTERNS.md) - All tricks

**New Problems (45 mins):**
1. [Number of 1 Bits](https://leetcode.com/problems/number-of-1-bits/) - 8 mins ⬜
   - Pattern: Brian Kernighan's Algorithm
   - Key: n & (n-1) removes rightmost 1
   - Easy problem, master the trick

2. [Counting Bits](https://leetcode.com/problems/counting-bits/) - 12 mins ⬜
   - Pattern: DP + Bit Trick
   - Key: dp[i] = dp[i >> 1] + (i & 1)
   - Build on previous problem

3. [Missing Number](https://leetcode.com/problems/missing-number/) - 10 mins ⬜
   - Pattern: XOR trick
   - Key: XOR all indices and values
   - Alternative: Sum formula

4. [Reverse Bits](https://leetcode.com/problems/reverse-bits/) - 15 mins ⬜
   - Pattern: Bit Shifting
   - Key: Shift result left, add LSB
   - Good practice

---

### **Friday (1 hour) - Bit Manipulation Continued**

**Speed Drill (15 mins):**
- Re-solve: Number of 1 Bits + Missing Number (5 mins each)

**New Problems (45 mins):**
1. [Sum of Two Integers](https://leetcode.com/problems/sum-of-two-integers/) - 15 mins ⬜
   - Pattern: XOR + AND
   - Key: sum = a ^ b, carry = (a & b) << 1
   - Tricky, take time to understand

2. Review all bit tricks from memory (10 mins):
   - XOR properties
   - Brian Kernighan
   - Bit counting
   - Write on paper

**Revision (20 mins):**
- Day 3 revision: Subsets (re-solve from scratch)

---

### **Saturday (3 hours) - Math/Geometry Foundations**

**Morning Review (20 mins):**
- Read [MATH_GEOMETRY_PATTERNS.md](../patterns/MATH_GEOMETRY_PATTERNS.md)

**Pattern-Based Batch (1 hour):**
- Backtracking Cluster: Re-solve all 5 problems from Mon-Wed
  - Subsets (10 mins)
  - Subsets II (12 mins)
  - Combination Sum (12 mins)
  - Permutations (12 mins)
  - Letter Combinations (14 mins)

**New Problems (1 hour 40 mins):**
1. [Rotate Image](https://leetcode.com/problems/rotate-image/) - 20 mins 🔥 ⬜
   - Pattern: Matrix Rotation
   - Key: Transpose + Reverse rows
   - MUST MASTER - common in interviews

2. [Spiral Matrix](https://leetcode.com/problems/spiral-matrix/) - 25 mins 🔥 ⬜
   - Pattern: Boundary Simulation
   - Key: 4 pointers (top, bottom, left, right)
   - Check boundaries carefully

3. [Set Matrix Zeroes](https://leetcode.com/problems/set-matrix-zeroes/) - 20 mins ⬜
   - Pattern: In-place Marking
   - Key: Use first row/col as markers
   - Tricky space optimization

4. [Happy Number](https://leetcode.com/problems/happy-number/) - 15 mins ⬜
   - Pattern: Cycle Detection (Floyd's)
   - Key: Detect infinite loop
   - Easy problem

5. [Plus One](https://leetcode.com/problems/plus-one/) - 10 mins ⬜
   - Pattern: Array Simulation
   - Key: Handle carry
   - Easy problem

---

### **Sunday (3 hours) - Math/Geometry + Week Review**

**New Problems (1 hour 30 mins):**
1. [Pow(x, n)](https://leetcode.com/problems/powx-n/) - 20 mins ⬜
   - Pattern: Binary Exponentiation
   - Key: O(log n) by squaring
   - Handle negative exponents

2. [Multiply Strings](https://leetcode.com/problems/multiply-strings/) - 30 mins ⬜
   - Pattern: String Math
   - Key: Position formula i+j, i+j+1
   - Complex indexing

3. Review all Math tricks from cheat sheet (15 mins)
   - Write from memory
   - Practice mental math

**Week Review (1 hour 30 mins):**
- Re-read all 3 pattern files (30 mins):
  - BACKTRACKING_PATTERNS.md
  - BIT_MANIPULATION_PATTERNS.md
  - MATH_GEOMETRY_PATTERNS.md

- Create summary cards (30 mins):
  - 1 page per pattern
  - Templates only, no explanations

- Review [MASTER_QUICK_REFERENCE.md](../patterns/MASTER_QUICK_REFERENCE.md) (15 mins)

- Update progress (15 mins):
  - PROBLEM_CHECKLIST.md
  - Revision tracker
  - Check completion: Backtracking (89%), Bit (86%), Math (88%)

---

## Week 1 Summary

**Expected Progress:**
- Backtracking: 1/9 → 8/9 (89%) ✅
- Bit Manipulation: 1/7 → 6/7 (86%) ✅
- Math & Geometry: 1/8 → 7/8 (88%) ✅
- Total: 99/149 → 118/149 (79%)

**Skills Gained:**
- ✅ All 3 backtracking templates mastered
- ✅ All 5 bit manipulation tricks memorized
- ✅ Matrix rotation, spiral, exponentiation patterns solid

---

## Week 2 Overview

**Focus:** Strengthen existing strong areas, fill remaining gaps

**Categories:**
- Day 1-2: DP review + remaining problems
- Day 3-4: Trees remaining problems
- Day 5: Greedy/Intervals remaining
- Day 6-7: Array/String/Linked List gaps + Mock interview

---

## Week 2 Daily Breakdown

### **Monday (1 hour) - DP Review**

**Speed Drill (15 mins):**
- Re-solve from Week 1: Combination Sum (Day 7 revision)

**Pattern Recognition (10 mins):**
- Drill: 20 problems from PROBLEM_TO_PATTERN_MAP

**New Problems (35 mins):**
1. Review DP files you haven't touched in 2+ weeks:
   - Pick 2 DP problems from your existing solved list
   - Re-solve from scratch (15 mins each)
   - Focus on: LIS or MCM patterns (your weaker DP areas)

---

### **Tuesday (1 hour) - Trees Review**

**Speed Drill (15 mins):**
- Re-solve: Happy Number (from Saturday) in 10 mins

**New Problems (45 mins):**
1. Review your trees/ folder:
   - Pick 3 tree problems solved >2 weeks ago
   - Re-solve from scratch (15 mins each)
   - Focus on: Tree DP or serialization problems

---

### **Wednesday (1 hour) - Greedy/Intervals Gaps**

**Pattern Recognition (10 mins):**
- Drill: 20 problems

**Review (15 mins):**
- Read [GREEDY_INTERVAL_PATTERNS.md](../patterns/GREEDY_INTERVAL_PATTERNS.md)

**New Problems (35 mins):**
1. Identify 2-3 unsolved problems from greedy/intervals:
   - Check PROBLEM_CHECKLIST.md
   - Solve them (12-15 mins each)
   - Likely: Gas Station, Hand of Straights, Merge Triplets

---

### **Thursday (1 hour) - Array/String Gaps**

**Speed Drill (20 mins):**
- Re-solve 2 bit manipulation problems from Week 1

**New Problems (40 mins):**
1. Review array/string categories:
   - Pick 2 unsolved problems
   - Focus on patterns you're weaker at
   - E.g., Kadane variants, sliding window edge cases

---

### **Friday (1 hour) - Linked List Gaps**

**Speed Drill (20 mins):**
- Re-solve: Rotate Image (Day 7 revision from Saturday)

**New Problems (40 mins):**
1. Check linked list completion in PROBLEM_CHECKLIST.md:
   - Solve any remaining problems
   - If all solved, re-do 2 hard ones (LRU Cache, Merge K Lists)

---

### **Saturday (3 hours) - Pattern-Based Batch Revision**

**Cluster 1: Two Pointer (45 mins):**
- Re-solve: Two Sum, 3Sum, 3Sum Closest, Container With Most Water, Trapping Rain Water

**Cluster 2: Knapsack DP (50 mins):**
- Re-solve: 0/1 Knapsack, Partition Equal Subset Sum, Target Sum, Coin Change

**Cluster 3: Graph Traversal (45 mins):**
- Re-solve: Number of Islands, Clone Graph, Course Schedule

**Week Planning (40 mins):**
- Update all trackers
- Review next week's plan
- Prepare for mock interview tomorrow

---

### **Sunday (3 hours) - Mock Interview #1**

**Mock Interview (1 hour):**
- Problem 1 (Easy-Medium): Two Sum (warm-up) - 15 mins
- Problem 2 (Medium): Merge Intervals - 20 mins
- Problem 3 (Medium): Validate BST - 20 mins
- Buffer: 5 mins

**Review Session (1 hour):**
- Score yourself on 6 criteria (see REVISION_MASTER.md)
- Note down mistakes
- Re-solve any failed problem

**Week 2 Summary (1 hour):**
- Review both weeks' progress
- Update PROBLEM_CHECKLIST.md
- Expected: 118/149 → ~125/149 (84%)
- Create Week 3-5 detailed plan
- Ensure all weak areas now >75%

---

## Week 1-2 Metrics to Track

**Weekly Checklist:**
```
Week 1:
- [ ] Solved 15+ new problems
- [ ] Backtracking: 1/9 → 8/9
- [ ] Bit Manipulation: 1/7 → 6/7
- [ ] Math & Geometry: 1/8 → 7/8
- [ ] Started revision tracker
- [ ] Created summary cards for 3 patterns

Week 2:
- [ ] Solved 8+ problems (new + review)
- [ ] All categories >75%
- [ ] Completed first mock interview
- [ ] Score: At least 4/6 criteria
- [ ] Revision: 10+ problems re-solved
- [ ] Ready for breadth-first Week 3-5
```

---

## Red Flags & Adjustments

**If struggling with Backtracking:**
- Spend extra hour on Sunday Week 1
- Re-read pattern file 3 times
- Draw decision trees on paper

**If Week 2 mock interview score <4/6:**
- Extend foundation phase by 2-3 days
- More pattern recognition drills
- Re-solve weak problems 2-3 times

**If behind schedule:**
- Cut new problems, focus on mastery of existing
- Quality > quantity in foundation phase

---

## Success Criteria (End of Week 2)

✅ **Pattern Mastery:**
- Can write backtracking templates from memory
- Can identify patterns for 18/20 problems instantly
- All bit manipulation tricks memorized

✅ **Problem Completion:**
- Week gaps (Backtracking, Bit, Math) now filled
- Total: 125/149+ (84%+)
- All categories ≥75%

✅ **Revision System:**
- Revision tracker set up
- Day 1, 3, 7 revisions happening
- Speed drill routine established

✅ **Interview Readiness Foundation:**
- Mock interview completed
- Can explain solutions out loud
- Recognize patterns quickly

**If all criteria met → Proceed to Week 3-5 (Breadth-First Completion)**

---

## Tips for Week 1-2

1. **Don't rush** - Foundation is critical
2. **Write templates from memory daily** - builds muscle memory
3. **Explain solutions out loud** - simulates interview
4. **Update trackers immediately** - don't skip
5. **If stuck >15 mins** - read pattern, try again tomorrow
6. **Sleep well** - pattern recognition needs rest
7. **Celebrate wins** - going from 11% to 89% is HUGE!

**Remember:** These 2 weeks transform your weakest areas into strengths. Slow and steady wins.
