# Dynamic Programming Patterns

✅ **STRENGTH AREA** - You have 20/22 problems solved (91%). Use this for efficient revision.

---

## Pattern 1: 0/1 Knapsack

**When to use:**
- Choose or skip items (binary choice)
- Maximize/minimize value with weight constraint
- Keywords: "0/1", "subset", "partition", "each item once"

**Template:**
```cpp
// Recursive + Memoization
int knapsack(int W, int wt[], int val[], int n, vector<vector<int>>& dp) {
    if (n == 0 || W == 0) return 0;
    if (dp[n][W] != -1) return dp[n][W];
    
    if (wt[n-1] <= W) {
        dp[n][W] = max(
            val[n-1] + knapsack(W - wt[n-1], wt, val, n-1, dp),  // Take
            knapsack(W, wt, val, n-1, dp)                         // Skip
        );
    } else {
        dp[n][W] = knapsack(W, wt, val, n-1, dp);  // Can't take
    }
    return dp[n][W];
}

// Tabulation (Bottom-up)
int knapsack(int W, int wt[], int val[], int n) {
    vector<vector<int>> dp(n+1, vector<int>(W+1, 0));
    
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (wt[i-1] <= w) {
                dp[i][w] = max(val[i-1] + dp[i-1][w - wt[i-1]], dp[i-1][w]);
            } else {
                dp[i][w] = dp[i-1][w];
            }
        }
    }
    return dp[n][W];
}

// Space Optimized (1D array)
int knapsack(int W, int wt[], int val[], int n) {
    vector<int> dp(W+1, 0);
    
    for (int i = 0; i < n; i++) {
        for (int w = W; w >= wt[i]; w--) {  // Reverse to avoid reuse
            dp[w] = max(dp[w], val[i] + dp[w - wt[i]]);
        }
    }
    return dp[W];
}
```

**Time:** O(n*W) | **Space:** O(W) optimized

**Problems:**
- ✅ [0-1 Knapsack](../dp/0-1knapsack.cpp)
- ✅ [Subset Sum Equal to K](../dp/subsetSumEqK.cpp) - [Partition Equal](https://leetcode.com/problems/partition-equal-subset-sum/)
- ✅ [Minimum Sum Partition](../dp/minSumPartition.cpp)
- ✅ [Count Partition with Given Diff](../dp/countPartitionWithGivenDiff.cpp)
- ✅ [Target Sum](../dp/targetSum.cpp)

---

## Pattern 2: Unbounded Knapsack

**When to use:**
- Unlimited supply of each item
- Can pick item multiple times
- Keywords: "unlimited", "infinite supply", "coin change", "rod cutting"

**Template:**
```cpp
// Key difference: i not i-1 when taking item (can reuse)
int unboundedKnapsack(int W, int wt[], int val[], int n) {
    vector<int> dp(W+1, 0);
    
    for (int i = 0; i < n; i++) {
        for (int w = wt[i]; w <= W; w++) {  // Forward iteration (allows reuse)
            dp[w] = max(dp[w], val[i] + dp[w - wt[i]]);
        }
    }
    return dp[W];
}

// Coin Change (Minimum coins)
int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;
    
    for (int coin : coins) {
        for (int i = coin; i <= amount; i++) {
            if (dp[i - coin] != INT_MAX) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }
    return dp[amount] == INT_MAX ? -1 : dp[amount];
}

// Coin Change 2 (Number of ways)
int change(int amount, vector<int>& coins) {
    vector<int> dp(amount + 1, 0);
    dp[0] = 1;  // One way to make 0
    
    for (int coin : coins) {
        for (int i = coin; i <= amount; i++) {
            dp[i] += dp[i - coin];
        }
    }
    return dp[amount];
}
```

**Time:** O(n*amount) | **Space:** O(amount)

**Problems:**
- ✅ [Coin Change](../dp/coinChange.cpp) 🔥
- ✅ [Coin Change 2](../dp/coinChange2.cpp)
- ✅ [Rod Cutting](../dp/rodCutting.cpp) × 2 files

---

## Pattern 3: Longest Common Subsequence (LCS)

**When to use:**
- Two sequences, find common pattern
- Order matters but not contiguous
- Keywords: "longest common", "edit distance", "subsequence"

**Template:**
```cpp
int lcs(string s1, string s2) {
    int m = s1.size(), n = s2.size();
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i-1] == s2[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];  // Match: add 1
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);  // No match: max of skip
            }
        }
    }
    return dp[m][n];
}

// Space Optimized
int lcs(string s1, string s2) {
    int m = s1.size(), n = s2.size();
    vector<int> prev(n+1, 0), curr(n+1, 0);
    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i-1] == s2[j-1]) {
                curr[j] = 1 + prev[j-1];
            } else {
                curr[j] = max(prev[j], curr[j-1]);
            }
        }
        prev = curr;
    }
    return prev[n];
}
```

**Time:** O(m*n) | **Space:** O(n) optimized

**LCS Variants:**

**Edit Distance (Levenshtein):**
```cpp
int editDistance(string s1, string s2) {
    int m = s1.size(), n = s2.size();
    vector<vector<int>> dp(m+1, vector<int>(n+1));
    
    // Base cases
    for (int i = 0; i <= m; i++) dp[i][0] = i;  // Delete all
    for (int j = 0; j <= n; j++) dp[0][j] = j;  // Insert all
    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1];  // No operation
            } else {
                dp[i][j] = 1 + min({
                    dp[i-1][j],    // Delete
                    dp[i][j-1],    // Insert
                    dp[i-1][j-1]   // Replace
                });
            }
        }
    }
    return dp[m][n];
}
```

**Longest Common Substring (contiguous):**
```cpp
int longestCommonSubstring(string s1, string s2) {
    int m = s1.size(), n = s2.size();
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    int maxLen = 0;
    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i-1] == s2[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];  // Extend substring
                maxLen = max(maxLen, dp[i][j]);
            }
            // else dp[i][j] = 0 (already initialized)
        }
    }
    return maxLen;
}
```

**Problems:**
- ✅ [Longest Common Subsequence](../dp/lcs.cpp) 🔥
- ✅ [Edit Distance](../dp/editDistance.cpp) 🔥
- ✅ [Shortest Common Supersequence](../dp/scs.cpp)
- ✅ [Longest Common Substring](../dp/longesCommonSubstring.cpp)
- ✅ [Distinct Occurrences](../dp/distinctOccurances.cpp)
- ✅ [Min Insertions/Deletions](../dp/minInsDel.cpp)
- ✅ [Longest Palindromic Subsequence](../dp/longestPalindromicSs.cpp)
- ✅ [Min Insertions for Palindrome](../dp/minmInsertionP.cpp)

---

## Pattern 4: Longest Increasing Subsequence (LIS)

**When to use:**
- Find longest increasing/decreasing sequence
- Order matters, need to track previous elements
- Keywords: "longest increasing", "lis", "subsequence"

**Template (DP - O(n²)):**
```cpp
int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 1);  // Each element is LIS of length 1
    int maxLen = 1;
    
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[j] < nums[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        maxLen = max(maxLen, dp[i]);
    }
    return maxLen;
}
```

**Template (Binary Search - O(n log n)):**
```cpp
int lengthOfLIS(vector<int>& nums) {
    vector<int> tails;  // tails[i] = smallest tail of LIS of length i+1
    
    for (int num : nums) {
        auto it = lower_bound(tails.begin(), tails.end(), num);
        if (it == tails.end()) {
            tails.push_back(num);  // Extend LIS
        } else {
            *it = num;  // Replace to keep smallest tail
        }
    }
    return tails.size();
}
```

**Time:** O(n²) or O(n log n) | **Space:** O(n)

**Problems:**
- ✅ [Longest Increasing Subsequence](../dp/lis/lis.cpp) 🔥
- ✅ [Count LIS](../dp/lis/countLIS.cpp)
- ✅ [Longest Bitonic Subsequence](../dp/lis/longestBitonicSS.cpp)
- ✅ [Longest String Chain](../dp/lis/longestStringChain.cpp)
- ✅ [Largest Divisible Subset](../dp/lis/largestDivSubset.cpp)

---

## Pattern 5: Matrix Chain Multiplication (MCM)

**When to use:**
- Partition problem with subproblems
- Try all partition points
- Keywords: "partition", "burst", "palindrome partition", "matrix chain"

**Template:**
```cpp
// Top-down with memoization
int mcm(int arr[], int i, int j, vector<vector<int>>& dp) {
    if (i >= j) return 0;  // Base case
    if (dp[i][j] != -1) return dp[i][j];
    
    int minCost = INT_MAX;
    for (int k = i; k < j; k++) {
        int cost = mcm(arr, i, k, dp) +          // Left partition
                   mcm(arr, k+1, j, dp) +        // Right partition
                   arr[i-1] * arr[k] * arr[j];   // Merge cost
        minCost = min(minCost, cost);
    }
    return dp[i][j] = minCost;
}

// Palindrome Partition
int palindromePartition(string s, int i, int j, vector<vector<int>>& dp) {
    if (i >= j) return 0;
    if (isPalindrome(s, i, j)) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    
    int minCuts = INT_MAX;
    for (int k = i; k < j; k++) {
        int cuts = palindromePartition(s, i, k, dp) +
                   palindromePartition(s, k+1, j, dp) + 1;
        minCuts = min(minCuts, cuts);
    }
    return dp[i][j] = minCuts;
}
```

**Time:** O(n³) | **Space:** O(n²)

**Problems:**
- ✅ [Matrix Chain Multiplication](../dp/matrix-chain-multiplication/mcm.cpp)
- ✅ [Palindrome Partitioning](../dp/matrix-chain-multiplication/palindromPartition.cpp)
- ✅ [Burst Balloons](../dp/matrix-chain-multiplication/burstBalloons.cpp) 🔥
- ✅ [Boolean Parenthesization](../dp/matrix-chain-multiplication/boolParenthesization.cpp)
- ✅ [Min Cost to Cut Stick](../dp/matrix-chain-multiplication/minCostToCut.cpp)
- ✅ [Partition Array for Max Sum](../dp/matrix-chain-multiplication/partitionMaxSum.cpp)

---

## Pattern 6: Grid DP

**When to use:**
- 2D grid/matrix path problems
- Move from start to end with constraints
- Keywords: "grid", "matrix", "paths", "minimum path sum"

**Template:**
```cpp
int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, 1));  // Base case: 1 way for first row/col
    
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];  // From top + left
        }
    }
    return dp[m-1][n-1];
}

// With obstacles
int uniquePathsWithObstacles(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    if (grid[0][0] == 1) return 0;
    
    vector<vector<int>> dp(m, vector<int>(n, 0));
    dp[0][0] = 1;
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) continue;  // Obstacle
            if (i > 0) dp[i][j] += dp[i-1][j];
            if (j > 0) dp[i][j] += dp[i][j-1];
        }
    }
    return dp[m-1][n-1];
}

// Minimum Path Sum
int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n));
    dp[0][0] = grid[0][0];
    
    // First row
    for (int j = 1; j < n; j++) dp[0][j] = dp[0][j-1] + grid[0][j];
    // First col
    for (int i = 1; i < m; i++) dp[i][0] = dp[i-1][0] + grid[i][0];
    
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[m-1][n-1];
}
```

**Time:** O(m*n) | **Space:** O(m*n) or O(n) optimized

**Problems:**
- ✅ [Unique Paths](../dp/uniquePaths.cpp) 🔥
- ✅ [Unique Paths 2](../dp/uniquePaths2.cpp)
- ✅ [Minimum Path Sum](../dp/minPathSum.cpp)
- ✅ [Triangle](../dp/triangle.cpp)
- ✅ [Max Path Sum](../dp/maxPathSum.cpp)
- ✅ [Cherry Pickup 2](../dp/cherryPickup2.cpp)

---

## Pattern 7: Stock Problems (State Machine)

**When to use:**
- Buy/sell with constraints
- State: holding stock or not
- Keywords: "stock", "buy and sell", "cooldown", "transaction fee"

**Template (Unlimited Transactions):**
```cpp
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    // dp[i][0] = max profit on day i with no stock
    // dp[i][1] = max profit on day i with stock
    vector<vector<int>> dp(n, vector<int>(2));
    dp[0][0] = 0;
    dp[0][1] = -prices[0];
    
    for (int i = 1; i < n; i++) {
        dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);  // Rest or sell
        dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i]);  // Rest or buy
    }
    return dp[n-1][0];
}

// Space optimized
int maxProfit(vector<int>& prices) {
    int hold = -prices[0], notHold = 0;
    for (int i = 1; i < prices.size(); i++) {
        int newHold = max(hold, notHold - prices[i]);
        notHold = max(notHold, hold + prices[i]);
        hold = newHold;
    }
    return notHold;
}
```

**Template (With Cooldown):**
```cpp
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    // dp[i][0] = max profit on day i, can buy (no stock, cooldown over)
    // dp[i][1] = max profit on day i, holding stock
    // dp[i][2] = max profit on day i, cooldown (just sold)
    vector<vector<int>> dp(n, vector<int>(3));
    dp[0][1] = -prices[0];
    
    for (int i = 1; i < n; i++) {
        dp[i][0] = max(dp[i-1][0], dp[i-1][2]);           // Rest or cooldown ends
        dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i]);  // Rest or buy
        dp[i][2] = dp[i-1][1] + prices[i];                // Sell
    }
    return max(dp[n-1][0], dp[n-1][2]);
}
```

**Time:** O(n) | **Space:** O(1) optimized

**Problems:**
- ✅ [Best Time to Buy and Sell Stock](../dp/buy-sell-stocks/bestTime.cpp) 🔥
- ✅ [Best Time 2](../dp/buy-sell-stocks/bestTime2.cpp)
- ✅ [Best Time 3](../dp/buy-sell-stocks/bestTime3.cpp)
- ✅ [Best Time with Cooldown](../dp/buy-sell-stocks/bestTimeWithCooldown.cpp)

---

## Pattern 8: House Robber

**When to use:**
- Can't pick adjacent elements
- Maximize sum with constraint
- Keywords: "non-adjacent", "robber", "can't pick consecutive"

**Template:**
```cpp
int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return nums[0];
    
    vector<int> dp(n);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    
    for (int i = 2; i < n; i++) {
        dp[i] = max(
            nums[i] + dp[i-2],  // Rob current house
            dp[i-1]             // Skip current house
        );
    }
    return dp[n-1];
}

// Space optimized
int rob(vector<int>& nums) {
    int prev2 = 0, prev1 = 0;
    for (int num : nums) {
        int curr = max(prev1, prev2 + num);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

// House Robber II (Circular - first and last are adjacent)
int robCircular(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return nums[0];
    // Either rob [0...n-2] or [1...n-1]
    return max(rob(nums, 0, n-2), rob(nums, 1, n-1));
}
```

**Time:** O(n) | **Space:** O(1)

**Problems:**
- ✅ [House Robber](../dp/sticklerThief.cpp) 🔥
- ⬜ [House Robber II](https://leetcode.com/problems/house-robber-ii/)

---

## DP Pattern Recognition

| Pattern | Key Indicator | Recurrence |
|---------|---------------|------------|
| 0/1 Knapsack | Each item once, weight constraint | `max(take, skip)` |
| Unbounded Knapsack | Unlimited items | Forward iteration |
| LCS | Two strings, common pattern | Match: `1 + dp[i-1][j-1]`  |
| LIS | Increasing subsequence | `max(dp[j] + 1)` for all j < i |
| MCM | Partition problem | Try all `k` between `i` and `j` |
| Grid DP | 2D paths | `dp[i][j] = f(dp[i-1][j], dp[i][j-1])` |
| State Machine | Multiple states | DP with state dimensions |
| House Robber | Non-adjacent | `max(curr + dp[i-2], dp[i-1])` |

---

## Revision Clusters (Solve Together)

**0/1 Knapsack Family** (45 mins):
1. [0-1knapsack.cpp](../dp/0-1knapsack.cpp)
2. [subsetSumEqK.cpp](../dp/subsetSumEqK.cpp)
3. [minSumPartition.cpp](../dp/minSumPartition.cpp)

**LCS Family** (2 hrs):
1. [lcs.cpp](../dp/lcs.cpp) → [editDistance.cpp](../dp/editDistance.cpp) → [scs.cpp](../dp/scs.cpp)

**Grid DP** (1 hr):
1. [uniquePaths.cpp](../dp/uniquePaths.cpp) → [minPathSum.cpp](../dp/minPathSum.cpp)

---

**Next Steps:**
1. Use this map for revision (pattern-by-pattern)
2. Speed code templates: Knapsack, LCS, LIS in < 20 mins
3. Solve 2 remaining (Decode Ways, House Robber II)
