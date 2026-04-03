# Tree Patterns

✅ **STRENGTH AREA** - You have 12/15 problems solved (80%). Use for efficient revision.

---

## Pattern 1: DFS Traversal (Inorder, Preorder, Postorder)

**When to use:**
- Need specific traversal order
- Process nodes in particular sequence
- Keywords: "inorder", "preorder", "postorder", "traversal"

**Templates:**
```cpp
// Inorder (Left → Root → Right) [BST gives sorted]
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    process(root->val);  // Process root
    inorder(root->right);
}

// Preorder (Root → Left → Right) [Copy tree structure]
void preorder(TreeNode* root) {
    if (!root) return;
    process(root->val);  // Process root first
    preorder(root->left);
    preorder(root->right);
}

// Postorder (Left → Right → Root) [Delete tree, calculate subtree info]
void postorder(TreeNode* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    process(root->val);  // Process root last
}

// Iterative Inorder (using stack)
vector<int> inorderIterative(TreeNode* root) {
    vector<int> result;
    stack<TreeNode*> st;
    TreeNode* curr = root;
    
    while (curr || !st.empty()) {
        while (curr) {
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top(); st.pop();
        result.push_back(curr->val);
        curr = curr->right;
    }
    return result;
}
```

**Time:** O(n) | **Space:** O(h) where h = height

**Problems:**
- ✅ [Tree Traversals](../trees/treeTraversals.cpp)
- ✅ [Validate BST](../trees/BST/isBst.cpp) - Uses inorder
- ✅ [BST Inorder Successor](../trees/BST/inorderSucc.cpp)

---

## Pattern 2: BFS / Level Order Traversal

**When to use:**
- Process level by level
- Find depth, width, level-based properties
- Keywords: "level order", "bfs", "width", "right side view"

**Template:**
```cpp
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> result;
    if (!root) return result;
    
    queue<TreeNode*> q;
    q.push(root);
    
    while (!q.empty()) {
        int size = q.size();
        vector<int> level;
        
        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front(); q.pop();
            level.push_back(node->val);
            
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        result.push_back(level);
    }
    return result;
}

// Right Side View
vector<int> rightSideView(TreeNode* root) {
    vector<int> result;
    if (!root) return result;
    
    queue<TreeNode*> q;
    q.push(root);
    
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front(); q.pop();
            if (i == size - 1) result.push_back(node->val);  // Last node in level
            
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }
    return result;
}
```

**Time:** O(n) | **Space:** O(w) where w = max width

**Problems:**
- ✅ [Level Order Traversal](../trees/levelOrderTraversal.cpp) 🔥
- ✅ [Left View / Right View](../trees/leftView.cpp)
- ✅ [Print Nodes at Level K](../trees/PrintNodesAtLevel k.cpp)
- ✅ [Cousins in Binary Tree](../trees/cousins.cpp)
- ✅ [Populate Next Pointers](../trees/populateNxtPointer.cpp)
- ✅ [Minimum Depth](../trees/minDepth.cpp)

---

## Pattern 3: Tree Recursion (Height, Diameter, Balance)

**When to use:**
- Calculate property from subtrees
- Bottom-up computation
- Keywords: "height", "diameter", "balanced", "depth"

**Templates:**
```cpp
// Height / Max Depth
int maxDepth(TreeNode* root) {
    if (!root) return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

// Diameter (Longest path between any two nodes)
int diameter(TreeNode* root, int& maxDiam) {
    if (!root) return 0;
    
    int leftHeight = diameter(root->left, maxDiam);
    int rightHeight = diameter(root->right, maxDiam);
    
    maxDiam = max(maxDiam, leftHeight + rightHeight);  // Path through root
    return 1 + max(leftHeight, rightHeight);  // Return height
}

int diameterOfBinaryTree(TreeNode* root) {
    int maxDiam = 0;
    diameter(root, maxDiam);
    return maxDiam;
}

// Is Balanced
pair<bool, int> isBalancedHelper(TreeNode* root) {
    if (!root) return {true, 0};
    
    auto [leftBal, leftH] = isBalancedHelper(root->left);
    auto [rightBal, rightH] = isBalancedHelper(root->right);
    
    bool balanced = leftBal && rightBal && abs(leftH - rightH) <= 1;
    return {balanced, 1 + max(leftH, rightH)};
}

bool isBalanced(TreeNode* root) {
    return isBalancedHelper(root).first;
}
```

**Time:** O(n) | **Space:** O(h)

**Problems:**
- ✅ [Diameter](../trees/diameter.cpp) 🔥
- ✅ [Is Balanced](../trees/isbalanced.cpp)
- ✅ [Min Depth](../trees/minDepth.cpp)

---

## Pattern 4: BST Operations

**When to use:**
- Binary Search Tree specific
- Use BST property: left < root < right
- Keywords: "BST", "search", "validate", "kth smallest"

**Templates:**
```cpp
// Search in BST
TreeNode* searchBST(TreeNode* root, int val) {
    if (!root || root->val == val) return root;
    if (val < root->val) return searchBST(root->left, val);
    return searchBST(root->right, val);
}

// Validate BST
bool isValidBST(TreeNode* root, long minVal, long maxVal) {
    if (!root) return true;
    if (root->val <= minVal || root->val >= maxVal) return false;
    
    return isValidBST(root->left, minVal, root->val) &&
           isValidBST(root->right, root->val, maxVal);
}

bool isValidBST(TreeNode* root) {
    return isValidBST(root, LONG_MIN, LONG_MAX);
}

// Lowest Common Ancestor (BST)
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (p->val < root->val && q->val < root->val)
        return lowestCommonAncestor(root->left, p, q);
    else if (p->val > root->val && q->val > root->val)
        return lowestCommonAncestor(root->right, p, q);
    else
        return root;  // Split point
}

// Construct BST from Sorted Array
TreeNode* sortedArrayToBST(vector<int>& nums, int left, int right) {
    if (left > right) return nullptr;
    
    int mid = left + (right - left) / 2;
    TreeNode* root = new TreeNode(nums[mid]);
    root->left = sortedArrayToBST(nums, left, mid - 1);
    root->right = sortedArrayToBST(nums, mid + 1, right);
    return root;
}
```

**Time:** O(log n) average for search, O(n) for construction | **Space:** O(h)

**Problems:**
- ✅ [Search BST](../trees/BST/search.cpp)
- ✅ [Validate BST](../trees/BST/isBst.cpp) 🔥
- ✅ [LCA of BST](../trees/BST/lca.cpp) 🔥
- ✅ [Sorted Array to BST](../trees/BST/SortedArrayToBST.cpp)
- ✅ [Inorder Successor](../trees/BST/inorderSucc.cpp)
- ⬜ [Kth Smallest in BST](https://leetcode.com/problems/kth-smallest-element-in-a-bst/)

---

## Pattern 5: Tree DP (Bottom-up Computation)

**When to use:**
- Calculate max/min from choices at each node
- Choose to include/exclude nodes
- Keywords: "maximum sum", "non-adjacent", "rob"

**Template:**
```cpp
// Maximum Path Sum (any node to any node)
int maxPathSum(TreeNode* root, int& globalMax) {
    if (!root) return 0;
    
    int leftMax = max(0, maxPathSum(root->left, globalMax));  // Ignore negative
    int rightMax = max(0, maxPathSum(root->right, globalMax));
    
    globalMax = max(globalMax, root->val + leftMax + rightMax);  // Path through root
    return root->val + max(leftMax, rightMax);  // Path ending at root
}

int maxPathSum(TreeNode* root) {
    int globalMax = INT_MIN;
    maxPathSum(root, globalMax);
    return globalMax;
}

// House Robber III (Binary Tree)
pair<int, int> rob(TreeNode* root) {
    if (!root) return {0, 0};
    
    auto [leftRob, leftNotRob] = rob(root->left);
    auto [rightRob, rightNotRob] = rob(root->right);
    
    int robCurrent = root->val + leftNotRob + rightNotRob;
    int notRobCurrent = max(leftRob, leftNotRob) + max(rightRob, rightNotRob);
    
    return {robCurrent, notRobCurrent};
}

int rob(TreeNode* root) {
    auto [robRoot, notRobRoot] = rob(root);
    return max(robRoot, notRobRoot);
}
```

**Time:** O(n) | **Space:** O(h)

**Problems:**
- ✅ [Max Path Sum](../trees/maxSubsetSum.cpp) 🔥
- ✅ [Maximum Sum Non-Adjacent](../trees/MaximumSumBTNonAdjacent.cpp)

---

## Pattern 6: Parent Pointer / Distance Problems

**When to use:**
- Need to track parents or ancestors
- Find nodes at distance K
- Keywords: "parent", "distance", "ancestor"

**Template:**
```cpp
// All Nodes Distance K
void buildParentMap(TreeNode* root, TreeNode* parent, unordered_map<TreeNode*, TreeNode*>& parentMap) {
    if (!root) return;
    parentMap[root] = parent;
    buildParentMap(root->left, root, parentMap);
    buildParentMap(root->right, root, parentMap);
}

vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    unordered_map<TreeNode*, TreeNode*> parentMap;
    buildParentMap(root, nullptr, parentMap);
    
    queue<TreeNode*> q;
    unordered_set<TreeNode*> visited;
    q.push(target);
    visited.insert(target);
    int dist = 0;
    
    while (!q.empty()) {
        if (dist == k) break;
        int size = q.size();
        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front(); q.pop();
            
            // Go to left, right, and parent
            if (node->left && !visited.count(node->left)) {
                q.push(node->left);
                visited.insert(node->left);
            }
            if (node->right && !visited.count(node->right)) {
                q.push(node->right);
                visited.insert(node->right);
            }
            if (parentMap[node] && !visited.count(parentMap[node])) {
                q.push(parentMap[node]);
                visited.insert(parentMap[node]);
            }
        }
        dist++;
    }
    
    vector<int> result;
    while (!q.empty()) {
        result.push_back(q.front()->val);
        q.pop();
    }
    return result;
}
```

**Time:** O(n) | **Space:** O(n)

**Problems:**
- ✅ [Nodes at Distance K](../trees/atDistanceK.cpp)
- ✅ [Minimum Distance Between Nodes](../trees/minDistance.cpp)

---

## Tree Pattern Recognition

| Pattern | Key Indicator | Time | Space |
|---------|---------------|------|-------|
| DFS Traversal | Specific order needed | O(n) | O(h) |
| BFS | Level-by-level, width | O(n) | O(w) |
| Tree Recursion | Calculate from subtrees | O(n) | O(h) |
| BST Operations | Ordered tree, search | O(log n) | O(h) |
| Tree DP | Max/min choices | O(n) | O(h) |
| Parent Pointer | Distance, ancestors | O(n) | O(n) |

---

## Common Mistakes

1. **Not checking for null:**
   ```cpp
   if (!root) return base_case;  // Always check first!
   ```

2. **Confusing inorder/preorder construction:**
   - Preorder gives root first
   - Inorder gives left-root-right ordering

3. **Forgetting to handle negative values in path sum:**
   ```cpp
   leftMax = max(0, leftMax);  // Ignore negative paths
   ```

4. **Wrong base case in recursion:**
   ```cpp
   if (!root) return 0;  // For height
   if (!root) return INT_MAX;  // For minimum operations
   ```

---

## Revision Clusters

**BFS Problems** (1 hr):
- [levelOrderTraversal.cpp](../trees/levelOrderTraversal.cpp)
- [leftView.cpp](../trees/leftView.cpp)
- [populateNxtPointer.cpp](../trees/populateNxtPointer.cpp)

**BST Problems** (1 hr):
- [search.cpp](../trees/BST/search.cpp)
- [isBst.cpp](../trees/BST/isBst.cpp)
- [lca.cpp](../trees/BST/lca.cpp)

**Tree Recursion** (45 mins):
- [diameter.cpp](../trees/diameter.cpp)
- [isbalanced.cpp](../trees/isbalanced.cpp)
- [minDepth.cpp](../trees/minDepth.cpp)

---

**Speed Drill:**
- Code max depth in 2 mins
- Code level order in 5 mins
- Code validate BST in mins
