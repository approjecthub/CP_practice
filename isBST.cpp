//https://leetcode.com/problems/validate-binary-search-tree/

pair<TreeNode*,TreeNode*> solve(TreeNode* root){
        
        if (root==NULL){
            return {NULL,NULL};
        }
        
         pair<TreeNode*,TreeNode*> lt = solve(root->left);
         pair<TreeNode*,TreeNode*> rt = solve(root->right);
        
        if((root->left!=NULL && lt.first==NULL) || (root->right!=NULL && rt.first==NULL)){
            return {NULL,NULL};
        }
        
        if(lt.first!=NULL && rt.first!=NULL){
            if(lt.second->val<root->val && rt.first->val>root->val){
                return {lt.first, rt.second};
            }
            else{
                return {NULL,NULL};
            }
        }
        else if(lt.first!=NULL ){
            if(lt.second->val<root->val ){
                return {lt.first, root};
            }
            else{
                return {NULL,NULL};
            }
        }
        else if(rt.first!=NULL ){
            if(rt.first->val>root->val){
                return { root, rt.second};
            }
            else{
                return {NULL,NULL};
            }
        }
        else{
            return {root, root};
        }
    }

    bool isValidBST(TreeNode* root) {
        if (root==NULL){
            return true;
        }
        pair<TreeNode*,TreeNode*> p = solve(root);
        
        if(p.first!=NULL){
            return true;
        }
        else{
            return false;
        }
    }
