# Backtracking Patterns

⚠️ **CRITICAL GAP** - You have 1/9 problems solved (11%). Master these 3 core templates first.

> 🆕 **MAANG Company Data (3-month frequency):**
> - **Letter Combinations of Phone Number** — asked at ALL 5 MAANG! (G:49, A:34, Me:16, Ms:47, Ap:48)
> - **Subsets** — Amazon 34, Meta 43, Microsoft 47
> - **Permutations** — Google 41, Microsoft 41, Apple 48
> - **Combination Sum** — Google 36, Microsoft 33
> - **Generate Parentheses** — Google 52, Amazon 66, Microsoft 41
> - **N-Queens** — Google 46, Microsoft 41
> - **Word Break II** (not in N150) — Amazon 66 — Backtracking+DP
>
> **Solve order:** Subsets → Permutations → Combination Sum → Letter Combinations → Generate Parentheses → N-Queens

---

## Pattern 1: Subsets (Powerset)

**When to use:**
- Generate all possible combinations of elements
- Include/exclude decisions
- Keywords: "all subsets", "powerset", "all combinations"

**Template (Recursive - Most Common):**
```cpp
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(nums, 0, current, result);
        return result;
    }
    
    void backtrack(vector<int>& nums, int start, vector<int>& current, vector<vector<int>>& result) {
        result.push_back(current);  // Add current subset
        
        for (int i = start; i < nums.size(); i++) {
            current.push_back(nums[i]);           // Include
            backtrack(nums, i + 1, current, result);  // Recurse
            current.pop_back();                   // Exclude (backtrack)
        }
    }
};
```

**Template (With Duplicates - Subsets II):**
```cpp
void backtrack(vector<int>& nums, int start, vector<int>& current, vector<vector<int>>& result) {
    result.push_back(current);
    
    for (int i = start; i < nums.size(); i++) {
        if (i > start && nums[i] == nums[i-1]) continue;  // Skip duplicates
        current.push_back(nums[i]);
        backtrack(nums, i + 1, current, result);
        current.pop_back();
    }
}
// Must sort nums first: sort(nums.begin(), nums.end());
```

**Time:** O(2^n) | **Space:** O(n) recursion depth

**Problems:**
- ✅ [Word Search](../graphs/wordBoggle.cpp) - Applied to matrix
- ⬜ [Subsets](https://leetcode.com/problems/subsets/) 🔥
- ⬜ [Subsets II](https://leetcode.com/problems/subsets-ii/)

---

## Pattern 2: Permutations

**When to use:**
- All arrangements of elements
- Order matters
- Keywords: "all permutations", "all arrangements", "reorder"

**Template (Swap Method - Most Efficient):**
```cpp
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        backtrack(nums, 0, result);
        return result;
    }
    
    void backtrack(vector<int>& nums, int start, vector<vector<int>>& result) {
        if (start == nums.size()) {
            result.push_back(nums);
            return;
        }
        
        for (int i = start; i < nums.size(); i++) {
            swap(nums[start], nums[i]);           // Choose
            backtrack(nums, start + 1, result);   // Explore
            swap(nums[start], nums[i]);           // Unchoose (backtrack)
        }
    }
};
```

**Template (Used Array Method - For Duplicates):**
```cpp
void backtrack(vector<int>& nums, vector<bool>& used, vector<int>& current, vector<vector<int>>& result) {
    if (current.size() == nums.size()) {
        result.push_back(current);
        return;
    }
    
    for (int i = 0; i < nums.size(); i++) {
        if (used[i]) continue;
        if (i > 0 && nums[i] == nums[i-1] && !used[i-1]) continue;  // Skip duplicate
        
        used[i] = true;
        current.push_back(nums[i]);
        backtrack(nums, used, current, result);
        current.pop_back();
        used[i] = false;
    }
}
```

**Time:** O(n!) | **Space:** O(n)

**Problems:**
- ⬜ [Permutations](https://leetcode.com/problems/permutations/) 🔥
- ⬜ [Letter Combinations of a Phone Number](https://leetcode.com/problems/letter-combinations-of-a-phone-number/)

---

## Pattern 3: Combination Sum

**When to use:**
- Select elements to reach a target
- Can reuse elements OR each element once
- Keywords: "combination sum", "target sum", "find combinations"

**Template (Unbounded - Can Reuse):**
```cpp
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(candidates, target, 0, current, result);
        return result;
    }
    
    void backtrack(vector<int>& candidates, int target, int start, 
                   vector<int>& current, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(current);
            return;
        }
        if (target < 0) return;
        
        for (int i = start; i < candidates.size(); i++) {
            current.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i, current, result);  // i not i+1 (reuse)
            current.pop_back();
        }
    }
};
```

**Template (Bounded - Each Once, With Duplicates):**
```cpp
void backtrack(vector<int>& candidates, int target, int start, 
               vector<int>& current, vector<vector<int>>& result) {
    if (target == 0) {
        result.push_back(current);
        return;
    }
    if (target < 0) return;
    
    for (int i = start; i < candidates.size(); i++) {
        if (i > start && candidates[i] == candidates[i-1]) continue;  // Skip duplicates
        current.push_back(candidates[i]);
        backtrack(candidates, target - candidates[i], i + 1, current, result);  // i+1 (no reuse)
        current.pop_back();
    }
}
// Must sort first
```

**Time:** O(2^n) worst case | **Space:** O(n)

**Problems:**
- ⬜ [Combination Sum](https://leetcode.com/problems/combination-sum/) 🔥
- ⬜ [Combination Sum II](https://leetcode.com/problems/combination-sum-ii/)

---

## Pattern 4: Palindrome Partitioning

**When to use:**
- Split string into valid parts
- Each part satisfies a condition
- Keywords: "partition", "split", "palindrome"

**Template:**
```cpp
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> current;
        backtrack(s, 0, current, result);
        return result;
    }
    
    void backtrack(string& s, int start, vector<string>& current, vector<vector<string>>& result) {
        if (start == s.size()) {
            result.push_back(current);
            return;
        }
        
        for (int end = start; end < s.size(); end++) {
            if (isPalindrome(s, start, end)) {
                current.push_back(s.substr(start, end - start + 1));
                backtrack(s, end + 1, current, result);
                current.pop_back();
            }
        }
    }
    
    bool isPalindrome(string& s, int left, int right) {
        while (left < right) {
            if (s[left++] != s[right--]) return false;
        }
        return true;
    }
};
```

**Time:** O(n * 2^n) | **Space:** O(n)

**Problems:**
- ⬜ [Palindrome Partitioning](https://leetcode.com/problems/palindrome-partitioning/)

---

## Pattern 5: N-Queens (Constraint-Based)

**When to use:**
- Place items with constraints
- Check validity at each step
- Keywords: "n-queens", "sudoku", "valid placement"

**Template:**
```cpp
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board(n, string(n, '.'));
        backtrack(board, 0, result);
        return result;
    }
    
    void backtrack(vector<string>& board, int row, vector<vector<string>>& result) {
        if (row == board.size()) {
            result.push_back(board);
            return;
        }
        
        for (int col = 0; col < board.size(); col++) {
            if (isValid(board, row, col)) {
                board[row][col] = 'Q';
                backtrack(board, row + 1, result);
                board[row][col] = '.';
            }
        }
    }
    
    bool isValid(vector<string>& board, int row, int col) {
        int n = board.size();
        
        // Check column
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q') return false;
        }
        
        // Check diagonal (top-left)
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') return false;
        }
        
        // Check diagonal (top-right)
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q') return false;
        }
        
        return true;
    }
};
```

**Time:** O(n!) | **Space:** O(n^2)

**Problems:**
- ⬜ [N-Queens](https://leetcode.com/problems/n-queens/) 🔥

---

## Quick Pattern Recognition

| Problem Type | Pattern | Key Indicator |
|--------------|---------|---------------|
| All subsets/combinations | Subset | "all possible", "powerset" |
| All arrangements | Permutation | "all permutations", order matters |
| Find combinations for target | Combination Sum | "target sum", "combination" |
| Split into valid parts | Partition | "partition", "split", each part valid |
| Place with constraints | N-Queens style | "valid placement", constraints |

---

## Backtracking Template Structure

**Standard 3-Step Pattern:**
```cpp
void backtrack(params, current_state, result) {
    // BASE CASE: Found valid solution
    if (reached_goal) {
        result.add(current_state);
        return;
    }
    
    // PRUNING: Invalid state
    if (invalid_state) return;
    
    // RECURSIVE CASE: Try all choices
    for (each choice) {
        make_choice(current_state);           // Modify state
        backtrack(params, current_state, result);  // Recurse
        undo_choice(current_state);           // Backtrack
    }
}
```

---

## Common Mistakes

1. **Forgetting to backtrack (undo choice)**
   ```cpp
   // WRONG
   current.push_back(num);
   backtrack(...);
   // Missing: current.pop_back();
   ```

2. **Not handling duplicates in sorted arrays**
   ```cpp
   // Add before recursion in for loop:
   if (i > start && nums[i] == nums[i-1]) continue;
   ```

3. **Wrong start index (reuse vs no reuse)**
   ```cpp
   backtrack(..., i, ...);     // Can reuse element i
   backtrack(..., i+1, ...);   // Cannot reuse, move to next
   ```

4. **Passing by value instead of reference**
   ```cpp
   // WRONG (too slow)
   void backtrack(vector<int> current, ...)
   
   // CORRECT
   void backtrack(vector<int>& current, ...)
   ```

---

## Speed Drill (Weekly: Code in < 15 mins total)

**Week 1 Practice:**
1. Code Subset template from memory (5 mins)
2. Code Permutation template from memory (5 mins)
3. Code Combination Sum template from memory (5 mins)

**Week 2 Master:**
- Solve 3 problems using each template without reference
- Target: Recognize pattern in 30 seconds, code in 20 mins

---

## Problems to Solve (Priority Order)

1. ⬜ [Subsets](https://leetcode.com/problems/subsets/) 🔥 - Must master first
2. ⬜ [Permutations](https://leetcode.com/problems/permutations/) 🔥 - Must master second
3. ⬜ [Combination Sum](https://leetcode.com/problems/combination-sum/) 🔥 - Must master third
4. ⬜ [Subsets II](https://leetcode.com/problems/subsets-ii/) - Handle duplicates
5. ⬜ [Combination Sum II](https://leetcode.com/problems/combination-sum-ii/) - Handle duplicates
6. ⬜ [Palindrome Partitioning](https://leetcode.com/problems/palindrome-partitioning/) - Validation check
7. ⬜ [Letter Combinations of a Phone Number](https://leetcode.com/problems/letter-combinations-of-a-phone-number/) - Simple mapping
8. ⬜ [N-Queens](https://leetcode.com/problems/n-queens/) 🔥 - Complex constraints
9. ✅ [Word Search](https://leetcode.com/problems/word-search/) 🔥 - Matrix backtracking (already solved)

---

**Next Steps:**
1. Code all 3 core templates from memory (Week 1, Day 1)
2. Solve Subsets + Permutations + Combination Sum (Week 1, Days 1-3)
3. Build muscle memory: Can you code these in 15 mins total?
