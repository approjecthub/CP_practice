# Math & Geometry Patterns

⚠️ **CRITICAL GAP** - You have 1/8 problems solved (13%). Build from scratch.

> 🆕 **MAANG Company Data (3-month frequency):**
> - **Rotate Image** — Google 47, Amazon 57, Microsoft 59, Apple 48 — **4/5 MAANG!**
> - **Spiral Matrix** — Google 44, Amazon 53, Microsoft 41, Apple 48 — **4/5 MAANG!**
> - **Pow(x,n)** — Google 47, Amazon 42, **Meta 78**, Microsoft 47 — **4/5 MAANG!**
> - **Happy Number** — Google 44, Microsoft 52, Apple 48
> - **Plus One** — Google 46, Amazon 42
> - **Reverse Integer** — Google 41, Amazon 55, Microsoft 56, Apple 48
> - **Set Matrix Zeroes** — Microsoft 47
>
> **These are NOT obscure problems — they appear at almost every MAANG company. Solve all 7 unsolved.**

---

## Pattern 1: Matrix Rotation & Manipulation

**When to use:**
- Rotate matrix 90°/180°/270°
- Transform 2D array
- Keywords: "rotate", "spiral", "matrix"

**Template (Rotate 90° Clockwise):**
```cpp
void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    
    // Step 1: Transpose (swap across diagonal)
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    
    // Step 2: Reverse each row
    for (int i = 0; i < n; i++) {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

// Rotate 90° Counter-clockwise: Transpose + Reverse each column
void rotateCounterClockwise(vector<vector<int>>& matrix) {
    int n = matrix.size();
    
    // Transpose
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    
    // Reverse each column
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n / 2; i++) {
            swap(matrix[i][j], matrix[n - 1 - i][j]);
        }
    }
}
```

**Template (Spiral Matrix):**
```cpp
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> result;
    if (matrix.empty()) return result;
    
    int top = 0, bottom = matrix.size() - 1;
    int left = 0, right = matrix[0].size() - 1;
    
    while (top <= bottom && left <= right) {
        // Right
        for (int j = left; j <= right; j++) {
            result.push_back(matrix[top][j]);
        }
        top++;
        
        // Down
        for (int i = top; i <= bottom; i++) {
            result.push_back(matrix[i][right]);
        }
        right--;
        
        // Left (check if row still exists)
        if (top <= bottom) {
            for (int j = right; j >= left; j--) {
                result.push_back(matrix[bottom][j]);
            }
            bottom--;
        }
        
        // Up (check if column still exists)
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                result.push_back(matrix[i][left]);
            }
            left++;
        }
    }
    
    return result;
}
```

**Template (Set Matrix Zeroes - In-place):**
```cpp
void setZeroes(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    bool firstRowZero = false, firstColZero = false;
    
    // Check if first row/col should be zero
    for (int j = 0; j < n; j++) {
        if (matrix[0][j] == 0) firstRowZero = true;
    }
    for (int i = 0; i < m; i++) {
        if (matrix[i][0] == 0) firstColZero = true;
    }
    
    // Use first row/col as markers
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }
    
    // Set zeros based on markers
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }
    
    // Set first row/col if needed
    if (firstRowZero) {
        for (int j = 0; j < n; j++) matrix[0][j] = 0;
    }
    if (firstColZero) {
        for (int i = 0; i < m; i++) matrix[i][0] = 0;
    }
}
```

**Time:** O(m*n) | **Space:** O(1)

**Problems:**
- ⬜ [Rotate Image](https://leetcode.com/problems/rotate-image/) 🔥
- ⬜ [Spiral Matrix](https://leetcode.com/problems/spiral-matrix/) 🔥
- ⬜ [Set Matrix Zeroes](https://leetcode.com/problems/set-matrix-zeroes/)
- ✅ [Spiral Matrix II](../arrays/Spiral_Matrix_II.cpp)

---

## Pattern 2: Number Simulation

**When to use:**
- Digit manipulation
- Cycle detection
- Keywords: "happy number", "plus one", "simulation"

**Template (Happy Number):**
```cpp
int getNext(int n) {
    int sum = 0;
    while (n > 0) {
        int digit = n % 10;
        sum += digit * digit;
        n /= 10;
    }
    return sum;
}

bool isHappy(int n) {
    unordered_set<int> seen;
    
    while (n != 1 && !seen.count(n)) {
        seen.insert(n);
        n = getNext(n);
    }
    
    return n == 1;
}

// Alternative: Floyd's Cycle Detection
bool isHappy(int n) {
    int slow = n, fast = n;
    
    do {
        slow = getNext(slow);
        fast = getNext(getNext(fast));
    } while (slow != fast);
    
    return slow == 1;
}
```

**Template (Plus One):**
```cpp
vector<int> plusOne(vector<int>& digits) {
    int n = digits.size();
    
    for (int i = n - 1; i >= 0; i--) {
        if (digits[i] < 9) {
            digits[i]++;
            return digits;
        }
        digits[i] = 0;
    }
    
    // All 9s, need extra digit
    digits.insert(digits.begin(), 1);
    return digits;
}
```

**Time:** O(n) or O(log n) | **Space:** O(1) or O(log n)

**Problems:**
- ⬜ [Happy Number](https://leetcode.com/problems/happy-number/)
- ⬜ [Plus One](https://leetcode.com/problems/plus-one/)
- ⬜ [Reverse Integer](https://leetcode.com/problems/reverse-integer/)

---

## Pattern 3: Fast Exponentiation

**When to use:**
- Calculate x^n efficiently
- Large exponentials
- Keywords: "power", "exponent"

**Template (Binary Exponentiation):**
```cpp
double myPow(double x, int n) {
    if (n == 0) return 1.0;
    
    long long N = n;  // Handle INT_MIN
    if (N < 0) {
        x = 1 / x;
        N = -N;
    }
    
    double result = 1.0;
    double current = x;
    
    while (N > 0) {
        if (N % 2 == 1) {  // Odd power
            result *= current;
        }
        current *= current;  // Square the base
        N /= 2;
    }
    
    return result;
}

// Recursive version
double myPow(double x, long long n) {
    if (n == 0) return 1.0;
    if (n < 0) return myPow(1/x, -n);
    
    if (n % 2 == 0) {
        double half = myPow(x, n / 2);
        return half * half;
    } else {
        return x * myPow(x, n - 1);
    }
}
```

**Time:** O(log n) | **Space:** O(1) iterative, O(log n) recursive

**Problems:**
- ⬜ [Pow(x, n)](https://leetcode.com/problems/powx-n/)

---

## Pattern 4: String Math (Large Numbers)

**When to use:**
- Numbers too large for int/long
- Add/multiply strings
- Keywords: "multiply strings", "add strings"

**Template (Multiply Strings):**
```cpp
string multiply(string num1, string num2) {
    if (num1 == "0" || num2 == "0") return "0";
    
    int m = num1.size(), n = num2.size();
    vector<int> result(m + n, 0);
    
    // Multiply digit by digit
    for (int i = m - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int p1 = i + j, p2 = i + j + 1;
            int sum = mul + result[p2];
            
            result[p2] = sum % 10;
            result[p1] += sum / 10;
        }
    }
    
    // Convert to string
    string str;
    for (int num : result) {
        if (!(str.empty() && num == 0)) {  // Skip leading zeros
            str += to_string(num);
        }
    }
    
    return str.empty() ? "0" : str;
}
```

**Template (Add Strings):**
```cpp
string addStrings(string num1, string num2) {
    string result;
    int i = num1.size() - 1, j = num2.size() - 1;
    int carry = 0;
    
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += num1[i--] - '0';
        if (j >= 0) sum += num2[j--] - '0';
        
        result += to_string(sum % 10);
        carry = sum / 10;
    }
    
    reverse(result.begin(), result.end());
    return result;
}
```

**Time:** O(m*n) for multiply, O(max(m,n)) for add | **Space:** O(m+n)

**Problems:**
- ⬜ [Multiply Strings](https://leetcode.com/problems/multiply-strings/)
- [Add Strings](https://leetcode.com/problems/add-strings/) - Not in checklist but good practice

---

## Pattern 5: GCD / LCM (Number Theory)

**When to use:**
- Greatest common divisor
- Least common multiple
- Keywords: "divisor", "multiple", "gcd"

**Template (GCD - Euclidean Algorithm):**
```cpp
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Recursive
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

// LCM
int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;  // Avoid overflow
}
```

**Time:** O(log(min(a,b))) | **Space:** O(1)

---

## Pattern 6: Coordinate Geometry

**When to use:**
- Distance calculations
- Detect shapes
- Keywords: "distance", "rectangle", "square", "detect"

**Template (Detect Squares):**
```cpp
class DetectSquares {
    unordered_map<int, unordered_map<int, int>> points;  // x -> {y -> count}
    
public:
    void add(vector<int> point) {
        points[point[0]][point[1]]++;
    }
    
    int count(vector<int> query) {
        int qx = query[0], qy = query[1];
        int result = 0;
        
        // For each point with same x-coordinate
        for (auto& [y, cnt1] : points[qx]) {
            if (y == qy) continue;  // Same point
            
            int sideLen = abs(y - qy);
            
            // Check for squares on both sides
            for (int dx : {-sideLen, sideLen}) {
                int x2 = qx + dx;
                if (points.count(x2)) {
                    auto& yMap = points[x2];
                    result += cnt1 * yMap[qy] * yMap[y];
                }
            }
        }
        
        return result;
    }
};
```

**Time:** O(n) per query | **Space:** O(n)

**Problems:**
- ✅ [Detect Squares](../hashing/countRectangles.cpp)

---

## Math Tricks Cheat Sheet

| Operation | Trick | Example |
|-----------|-------|---------|
| Check even/odd | `n & 1` | `5 & 1 = 1` (odd) |
| Divide by 2 | `n >> 1` | `10 >> 1 = 5` |
| Multiply by 2 | `n << 1` | `5 << 1 = 10` |
| Power of 2 | `(n & (n-1)) == 0` | `8 & 7 = 0` (true) |
| Absolute value | `abs(n) = (n ^ (n >> 31)) - (n >> 31)` | For bits |
| Swap without temp | `a ^= b; b ^= a; a ^= b;` | XOR swap |
| Sign check | `(a ^ b) < 0` | Different signs |
| Min without if | `b ^ ((a ^ b) & -(a < b))` | Branchless |
| Max without if | `a ^ ((a ^ b) & -(a < b))` | Branchless |

---

## Common Math Operations

```cpp
// Sum of 1 to n
int sum = n * (n + 1) / 2;

// Sum of squares 1² + 2² + ... + n²
int sumSq = n * (n + 1) * (2 * n + 1) / 6;

// Integer square root
int isqrt(int n) {
    if (n < 2) return n;
    int left = 1, right = n;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (mid == n / mid) return mid;
        if (mid < n / mid) left = mid + 1;
        else right = mid - 1;
    }
    return right;
}

// Check prime
bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}
```

---

## Problems to Solve (Week 3 Focus)

1. ⬜ [Rotate Image](https://leetcode.com/problems/rotate-image/) 🔥 - Day 1
2. ⬜ [Spiral Matrix](https://leetcode.com/problems/spiral-matrix/) 🔥 - Day 2
3. ⬜ [Set Matrix Zeroes](https://leetcode.com/problems/set-matrix-zeroes/) - Day 3
4. ⬜ [Happy Number](https://leetcode.com/problems/happy-number/) - Day 4 (easy)
5. ⬜ [Plus One](https://leetcode.com/problems/plus-one/) - Day 4 (easy)
6. ⬜ [Pow(x, n)](https://leetcode.com/problems/powx-n/) - Day 5
7. ⬜ [Multiply Strings](https://leetcode.com/problems/multiply-strings/) - Day 5

---

**Speed Drill (Week 3):**
- Rotate matrix 90° from memory (8 mins)
- Code spiral matrix from memory (12 mins)
- Code binary exponentiation (5 mins)
- Memorize all tricks in cheat sheet (10 mins)

**These are all solvable in Week 3 - don't skip this category!**
