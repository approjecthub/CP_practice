// https://www.geeksforgeeks.org/how-to-determine-if-a-binary-tree-is-balanced/
/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

class Solution{
    public:
    //Function to check whether a binary tree is balanced or not.
    int solve(Node *root){
        if(root==NULL){
            return true;
        }
        int lh = solve(root->left);
        int rh = solve(root->right);
        
        if(abs(lh-rh)>1 || lh==-1 || rh==-1){
            return -1;
        }
        else{
            return 1+max(lh, rh);
        }
    }
    bool isBalanced(Node *root)
    {
        //  Your Code here
        if(root==NULL){
            return true;
        }
        
        return solve(root)>-1;
    }
};
