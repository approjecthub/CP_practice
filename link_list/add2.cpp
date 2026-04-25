// https://leetcode.com/problems/add-two-numbers-ii/description/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
 class Solution {
    public:
        int getLength(ListNode* head) {
            int len = 0;
            while (head) {
                len++;
                head = head->next;
            }
            return len;
        }
    
        ListNode* addHelper(ListNode* l1, ListNode* l2, int& carry) {
            if (!l1 && !l2)
                return nullptr;
    
            // Recurse first (go to the end)
            ListNode* next = addHelper(l1->next, l2->next, carry);
    
            // Process current nodes on the way back
            int sum = l1->val + l2->val + carry;
            carry = sum / 10;
    
            ListNode* curr = new ListNode(sum % 10);
            curr->next = next;
            return curr;
        }
    
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            int len1 = getLength(l1);
            int len2 = getLength(l2);
    
            // Pad the shorter list
            if (len1 < len2) {
                for (int i = 0; i < len2 - len1; i++) {
                    ListNode* temp = new ListNode(0);
                    temp->next = l1;
                    l1 = temp;
                }
            } else if (len2 < len1) {
                for (int i = 0; i < len1 - len2; i++) {
                    ListNode* temp = new ListNode(0);
                    temp->next = l2;
                    l2 = temp;
                }
            }
    
            int carry = 0;
            ListNode* result = addHelper(l1, l2, carry);
    
            if (carry > 0) {
                ListNode* newHead = new ListNode(carry);
                newHead->next = result;
                result = newHead;
            }
    
            return result;
        }
    };