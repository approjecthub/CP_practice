# Greedy & Interval Patterns

**Status:** Greedy 5/8 (63%), Intervals 5/6 (83%)

---

## GREEDY PATTERNS

### Pattern 1: Activity Selection / Interval Scheduling

**When to use:**
- Select maximum non-overlapping activities
- Schedule meetings
- Keywords: "maximum", "non-overlapping", "schedule"

**Template:**
```cpp
int intervalScheduling(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) {
        return a[1] < b[1];  // Sort by end time
    });
    
    int count = 0;
    int lastEnd = INT_MIN;
    
    for (auto& interval : intervals) {
        if (interval[0] >= lastEnd) {  // No overlap
            count++;
            lastEnd = interval[1];
        }
    }
    return count;
}

// Minimum Arrows to Burst Balloons
int findMinArrowShots(vector<vector<int>>& points) {
    sort(points.begin(), points.end(), [](auto& a, auto& b) {
        return a[1] < b[1];
    });
    
    int arrows = 1;
    int lastEnd = points[0][1];
    
    for (int i = 1; i < points.size(); i++) {
        if (points[i][0] > lastEnd) {  // Need new arrow
            arrows++;
            lastEnd = points[i][1];
        }
    }
    return arrows;
}
```

**Time:** O(n log n) | **Space:** O(1)

**Problems:**
- ✅ [Non-overlapping Intervals](../greedy/interval/non_overlapping_intervals.cpp) 🔥
- ✅ [Minimum Arrows to Burst Balloons](../greedy/Minimum Number of Arrows to Burst Balloons.cpp)
- ✅ [Meeting Rooms](../greedy/interval/meeting_room2.cpp)

---

### Pattern 2: Jump Game

**When to use:**
- Can reach end with jumps
- Minimum jumps needed
- Keywords: "jump", "reach", "minimum steps"

**Template (Can Jump):**
```cpp
bool canJump(vector<int>& nums) {
    int maxReach = 0;
    
    for (int i = 0; i < nums.size(); i++) {
        if (i > maxReach) return false;  // Can't reach i
        maxReach = max(maxReach, i + nums[i]);
    }
    return true;
}
```

**Template (Min Jumps):**
```cpp
int jump(vector<int>& nums) {
    int jumps = 0;
    int currentEnd = 0, maxReach = 0;
    
    for (int i = 0; i < nums.size() - 1; i++) {
        maxReach = max(maxReach, i + nums[i]);
        
        if (i == currentEnd) {  // Must jump
            jumps++;
            currentEnd = maxReach;
        }
    }
    return jumps;
}
```

**Time:** O(n) | **Space:** O(1)

**Problems:**
- ✅ [Jump Game](../dp/jumpGame.cpp) 🔥
- ✅ [Jump Game II](../dp/Minimum_Jmps.cpp)

---

### Pattern 3: Greedy Choice at Each Step

**When to use:**
- Locally optimal choice leads to global optimum
- Build solution step by step
- Keywords: "maximum", "minimum", "optimal"

**Template (Largest Permutation):**
```cpp
vector<int> largestPermutation(vector<int>& nums, int k) {
    unordered_map<int, int> pos;  // value -> index
    for (int i = 0; i < nums.size(); i++) {
        pos[nums[i]] = i;
    }
    
    int expected = nums.size();
    for (int i = 0; i < nums.size() && k > 0; i++) {
        if (nums[i] != expected) {
            int idx = pos[expected];
            swap(nums[i], nums[idx]);
            pos[nums[idx]] = idx;
            pos[nums[i]] = i;
            k--;
        }
        expected--;
    }
    return nums;
}
```

**Template (Gas Station):**
```cpp
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int totalGas = 0, currentGas = 0;
    int start = 0;
    
    for (int i = 0; i < gas.size(); i++) {
        totalGas += gas[i] - cost[i];
        currentGas += gas[i] - cost[i];
        
        if (currentGas < 0) {  // Can't start from current position
            start = i + 1;
            currentGas = 0;
        }
    }
    
    return totalGas >= 0 ? start : -1;
}
```

**Time:** O(n) | **Space:** O(1) or O(n)

**Problems:**
- ✅ [Largest Permutation](../greedy/largest_permutation.cpp)
- ✅ [Container With Most Water](../greedy/containerWithMostWater.cpp)
- ✅ [Gas Station / Circular Tour](../sliding%20window/circularTour.cpp)
- ✅ [Partition Labels](../notebooks/Partition_Labels.ipynb)
- ⬜ [Hand of Straights](https://leetcode.com/problems/hand-of-straights/)

---

## INTERVAL PATTERNS

### Pattern 1: Merge Intervals

**When to use:**
- Combine overlapping intervals
- Keywords: "merge", "overlap"

**Template:**
```cpp
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    if (intervals.empty()) return {};
    
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> result;
    result.push_back(intervals[0]);
    
    for (int i = 1; i < intervals.size(); i++) {
        if (intervals[i][0] <= result.back()[1]) {  // Overlap
            result.back()[1] = max(result.back()[1], intervals[i][1]);
        } else {
            result.push_back(intervals[i]);
        }
    }
    return result;
}
```

**Template (Insert Interval):**
```cpp
vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>> result;
    int i = 0, n = intervals.size();
    
    // Add all intervals before newInterval
    while (i < n && intervals[i][1] < newInterval[0]) {
        result.push_back(intervals[i++]);
    }
    
    // Merge overlapping intervals
    while (i < n && intervals[i][0] <= newInterval[1]) {
        newInterval[0] = min(newInterval[0], intervals[i][0]);
        newInterval[1] = max(newInterval[1], intervals[i][1]);
        i++;
    }
    result.push_back(newInterval);
    
    // Add remaining intervals
    while (i < n) {
        result.push_back(intervals[i++]);
    }
    
    return result;
}
```

**Time:** O(n log n) | **Space:** O(1)

**Problems:**
- ✅ [Merge Intervals](../merge_interval_problems/mergeInterval.cpp) 🔥
- ✅ [Insert Interval](../merge_interval_problems/insertInterval.cpp)

---

### Pattern 2: Meeting Rooms (Heap)

**When to use:**
- Find max overlapping intervals
- Minimum rooms needed
- Keywords: "meeting rooms", "overlap count"

**Template:**
```cpp
int minMeetingRooms(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    
    priority_queue<int, vector<int>, greater<int>> pq;  // Min heap of end times
    
    for (auto& interval : intervals) {
        if (!pq.empty() && pq.top() <= interval[0]) {
            pq.pop();  // Room is free, reuse it
        }
        pq.push(interval[1]);  // Occupy room until end time
    }
    
    return pq.size();  // Number of rooms needed
}
```

**Alternative (Two arrays):**
```cpp
int minMeetingRooms(vector<vector<int>>& intervals) {
    vector<int> start, end;
    for (auto& interval : intervals) {
        start.push_back(interval[0]);
        end.push_back(interval[1]);
    }
    
    sort(start.begin(), start.end());
    sort(end.begin(), end.end());
    
    int rooms = 0, endPtr = 0;
    for (int i = 0; i < start.size(); i++) {
        if (start[i] < end[endPtr]) {
            rooms++;  // Need new room
        } else {
            endPtr++;  // Reuse room
        }
    }
    return rooms;
}
```

**Time:** O(n log n) | **Space:** O(n)

**Problems:**
- ✅ [Meeting Rooms II](../greedy/interval/meeting_room2.cpp) 🔥
- ⬜ [Minimum Interval to Include Each Query](https://leetcode.com/problems/minimum-interval-to-include-each-query/) - Hard

---

## Pattern Recognition

| Pattern | Key Indicator | Approach |
|---------|---------------|----------|
| Activity Selection | Max non-overlapping | Sort by end time |
| Jump Game | Reach with jumps | Track max reachable |
| Greedy Choice | Build optimal step-by-step | Local optimum |
| Merge Intervals | Combine overlaps | Sort, merge conditions |
| Meeting Rooms | Count overlaps | Heap or two arrays |

---

## Greedy vs DP Decision

**Use Greedy when:**
- Problem has greedy choice property (local optimal → global optimal)
- Examples: Activity selection, Huffman coding, Fractional knapsack

**Use DP when:**
- Need to consider all possibilities
- Overlapping subproblems
- Examples: 0/1 knapsack, LCS, longest path

**Test with counter-example:** If you can find case where greedy fails, use DP.

---

## Common Mistakes

1. **Wrong sort comparator:**
   ```cpp
   // For activity selection, sort by END time, not start
   sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) {
       return a[1] < b[1];  // END time
   });
   ```

2. **Not handling edge cases in merge:**
   ```cpp
   // Check overlap: intervals[i][0] <= result.back()[1]
   // Merge: max(result.back()[1], intervals[i][1])
   ```

3. **Forgetting to sort first:**
   ```cpp
   sort(intervals.begin(), intervals.end());  // Always sort!
   ```

---

## Revision Cluster

**Interval Problems** (1 hr):
1. [mergeInterval.cpp](../merge_interval_problems/mergeInterval.cpp)
2. [insertInterval.cpp](../merge_interval_problems/insertInterval.cpp)
3. [non_overlapping_intervals.cpp](../greedy/interval/non_overlapping_intervals.cpp)
4. [meeting_room2.cpp](../greedy/interval/meeting_room2.cpp)

---

**Speed Drill:**
- Code merge intervals in 8 mins
- Code meeting rooms in 10 mins
- Code canJump in 5 mins
