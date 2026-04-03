# Bit Manipulation Patterns

✅ **NEARLY COMPLETE** - You have 6/7 problems solved (86%). Only Reverse Integer remaining.

---

## Shift Operators Quick Reference

**Left Shift (`<<`)** - Shifts bits LEFT, fills right with 0s → **Multiplies by 2^n**
```cpp
5 << 1 = 10    // 0101 → 1010  (5 * 2¹)
5 << 2 = 20    // 0101 → 10100 (5 * 2²)
1 << i = 2^i   // Create power of 2
```

**Right Shift (`>>`)** - Shifts bits RIGHT, discards rightmost → **Divides by 2^n**
```cpp
20 >> 1 = 10   // 10100 → 1010 (20 / 2¹)
20 >> 2 = 5    // 10100 → 0101 (20 / 2²)
n >> i & 1     // Check if i-th bit is set
```

**Memory trick:** Arrow shows direction - `<<` grows (multiply), `>>` shrinks (divide)

---

## Essential Bit Operations

**1. Get bit at position i**
```cpp
(num >> i) & 1

// Example: num = 13 (binary: 1101), check bit at position 2
// 13 >> 2 = 3 (binary: 0011)
// 3 & 1 = 1 → bit is SET
```

**2. Set bit at position i**
```cpp
num | (1 << i)

// Example: num = 9 (binary: 1001), set bit at position 1
// 1 << 1 = 2 (binary: 0010)
// 9 | 2 = 11 (binary: 1011)
```

**3. Clear bit at position i**
```cpp
num & ~(1 << i)

// Example: num = 13 (binary: 1101), clear bit at position 2
// 1 << 2 = 4 (binary: 0100)
// ~4 = -5 (binary: ...11111011)
// 13 & ~4 = 9 (binary: 1001)
```

**4. Toggle bit at position i**
```cpp
num ^ (1 << i)

// Example: num = 13 (binary: 1101), toggle bit at position 1
// 1 << 1 = 2 (binary: 0010)
// 13 ^ 2 = 15 (binary: 1111)
```

**5. Check if power of 2**
```cpp
(num & (num - 1)) == 0 && num != 0

// Example 1: num = 8 (binary: 1000)
// 8 - 1 = 7 (binary: 0111)
// 8 & 7 = 0 → TRUE (power of 2)

// Example 2: num = 10 (binary: 1010)
// 10 - 1 = 9 (binary: 1001)
// 10 & 9 = 8 → FALSE (not power of 2)
```

**6. Count set bits (Brian Kernighan)**
```cpp
int count = 0;
while (num) {
    num &= (num - 1);  // Removes rightmost set bit
    count++;
}

// Example: num = 13 (binary: 1101)
// Iteration 1: 13 & 12 = 12 (1101 & 1100 = 1100), count = 1
// Iteration 2: 12 & 11 = 8  (1100 & 1011 = 1000), count = 2
// Iteration 3: 8 & 7 = 0    (1000 & 0111 = 0000), count = 3
// Result: 3 set bits
```

---

## Pattern 1: XOR Properties

**When to use:**
- Find unique/missing elements
- Pairs cancel out
- Keywords: "single number", "missing number", "appears twice"

**Key Properties:**
```
a ^ a = 0        (self-cancel)
a ^ 0 = a        (identity)
a ^ b ^ a = b    (commutative, associative)
```

**Template (Single Number):**
```cpp
int singleNumber(vector<int>& nums) {
    int result = 0;
    for (int num : nums) {
        result ^= num;  // All pairs cancel, only single remains
    }
    return result;
}
```

**Template (Missing Number):**
```cpp
int missingNumber(vector<int>& nums) {
    int result = nums.size();  // Start with n
    for (int i = 0; i < nums.size(); i++) {
        result ^= i ^ nums[i];  // XOR index with value
    }
    return result;  // Missing index remains
}

// Alternative: Mathematical approach
int missingNumber(vector<int>& nums) {
    int n = nums.size();
    int expected = n * (n + 1) / 2;  // Sum from 0 to n
    int actual = 0;
    for (int num : nums) actual += num;
    return expected - actual;
}
```

**Time:** O(n) | **Space:** O(1)

**Problems:**
- ✅ [Single Number](https://leetcode.com/problems/single-number/) 🔥 - [findSingleElement.cpp](../binary_search/findSingleElement.cpp)
- ✅ [Missing Number](https://leetcode.com/problems/missing-number/) - [missing_num.cpp](../bit_manipulation/missing_num.cpp)

---

## Pattern 2: Counting Bits (Brian Kernighan's Algorithm)

**When to use:**
- Count set bits (1s) in binary representation
- Keywords: "number of 1 bits", "hamming weight", "count bits"

**Brian Kernighan's Algorithm:**
```cpp
int hammingWeight(uint32_t n) {
    int count = 0;
    while (n) {
        n &= (n - 1);  // Removes the rightmost set bit
        count++;
    }
    return count;
}
// Time: O(k) where k = number of set bits (not O(32))
```

**Why it works:**
```
n     = 10110100
n-1   = 10110011
n&(n-1)= 10110000  (rightmost 1 removed)
```

**Template (Counting Bits 0 to n):**
```cpp
vector<int> countBits(int n) {
    vector<int> result(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        result[i] = result[i >> 1] + (i & 1);
        // i >> 1 is i/2 (drop last bit)
        // i & 1 is last bit (0 or 1)
        // So: bits[i] = bits[i/2] + lastBit
    }
    return result;
}
```

**Alternative DP approach:**
```cpp
result[i] = result[i & (i-1)] + 1;
// i & (i-1) removes rightmost set bit
// So count = count of that number + 1
```

**Time:** O(n) | **Space:** O(n)

**Problems:**
- ✅ [Number of 1 Bits](https://leetcode.com/problems/number-of-1-bits/) - [num_1_bits.cpp](../bit_manipulation/num_1_bits.cpp)
- ✅ [Counting Bits](https://leetcode.com/problems/counting-bits/) - [count_bits.cpp](../bit_manipulation/count_bits.cpp)

---

## Pattern 3: Power of 2 Check

**When to use:**
- Check if number is power of 2
- Single bit set check
- Keywords: "power of two", "single bit"

**Template:**
```cpp
bool isPowerOfTwo(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}
```

**Why it works:**
```
Powers of 2 have exactly one bit set:
1   = 00001
2   = 00010
4   = 00100
8   = 01000
16  = 10000

Any power of 2:
n     = 10000
n-1   = 01111
n&(n-1)= 00000  (result is 0)

Non-power of 2:
n     = 10100
n-1   = 10011
n&(n-1)= 10000  (result is not 0)
```

**Related: Get rightmost set bit:**
```cpp
int rightmostBit = n & (-n);
// -n in two's complement flips all bits and adds 1
// n    = 10110000
// -n   = 01010000
// n&-n = 00010000 (isolates rightmost set bit)
```

---

## Pattern 4: Bit Reversal

**When to use:**
- Reverse bits in integer
- Mirror binary representation
- Keywords: "reverse bits"

**Template (32-bit):**
```cpp
uint32_t reverseBits(uint32_t n) {
    uint32_t result = 0;
    for (int i = 0; i < 32; i++) {
        result <<= 1;           // Shift result left
        result |= (n & 1);      // Add rightmost bit of n
        n >>= 1;                // Shift n right
    }
    return result;
}
```

**Example (8-bit for clarity):**
```
Input: n = 13 (binary: 00001101)

Iteration 1: result = 0, n = 00001101
  result <<= 1 → result = 0
  result |= (13 & 1) = 1 → result = 1
  n >>= 1 → n = 0000110

Iteration 2: result = 1, n = 0000110
  result <<= 1 → result = 10
  result |= (6 & 1) = 0 → result = 10
  n >>= 1 → n = 000011

Iteration 3: result = 10, n = 000011
  result <<= 1 → result = 100
  result |= (3 & 1) = 1 → result = 101
  n >>= 1 → n = 00001

Iteration 4: result = 101, n = 00001
  result <<= 1 → result = 1010
  result |= (1 & 1) = 1 → result = 1011
  n >>= 1 → n = 0000

... (continue for 4 more iterations with n = 0)

Final: result = 10110000 = 176

Visual:
  00001101 → 10110000
  ^^^^^^^^    ^^^^^^^^
  Original    Reversed
```

**Optimized (Divide and Conquer):**
```cpp
uint32_t reverseBits(uint32_t n) {
    n = ((n & 0xFFFF0000) >> 16) | ((n & 0x0000FFFF) << 16);  // Swap 16-bit halves
    n = ((n & 0xFF00FF00) >> 8)  | ((n & 0x00FF00FF) << 8);   // Swap 8-bit chunks
    n = ((n & 0xF0F0F0F0) >> 4)  | ((n & 0x0F0F0F0F) << 4);   // Swap 4-bit chunks
    n = ((n & 0xCCCCCCCC) >> 2)  | ((n & 0x33333333) << 2);   // Swap 2-bit chunks
    n = ((n & 0xAAAAAAAA) >> 1)  | ((n & 0x55555555) << 1);   // Swap 1-bit chunks
    return n;
}
```

**Time:** O(32) = O(1) | **Space:** O(1)

**Problems:**
- ✅ [Reverse Bits](https://leetcode.com/problems/reverse-bits/) - [reverse_bits.cpp](../bit_manipulation/reverse_bits.cpp)
- ⬜ [Reverse Integer](https://leetcode.com/problems/reverse-integer/)

---

## Pattern 5: Bit Manipulation Arithmetic

**When to use:**
- Arithmetic without +, -, *, / operators
- Low-level operations
- Keywords: "without using", "bit operations only"

**Template (Addition):**
```cpp
int getSum(int a, int b) {
    while (b != 0) {
        unsigned carry = (unsigned)(a & b) << 1;  // Carry bits
        a = a ^ b;      // Sum without carry
        b = carry;      // Update b to carry
    }
    return a;
}
```

**How it works:**
```
Example: 5 + 3
  5 = 101
  3 = 011

First iteration:
  a ^ b     = 101 ^ 011 = 110 (sum without carry)
  (a & b)<<1 = (101 & 011)<<1 = 001<<1 = 010 (carry)

Second iteration:
  a = 110, b = 010
  a ^ b     = 110 ^ 010 = 100
  (a & b)<<1 = (110 & 010)<<1 = 010<<1 = 100

Third iteration:
  a = 100, b = 100
  a ^ b     = 000
  (a & b)<<1 = 1000

Fourth iteration:
  a = 1000, b = 0 → done
  Result: 1000 = 8
```

**Template (Multiplication by 2^k):**
```cpp
int multiply(int n, int k) {
    return n << k;  // Multiply by 2^k
}
```

**Template (Division by 2^k):**
```cpp
int divide(int n, int k) {
    return n >> k;  // Divide by 2^k
}
```

**Time:** O(32) = O(1) | **Space:** O(1)

**Problems:**
- ✅ [Sum of Two Integers](https://leetcode.com/problems/sum-of-two-integers/) - [sum.cpp](../bit_manipulation/sum.cpp)

---

## Pattern 6: Subset Generation Using Bits

**When to use:**
- Generate all subsets using bit masks
- Alternative to backtracking
- Keywords: "all subsets" (when array is small, n ≤ 20)

**Template:**
```cpp
vector<vector<int>> subsets(vector<int>& nums) {
    int n = nums.size();
    int totalSubsets = 1 << n;  // 2^n subsets
    vector<vector<int>> result;
    
    for (int mask = 0; mask < totalSubsets; mask++) {
        vector<int> subset;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {  // Check if i-th bit is set
                subset.push_back(nums[i]);
            }
        }
        result.push_back(subset);
    }
    return result;
}
```

**Example:** `nums = [1, 2, 3]`
```
mask = 000 → []
mask = 001 → [1]
mask = 010 → [2]
mask = 011 → [1, 2]
mask = 100 → [3]
mask = 101 → [1, 3]
mask = 110 → [2, 3]
mask = 111 → [1, 2, 3]
```

**Time:** O(n * 2^n) | **Space:** O(1) excluding output

---

## Bit Manipulation Cheat Sheet

| Operation | Code | Result |
|-----------|------|--------|
| Check if i-th bit set | `(n >> i) & 1` | 0 or 1 |
| Set i-th bit | `n \| (1 << i)` | n with bit set |
| Clear i-th bit | `n & ~(1 << i)` | n with bit cleared |
| Toggle i-th bit | `n ^ (1 << i)` | n with bit flipped |
| Remove rightmost 1 | `n & (n-1)` | n with rightmost 1 removed |
| Isolate rightmost 1 | `n & (-n)` | Only rightmost 1, rest 0 |
| Check power of 2 | `n > 0 && (n & (n-1)) == 0` | true/false |
| Multiply by 2^k | `n << k` | n * 2^k |
| Divide by 2^k | `n >> k` | n / 2^k |
| Get lowest k bits | `n & ((1 << k) - 1)` | Last k bits |
| Clear lowest k bits | `n & (~0 << k)` | Clear last k |

---

## Common Tricks

**1. Check if both same sign:**
```cpp
bool sameSign = (a ^ b) >= 0;
// If signs differ, XOR's MSB is 1 (negative)
```

**2. Swap two numbers without temp:**
```cpp
a ^= b;
b ^= a;
a ^= b;
```

**3. Min/Max without branching:**
```cpp
int min = b ^ ((a ^ b) & -(a < b));
int max = a ^ ((a ^ b) & -(a < b));
```

**4. Absolute value:**
```cpp
int abs(int n) {
    int mask = n >> 31;  // All 1s if negative, all 0s if positive
    return (n + mask) ^ mask;
}
```

---

## Problems to Solve (Priority Order)

1. ✅ [Number of 1 Bits](https://leetcode.com/problems/number-of-1-bits/) - Easy warm-up
2. ✅ [Counting Bits](https://leetcode.com/problems/counting-bits/) - DP + bits
3. ✅ [Missing Number](https://leetcode.com/problems/missing-number/) - XOR trick
4. ✅ [Reverse Bits](https://leetcode.com/problems/reverse-bits/) - Bit manipulation
5. ✅ [Sum of Two Integers](https://leetcode.com/problems/sum-of-two-integers/) - Arithmetic
6. ⬜ [Reverse Integer](https://leetcode.com/problems/reverse-integer/) - Integer operations
7. ✅ [Single Number](https://leetcode.com/problems/single-number/) 🔥 - Already solved

---

## Speed Drill (Week 2)

**Practice these in 30 mins total:**
1. Write Brian Kernighan's algorithm from memory (5 mins)
2. Write XOR-based missing number (5 mins)
3. Write bit reversal (5 mins)
4. Solve 3 easy problems without reference (15 mins)

**Memorize:**
- `n & (n-1)` removes rightmost 1
- `n & (-n)` isolates rightmost 1
- XOR properties: `a ^ a = 0`, `a ^ 0 = a`

---

**Next Steps:**
1. Memorize the cheat sheet (Week 2, Day 1)
2. Solve all 6 remaining problems (Week 2, Days 1-3)
3. These are quick wins - all problems are Easy/Medium
