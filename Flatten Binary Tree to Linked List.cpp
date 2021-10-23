//https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    pair<TreeNode* , TreeNode* > solve(TreeNode* root){
        if(root==NULL){
            return {NULL,NULL}; 
        }
        pair<TreeNode* , TreeNode* > ln = solve(root->left);
        pair<TreeNode* , TreeNode* > rn = solve(root->right);
        
        
        root->left = NULL;
        root->right = ln.first;
        if(ln.second!=NULL){
            ln.second->right = rn.first;
        }
        else if(ln.first!=NULL){
            ln.first->right = rn.first;
        }
        else{
            root->right = rn.first;
        }
        
        TreeNode *sn =NULL;
        if(rn.second){
            sn = rn.second;
        }
        else if(rn.first){
            sn = rn.first;
        }
        else if(ln.second){
            sn = ln.second;
        }
        else if(ln.first){
            sn = ln.first;
        }
        else{
            sn = root;
        }
        return {root, sn};
    }
    void flatten(TreeNode* root) {
         solve(root);
    }
};
