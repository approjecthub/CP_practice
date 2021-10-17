//https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void printLevelK(TreeNode* root, int k, vector<int> &ans){
        if(root==NULL){
            return ;
        }
        if(k==0){
            ans.push_back(root->val);
            return;
        }
        printLevelK(root->left, k-1, ans);
        printLevelK(root->right, k-1, ans);
    }
    int solve(TreeNode* root, TreeNode* target, int k, vector<int> &ans){
        if(root==NULL || k<0){
            return -1;
        }
        
        if(root==target){
            printLevelK(root, k, ans);
            return 0;
        }
        
        int dl = solve(root->left, target,k,ans);
        if(dl!=-1){
            if(dl+1 == k){
                ans.push_back(root->val);
            }
            else if(dl+1 < k){
                printLevelK(root->right, k-(dl+1)-1, ans);
            }
            else{
                return -1;
            }
            return dl+1;
        }
        else{
            int rl = solve(root->right, target,k,ans);
            if(rl!=-1){
                if(rl+1 == k){
                    ans.push_back(root->val);
                }
                else if(rl+1 < k){
                    printLevelK(root->left,  k-(rl+1)-1, ans);
                }
                else{
                    return -1;
                }
            }
            return rl==-1?-1:rl+1;
        }
        
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        solve(root, target, k, ans);
        return ans;
    }
};
