# Stack & Queue Patterns

**Status:** 4/7 problems solved (57%). Focus on design problems.

> 🆕 **MAANG Company Data — Stack is WORSE than it looks!**
> - **Minimum Remove to Make Valid Parentheses** — **Meta #1 problem (freq 100!)** — NOT in NeetCode 150!
> - **Basic Calculator II** — Meta 86, Microsoft 47, Apple 48 — NOT in NeetCode 150!
> - **Simplify Path** — Meta 76 — NOT in NeetCode 150!
> - **Evaluate Reverse Polish Notation** — Amazon 39 — In NeetCode 150, unsolved
> - **Generate Parentheses** — Google 52, Amazon 66 — In NeetCode 150, unsolved
>
> **Action:** Solve the 3 N150 problems + at least 2 beyond-N150 Stack problems (Min Remove + Basic Calc II)

---

## Pattern 1: Monotonic Stack

**When to use:**
- Find next/previous greater/smaller element
- Maintain increasing/decreasing order
- Keywords: "next greater", "next smaller", "histogram", "daily temperatures"

**Template (Next Greater Element):**
```cpp
vector<int> nextGreaterElement(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, -1);
    stack<int> st;  // Store indices
    
    for (int i = 0; i < n; i++) {
        while (!st.empty() && nums[st.top()] < nums[i]) {
            result[st.top()] = nums[i];
            st.pop();
        }
        st.push(i);
    }
    return result;
}

// Circular Array (Next Greater II)
vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, -1);
    stack<int> st;
    
    for (int i = 0; i < 2 * n; i++) {  // Traverse twice
        int idx = i % n;
        while (!st.empty() && nums[st.top()] < nums[idx]) {
            result[st.top()] = nums[idx];
            st.pop();
        }
        if (i < n) st.push(i);  // Only push first iteration
    }
    return result;
}
```

**Template (Largest Rectangle in Histogram):**
```cpp
int largestRectangleArea(vector<int>& heights) {
    stack<int> st;
    int maxArea = 0;
    int n = heights.size();
    
    for (int i = 0; i <= n; i++) {
        int h = (i == n) ? 0 : heights[i];
        
        while (!st.empty() && heights[st.top()] > h) {
            int height = heights[st.top()];
            st.pop();
            int width = st.empty() ? i : i - st.top() - 1;
            maxArea = max(maxArea, height * width);
        }
        st.push(i);
    }
    return maxArea;
}
```

**Time:** O(n) | **Space:** O(n)

**Problems:**
- ✅ [Next Greater Element II](../stack & queue/next-greater-element2.cpp)
- ✅ [Daily Temperatures](../stack & queue/daily_temp.cpp) 🔥
- ✅ [Largest Rectangle in Histogram](../stack & queue/largest-area-rectangle.cpp) 🔥
- ⬜ [Car Fleet](https://leetcode.com/problems/car-fleet/)

---

## Pattern 2: Design Problems (Stack/Queue with Extra Operation)

**When to use:**
- Stack/queue with O(1) additional operation
- Track min/max efficiently
- Keywords: "min stack", "max stack", "design"

**Template (Min Stack):**
```cpp
class MinStack {
    stack<int> st;
    stack<int> minSt;  // Keeps track of minimum
    
public:
    void push(int val) {
        st.push(val);
        if (minSt.empty() || val <= minSt.top()) {
            minSt.push(val);
        }
    }
    
    void pop() {
        if (st.top() == minSt.top()) {
            minSt.pop();
        }
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSt.top();
    }
};

// Alternative: Store (val, currentMin) pairs
class MinStack {
    stack<pair<int, int>> st;  // {value, min_so_far}
    
public:
    void push(int val) {
        int minVal = st.empty() ? val : min(val, st.top().second);
        st.push({val, minVal});
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};
```

**Template (Stock Span):**
```cpp
class StockSpanner {
    stack<pair<int, int>> st;  // {price, span}
    
public:
    int next(int price) {
        int span = 1;
        while (!st.empty() && st.top().first <= price) {
            span += st.top().second;
            st.pop();
        }
        st.push({price, span});
        return span;
    }
};
```

**Time:** O(1) per operation | **Space:** O(n)

**Problems:**
- ✅ [Min Stack](../stack & queue/min_stack.cpp)
- ✅ [Online Stock Span](../stack & queue/Online Stock Span.cpp)
- ✅ [Min Stack](../stack%20%26%20queue/min_stack.cpp) 🔥

---

## Pattern 3: Expression Parsing / Parentheses

**When to use:**
- Validate or parse expressions
- Match parentheses/brackets
- Keywords: "valid", "parentheses", "expression", "braces"

**Template (Valid Parentheses):**
```cpp
bool isValid(string s) {
    stack<char> st;
    unordered_map<char, char> pairs = {{')', '('}, {']', '['}, {'}', '{'}};
    
    for (char c : s) {
        if (pairs.count(c)) {  // Closing bracket
            if (st.empty() || st.top() != pairs[c]) return false;
            st.pop();
        } else {  // Opening bracket
            st.push(c);
        }
    }
    return st.empty();
}
```

**Template (Redundant Braces):**
```cpp
bool hasRedundantBraces(string s) {
    stack<char> st;
    
    for (char c : s) {
        if (c == ')') {
            bool hasOperator = false;
            while (!st.empty() && st.top() != '(') {
                char top = st.top();
                st.pop();
                if (top == '+' || top == '-' || top == '*' || top == '/') {
                    hasOperator = true;
                }
            }
            if (!st.empty()) st.pop();  // Pop '('
            
            if (!hasOperator) return true;  // Redundant
        } else {
            st.push(c);
        }
    }
    return false;
}
```

**Template (Generate Parentheses):**
```cpp
void generate(int open, int close, string current, vector<string>& result) {
    if (open == 0 && close == 0) {
        result.push_back(current);
        return;
    }
    
    if (open > 0) {
        generate(open - 1, close, current + '(', result);
    }
    if (close > open) {  // Can only add ')' if more open than close
        generate(open, close - 1, current + ')', result);
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> result;
    generate(n, n, "", result);
    return result;
}
```

**Time:** O(n) for validation, O(4^n / sqrt(n)) for generation | **Space:** O(n)

**Problems:**
- ✅ [Valid Parentheses](../strings/valid_parenthesis.cpp) 🔥
- ✅ [Redundant Braces](../stack & queue/redundant-braces.cpp)
- ⬜ [Generate Parentheses](https://leetcode.com/problems/generate-parentheses/)
- ⬜ [Evaluate Reverse Polish Notation](https://leetcode.com/problems/evaluate-reverse-polish-notation/)

---

## Pattern 4: Queue (Stream / Sliding Window Related)

**When to use:**
- Process stream of data
- First non-repeating character
- Keywords: "stream", "first", "queue"

**Template (First Non-Repeating in Stream):**
```cpp
class FirstNonRepeating {
    queue<char> q;
    unordered_map<char, int> freq;
    
public:
    char getFirst(char c) {
        freq[c]++;
        q.push(c);
        
        while (!q.empty() && freq[q.front()] > 1) {
            q.pop();
        }
        
        return q.empty() ? '#' : q.front();
    }
};
```

**Time:** O(1) per operation | **Space:** O(n)

**Problems:**
- ✅ [First Non-Repeating Character in Stream](../stack & queue/first_non_repeating_character.cpp)
- ✅ [1st Non-Repeating Ch In Stream](../stack & queue/1st-NonRepeatingCh-InStream.cpp)

---

## Pattern 5: Two Heaps (Median from Stream)

**When to use:**
- Maintain median dynamically
- Access both max and min efficiently
- Keywords: "median", "data stream", "running"

**Template:**
```cpp
class MedianFinder {
    priority_queue<int> maxHeap;  // Lower half (max at top)
    priority_queue<int, vector<int>, greater<int>> minHeap;  // Upper half (min at top)
    
public:
    void addNum(int num) {
        maxHeap.push(num);
        
        // Balance: maxHeap top <= minHeap top
        minHeap.push(maxHeap.top());
        maxHeap.pop();
        
        // Balance sizes: maxHeap size >= minHeap size
        if (maxHeap.size() < minHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if (maxHeap.size() > minHeap.size()) {
            return maxHeap.top();
        }
        return (maxHeap.top() + minHeap.top()) / 2.0;
    }
};
```

**Time:** O(log n) per add, O(1) for median | **Space:** O(n)

**Problems:**
- ✅ [Find Median from Data Stream](../stack & queue/Find Median from Data Stream.cpp) 🔥

---

## Stack/Queue Pattern Recognition

| Pattern | Structure | Key Indicator |
|---------|-----------|---------------|
| Monotonic Stack | Stack of indices | Next/previous greater/smaller |
| Design | Stack + extra DS | O(1) min/max operation |
| Expression | Stack | Parentheses, brackets matching |
| Queue | Queue + HashMap | Stream, FIFO, first occurrence |
| Two Heaps | Max heap + Min heap | Median, middle element |

---

## Common Mistakes

1. **Wrong monotonic stack direction:**
   ```cpp
   // For next greater, process left to right
   // For previous greater, process right to left
   ```

2. **Forgetting to handle edge in histogram:**
   ```cpp
   for (int i = 0; i <= n; i++) {  // Note: <= not <
       int h = (i == n) ? 0 : heights[i];  // Append 0 at end
   ```

3. **Not maintaining heap sizes:**
   ```cpp
   // maxHeap can be 1 larger, but not minHeap
   if (maxHeap.size() < minHeap.size()) {
       // Rebalance
   }
   ```

---

## Revision Cluster

**Monotonic Stack** (1 hr):
1. [next-greater-element2.cpp](../stack & queue/next-greater-element2.cpp)
2. [daily_temp.cpp](../stack & queue/daily_temp.cpp)
3. [largest-area-rectangle.cpp](../stack & queue/largest-area-rectangle.cpp)

---

**Speed Drill:**
- Code monotonic stack template in 5 mins
- Code Min Stack in 5 mins
- Solve next greater element in 10 mins
