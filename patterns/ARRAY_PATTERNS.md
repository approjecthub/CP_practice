# Array Patterns

**Status:** 10/14 problems solved (71%). Quick wins available.

> 🆕 **MAANG Company Data — Key unsolved problems:**
> - **Valid Anagram** — Google 49, Amazon 48 → solve in 10 min
> - **Contains Duplicate** — Google 36 → solve in 5 min
> - **Valid Sudoku** — Amazon 53, Apple 57 → 20 min
> - **Encode/Decode Strings** — low frequency, P3

---

## Pattern 1: Two Pointer

**When to use:**
- Sorted array or need to sort
- Find pairs, triplets with target
- Keywords: "two sum", "3sum", "pair", "sorted"

**Template (Two Sum - Sorted):**
```cpp
vector<int> twoSum(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    
    while (left < right) {
        int sum = nums[left] + nums[right];
        if (sum == target) {
            return {left, right};
        } else if (sum < target) {
            left++;
        } else {
            right--;
        }
    }
    return {-1, -1};
}
```

**Template (3Sum):**
```cpp
vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());
    
    for (int i = 0; i < nums.size() - 2; i++) {
        if (i > 0 && nums[i] == nums[i-1]) continue;  // Skip duplicates
        
        int left = i + 1, right = nums.size() - 1;
        int target = -nums[i];
        
        while (left < right) {
            int sum = nums[left] + nums[right];
            if (sum == target) {
                result.push_back({nums[i], nums[left], nums[right]});
                while (left < right && nums[left] == nums[left+1]) left++;
                while (left < right && nums[right] == nums[right-1]) right--;
                left++; right--;
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }
    }
    return result;
}
```

**Template (Trapping Rain Water):**
```cpp
int trap(vector<int>& height) {
    int left = 0, right = height.size() - 1;
    int leftMax = 0, rightMax = 0;
    int water = 0;
    
    while (left < right) {
        if (height[left] < height[right]) {
            if (height[left] >= leftMax) {
                leftMax = height[left];
            } else {
                water += leftMax - height[left];
            }
            left++;
        } else {
            if (height[right] >= rightMax) {
                rightMax = height[right];
            } else {
                water += rightMax - height[right];
            }
            right--;
        }
    }
    return water;
}
```

**Time:** O(n) or O(n²) for 3sum | **Space:** O(1)

**Problems:**
- ✅ [Two Sum II / Pairs](../arrays/pairs.cpp)
- ✅ [3Sum](../arrays/3sum.cpp) 🔥
- ✅ [Trapping Rain Water](../arrays/trapping_water.cpp) 🔥
- ✅ [Min Absolute Difference](../arrays/min_abs_diff.cpp)
- ✅ [Container With Most Water](../greedy/containerWithMostWater.cpp) 🔥

---

## Pattern 2: Prefix Sum / Product

**When to use:**
- Subarray sum queries
- Cumulative operations
- Keywords: "subarray sum", "prefix", "cumulative"

**Template (Prefix Sum):**
```cpp
vector<int> prefixSum(vector<int>& nums) {
    int n = nums.size();
    vector<int> prefix(n);
    prefix[0] = nums[0];
    
    for (int i = 1; i < n; i++) {
        prefix[i] = prefix[i-1] + nums[i];
    }
    return prefix;
}

// Range sum query [l, r]
int rangeSum(vector<int>& prefix, int l, int r) {
    if (l == 0) return prefix[r];
    return prefix[r] - prefix[l-1];
}
```

**Template (Product of Array Except Self):**
```cpp
vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, 1);
    
    // Left products
    int leftProduct = 1;
    for (int i = 0; i < n; i++) {
        result[i] = leftProduct;
        leftProduct *= nums[i];
    }
    
    // Right products
    int rightProduct = 1;
    for (int i = n - 1; i >= 0; i--) {
        result[i] *= rightProduct;
        rightProduct *= nums[i];
    }
    
    return result;
}
```

**Time:** O(n) | **Space:** O(1) excluding output

**Problems:**
- ✅ [Product of Array Except Self](../arrays/Product of Array Except Self.cpp) 🔥
- ✅ [Subarray Sum Equals K](../sliding window/Subarray Sum Equals K.cpp)
- ✅ [Maximum Subarray Sum](../arrays/maximum_subarray_sum.cpp)

---

## Pattern 3: Kadane's Algorithm

**When to use:**
- Maximum subarray sum
- Max product subarray
- Keywords: "maximum subarray", "contiguous"

**Template:**
```cpp
int maxSubArray(vector<int>& nums) {
    int maxSum = nums[0];
    int currentSum = nums[0];
    
    for (int i = 1; i < nums.size(); i++) {
        currentSum = max(nums[i], currentSum + nums[i]);  // Start new or continue
        maxSum = max(maxSum, currentSum);
    }
    return maxSum;
}

// Maximum Product Subarray
int maxProduct(vector<int>& nums) {
    int maxProd = nums[0];
    int currentMax = nums[0], currentMin = nums[0];
    
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] < 0) {
            swap(currentMax, currentMin);  // Negative flips max/min
        }
        
        currentMax = max(nums[i], currentMax * nums[i]);
        currentMin = min(nums[i], currentMin * nums[i]);
        maxProd = max(maxProd, currentMax);
    }
    return maxProd;
}
```

**Time:** O(n) | **Space:** O(1)

**Problems:**
- ✅ [Maximum Subarray Sum](../arrays/maximum_subarray_sum.cpp) 🔥
- ✅ [Maximum Product Subarray](../blind75/problem6.cpp) 🔥

---

## Pattern 4: HashMap for Counting / Frequency

**When to use:**
- Count occurrences
- Find patterns with specific count
- Keywords: "count", "frequency", "appears"

**Template (Longest Consecutive Sequence):**
```cpp
int longestConsecutive(vector<int>& nums) {
    unordered_set<int> numSet(nums.begin(), nums.end());
    int maxLen = 0;
    
    for (int num : numSet) {
        if (!numSet.count(num - 1)) {  // Start of sequence
            int currentNum = num;
            int currentLen = 1;
            
            while (numSet.count(currentNum + 1)) {
                currentNum++;
                currentLen++;
            }
            maxLen = max(maxLen, currentLen);
        }
    }
    return maxLen;
}
```

**Time:** O(n) | **Space:** O(n)

**Problems:**
- ✅ [Longest Consecutive Sequence](../arrays/longest_band.cpp) 🔥
- ⬜ [Contains Duplicate](https://leetcode.com/problems/contains-duplicate/)
- ⬜ [Valid Anagram](https://leetcode.com/problems/valid-anagram/)

---

## Pattern 5: Sorting-Based

**When to use:**
- Need to compare neighbors
- Find duplicates/patterns
- Keywords: "sort", "minimum swaps"

**Template (Sort Colors - Dutch National Flag):**
```cpp
void sortColors(vector<int>& nums) {
    int low = 0, mid = 0, high = nums.size() - 1;
    
    while (mid <= high) {
        if (nums[mid] == 0) {
            swap(nums[low++], nums[mid++]);
        } else if (nums[mid] == 1) {
            mid++;
        } else {
            swap(nums[mid], nums[high--]);
        }
    }
}
```

**Time:** O(n) | **Space:** O(1)

**Problems:**
- ✅ [Sort 0, 1, 2](../sorting/sort012.cpp)
- ✅ [Minimum Swaps](../arrays/minimum_swaps.cpp)

---

## Array Pattern Recognition

| Pattern | Key Indicator | Time | Space |
|---------|---------------|------|-------|
| Two Pointer | Sorted, pairs, target | O(n) or O(n²) | O(1) |
| Prefix Sum/Product | Subarray queries, cumulative | O(n) | O(n) |
| Kadane's | Max subarray sum/product | O(n) | O(1) |
| HashMap | Count, frequency, exists | O(n) | O(n) |
| Sorting | Compare neighbors, patterns | O(n log n) | O(1) |

---

## Quick Wins (Easy Problems)

1. ⬜ [Contains Duplicate](https://leetcode.com/problems/contains-duplicate/)
2. ⬜ [Valid Anagram](https://leetcode.com/problems/valid-anagram/)
3. ⬜ [Valid Sudoku](https://leetcode.com/problems/valid-sudoku/)

---

**Speed Drill:**
- Code two sum (sorted) in 3 mins
- Code Kadane's algorithm in 3 mins
- Code product except self in 5 mins
