//https://leetcode.com/problems/merge-k-sorted-lists/

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
    class CustomCompare{
        public:
            bool operator()(ListNode* x1, ListNode* x2){
                if(x1 && x2){
                    return x1->val>x2->val;
                }
                else if(x1){
                    return true;
                }
                else{
                    return false;
                }
            }        
    };
class Solution {
public:

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, CustomCompare> pq;
        
        int n = lists.size();
        
        for(int i=0; i<n;i++){
            if(lists[i]!=NULL){
                pq.push(lists[i]);
            }
            
        }
        ListNode* temp = NULL;
        ListNode* ans = NULL;
        
        while(pq.size()>0){
            
            ListNode* node = pq.top();
            
            if(ans==NULL){
                temp = node;
                ans = temp;
            }
            else{
                temp->next = node;
                temp = temp->next;
            }
            pq.pop();
            if(node->next!=NULL){
               pq.push(node->next); 
            }
            
        }
        return ans;
        
    }
};
