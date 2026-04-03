# Linked List Patterns

**Status:** 7/11 problems solved (64%).

> 🆕 **MAANG Company Data:**
> - **Add Two Numbers** — Google 72, Amazon 74, Meta 57, Microsoft 59 — **4/5 MAANG, P0!**
> - Reorder List, Remove Nth Node, Find Duplicate Number — not asked recently at MAANG (P2/P3)

---

## Pattern 1: Fast & Slow Pointer (Floyd's Cycle Detection)

**When to use:**
- Detect cycle
- Find middle element
- Find cycle start
- Keywords: "cycle", "middle", "loop", "floyd"

**Template (Detect Cycle):**
```cpp
bool hasCycle(ListNode *head) {
    ListNode *slow = head, *fast = head;
    
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        
        if (slow == fast) return true;
    }
    return false;
}
```

**Template (Find Middle):**
```cpp
ListNode* findMiddle(ListNode* head) {
    ListNode *slow = head, *fast = head;
    
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;  // Middle node
}
```

**Template (Find Cycle Start):**
```cpp
ListNode *detectCycle(ListNode *head) {
    ListNode *slow = head, *fast = head;
    
    // Find meeting point
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) break;
    }
    
    if (!fast || !fast->next) return nullptr;  // No cycle
    
    // Find cycle start
    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}
```

**Time:** O(n) | **Space:** O(1)

**Problems:**
- ✅ [Linked List Cycle](../link_list/cycle.cpp) 🔥
- ✅ [Linked List Cycle II](../link_list/cycle2.cpp)
- ✅ [Find Middle](../link_list/middle.cpp)
- ⬜ [Find the Duplicate Number](https://leetcode.com/problems/find-the-duplicate-number/) - Use as array

---

## Pattern 2: Reversal

**When to use:**
- Reverse entire list or part of it
- Reverse in groups
- Keywords: "reverse", "backward"

**Template (Reverse Linked List):**
```cpp
ListNode* reverseList(ListNode* head) {
    ListNode *prev = nullptr, *curr = head;
    
    while (curr) {
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// Recursive
ListNode* reverseList(ListNode* head) {
    if (!head || !head->next) return head;
    
    ListNode* newHead = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;
    return newHead;
}
```

**Template (Reverse in K-Groups):**
```cpp
ListNode* reverseKGroup(ListNode* head, int k) {
    // Count nodes
    ListNode* curr = head;
    int count = 0;
    while (curr && count < k) {
        curr = curr->next;
        count++;
    }
    
    if (count < k) return head;  // Not enough nodes
    
    // Reverse first k nodes
    ListNode *prev = nullptr, *current = head;
    for (int i = 0; i < k; i++) {
        ListNode* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    
    // Recursively reverse rest
    head->next = reverseKGroup(current, k);
    return prev;
}
```

**Time:** O(n) | **Space:** O(1) iterative, O(n/k) recursive

**Problems:**
- ✅ [Reverse Linked List](../link_list/reverse.cpp) 🔥
- ✅ [Reverse in K-Groups](../link_list/k_reverse.cpp)

---

## Pattern 3: Merge

**When to use:**
- Combine sorted lists
- Merge multiple lists
- Keywords: "merge", "combine", "sorted"

**Template (Merge Two Sorted Lists):**
```cpp
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode dummy(0);
    ListNode* tail = &dummy;
    
    while (l1 && l2) {
        if (l1->val < l2->val) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    
    tail->next = l1 ? l1 : l2;
    return dummy.next;
}
```

**Template (Merge K Sorted Lists - Heap):**
```cpp
struct Compare {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;  // Min heap
    }
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<ListNode*, vector<ListNode*>, Compare> pq;
    
    // Add first node of each list
    for (ListNode* list : lists) {
        if (list) pq.push(list);
    }
    
    ListNode dummy(0);
    ListNode* tail = &dummy;
    
    while (!pq.empty()) {
        ListNode* node = pq.top(); pq.pop();
        tail->next = node;
        tail = tail->next;
        
        if (node->next) pq.push(node->next);
    }
    
    return dummy.next;
}
```

**Time:** O(n log k) for k lists | **Space:** O(k)

**Problems:**
- ✅ [Merge Two Sorted Lists](../link_list/merge 2 sorted LinkList.cpp) 🔥
- ✅ [Merge K Sorted Lists](../link_list/Merge k Sorted Lists.cpp) 🔥

---

## Pattern 4: Manipulation / Clone

**When to use:**
- Copy with random pointers
- Remove nodes
- Reorder list
- Keywords: "copy", "clone", "remove", "reorder"

**Template (Copy List with Random Pointer):**
```cpp
Node* copyRandomList(Node* head) {
    if (!head) return nullptr;
    
    unordered_map<Node*, Node*> map;
    
    // First pass: create nodes
    Node* curr = head;
    while (curr) {
        map[curr] = new Node(curr->val);
        curr = curr->next;
    }
    
    // Second pass: link next and random
    curr = head;
    while (curr) {
        map[curr]->next = map[curr->next];
        map[curr]->random = map[curr->random];
        curr = curr->next;
    }
    
    return map[head];
}

// Space-optimized (interweaving)
Node* copyRandomList(Node* head) {
    if (!head) return nullptr;
    
    // Step 1: Interweave original and copied nodes
    Node* curr = head;
    while (curr) {
        Node* copy = new Node(curr->val);
        copy->next = curr->next;
        curr->next = copy;
        curr = copy->next;
    }
    
    // Step 2: Copy random pointers
    curr = head;
    while (curr) {
        if (curr->random) {
            curr->next->random = curr->random->next;
        }
        curr = curr->next->next;
    }
    
    // Step 3: Separate lists
    Node* newHead = head->next;
    curr = head;
    while (curr) {
        Node* copy = curr->next;
        curr->next = copy->next;
        if (copy->next) copy->next = copy->next->next;
        curr = curr->next;
    }
    
    return newHead;
}
```

**Template (Remove Nth from End):**
```cpp
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode dummy(0);
    dummy.next = head;
    
    ListNode *fast = &dummy, *slow = &dummy;
    
    // Move fast n+1 steps ahead
    for (int i = 0; i <= n; i++) {
        fast = fast->next;
    }
    
    // Move both until fast reaches end
    while (fast) {
        fast = fast->next;
        slow = slow->next;
    }
    
    // Remove nth node
    slow->next = slow->next->next;
    return dummy.next;
}
```

**Time:** O(n) | **Space:** O(n) or O(1)

**Problems:**
- ✅ [Copy List with Random Pointer](../link_list/cloneList.cpp) 🔥
- ⬜ [Remove Nth Node From End](https://leetcode.com/problems/remove-nth-node-from-end-of-list/)
- ⬜ [Reorder List](https://leetcode.com/problems/reorder-list/)
- ⬜ [Add Two Numbers](https://leetcode.com/problems/add-two-numbers/)

---

## Pattern 5: Sort

**When to use:**
- Sort linked list
- Keywords: "sort"

**Template (Merge Sort for Linked List):**
```cpp
ListNode* sortList(ListNode* head) {
    if (!head || !head->next) return head;
    
    // Find middle
    ListNode *slow = head, *fast = head, *prev = nullptr;
    while (fast && fast->next) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    prev->next = nullptr;  // Split into two halves
    
    // Recursively sort both halves
    ListNode* l1 = sortList(head);
    ListNode* l2 = sortList(slow);
    
    // Merge
    return merge(l1, l2);
}
```

**Time:** O(n log n) | **Space:** O(log n) recursion

**Problems:**
- ✅ [Merge Sort Linked List](../link_list/MergeSortLinkList.cpp)

---

## Linked List Pattern Recognition

| Pattern | Key Indicator | Time | Space |
|---------|---------------|------|-------|
| Fast/Slow Pointer | Cycle, middle, distance | O(n) | O(1) |
| Reversal | Reverse list/groups | O(n) | O(1) |
| Merge | Combine sorted lists | O(n log k) | O(k) |
| Manipulation | Copy, remove, reorder | O(n) | O(n) or O(1) |
| Sort | Sort linked list | O(n log n) | O(log n) |

---

## Common Mistakes

1. **Not using dummy node:**
   ```cpp
   ListNode dummy(0);
   dummy.next = head;  // Simplifies edge cases
   ```

2. **Losing reference to head:**
   ```cpp
   // Save original head before manipulation
   ListNode* originalHead = head;
   ```

3. **Not checking for null:**
   ```cpp
   if (!head || !head->next) return head;
   ```

---

## Revision Cluster

**Pointer Manipulation** (45 mins):
1. [cycle.cpp](../link_list/cycle.cpp)
2. [middle.cpp](../link_list/middle.cpp)
3. [reverse.cpp](../link_list/reverse.cpp)

**Merge Problems** (30 mins):
1. [merge 2 sorted LinkList.cpp](../link_list/merge 2 sorted LinkList.cpp)
2. [Merge k Sorted Lists.cpp](../link_list/Merge k Sorted Lists.cpp)

---

**Speed Drill:**
- Code cycle detection in 5 mins
- Code reverse list in 3 mins
- Code merge two lists in 5 mins
